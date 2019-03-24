#include "ast_spec_nodes.hpp"


//declaration

declarator::declarator(NodePtr direct, NodePtr pointer): directDeclarator(direct), pointerPtr(pointer) {}
declarator::declarator(NodePtr direct): directDeclarator(direct) {}


void declaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(specifier_list != NULL){specifier_list->printMips(ctx, stream);}
    if(declarator_list != NULL){declarator_list->printMips(ctx, stream);}
    ctx.tempDeclarator.purge();
}


//declaration_specifiers

declaration_specifiers::declaration_specifiers(std::string s): type_name(s) {}

void declaration_specifiers::printMips(compilerContext& ctx, std::ostream& stream){
    if(type_name == "int"){
        ctx.tempDeclarator.size = 4; //size in bytes
    }
}


//init_declarator

init_declarator::init_declarator(NodePtr declarator, NodePtr initial): declaratorPtr(declarator), initialiserPtr(initial) {}
init_declarator::init_declarator(NodePtr declarator): declaratorPtr(declarator) {}

void init_declarator::printMips(compilerContext& ctx, std::ostream& stream){
    //need to do something different for arrays
    if(ctx.functions.size() == 0){ //global vars
        if(!ctx.globalDefs){
            ctx.globalDefs = true;
            stream << "\t.data" << std::endl;
        }
        if(declaratorPtr != NULL){declaratorPtr->printMips(ctx, stream);}
        if(!ctx.tempDeclarator.id.empty()){
            ctx.globalVars[ctx.tempDeclarator.id] = varData(0, ctx.tempDeclarator.elements, ctx.tempDeclarator.size, true, false);//add global flag
        }
        if(initialiserPtr != NULL){
            initialiserPtr->printMips(ctx, stream);   
        }
        stream << std::endl;
    }else{
        ctx.tempDeclarator.offset = ctx.functions.back().memUsed + 4; //setting the offset
        if(declaratorPtr != NULL){declaratorPtr->printMips(ctx, stream);}
        if(ctx.tempDeclarator.isArray){
            ctx.addToStack(4, stream);
            stream << "addi $8, $sp, "<< -(ctx.tempDeclarator.totSize()) << std::endl;
            stream << "sw $8, 0($sp)" << std::endl;
        }
        ctx.addToStack(ctx.tempDeclarator.totSize(), stream);
        ctx.currentScope()->addToBindings(ctx.tempDeclarator.id, ctx.tempDeclarator.offset, ctx.tempDeclarator.elements, ctx.tempDeclarator.size, false, ctx.tempDeclarator.isPointer);
        if(initialiserPtr != NULL){
            initialiserPtr->printMips(ctx, stream);   
        }
    }
    
}


//direct_declarator

direct_declarator::direct_declarator(std::string s): identifier(s) {}

void direct_declarator::printMips(compilerContext& ctx, std::ostream& stream){
    if(!ctx.funcDef && !ctx.globalDefs){
        ctx.tempDeclarator.id = identifier;
        ctx.tempDeclarator.elements = 1;
    }else if(!ctx.funcDef && ctx.globalDefs){
        ctx.tempDeclarator.id = identifier;
        ctx.tempDeclarator.elements = 1;
        stream << "\t.global " << ctx.tempDeclarator.id << std::endl;
        stream << "\t.type " << ctx.tempDeclarator.id << ", @object" << std::endl;
        stream << ctx.tempDeclarator.id << ":" << std::endl;
        
    }else if(ctx.funcDef){
        stream << ".text" << std::endl;
        stream << ".global " << identifier << std::endl;
        stream << ".ent " << identifier << std::endl;
        stream << ".type " << identifier << ", @function" << std::endl << std::endl;
        stream << identifier << ":" << std::endl;
        ctx.funcName = identifier;
    }
}


void initialiser::printMips(compilerContext& ctx, std::ostream& stream){
    if(assignment != NULL){
        if(!ctx.globalDefs){
            if(ctx.tempDeclarator.isArray){
                assignment->printMips(ctx, stream);
                stream << "sw $2,"<<  (ctx.currentFunc()->memUsed - ctx.tempDeclarator.offset - (ctx.tempDeclarator.size*4) + ctx.tempDeclarator.initOffset) <<"($sp)" << std::endl;
            }else{
                assignment->printMips(ctx, stream);
                stream << "sw $2,"<<  (ctx.currentFunc()->memUsed - ctx.tempDeclarator.offset) <<"($sp)" << std::endl;
            }
        }else{
            int temp = assignment->eval(); //implemente val function
            stream << "\t.word " << temp << std::endl;
        }
    }
}

void ObjectInitialiser::printMips(compilerContext& ctx, std::ostream& stream){
    if(initList != NULL){initList->printMips(ctx, stream);}
}



//initialiser

initialiser::initialiser(ExpPtr a): assignment(a) {}

//ArrayDeclaration

void ArrayDeclaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(varName != NULL){varName->printMips(ctx, stream);}
    if(size != NULL){
        ctx.tempDeclarator.elements = size->eval();
        ctx.tempDeclarator.isArray = true;

    }
    else{
        ctx.tempDeclarator.elements = 0; //represents empty array
    }
}


//function definition
void function_definition::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.funcDef = true;
    ctx. globalDefs = false;
    ctx.functions.push_back(funcScope(stream, ctx.globalVars)); //creates function
    if(name != NULL){name->printMips(ctx, stream);} //prints a label
    ctx.setup(stream);
    for(int i = 0; (i < ctx.currentFunc()->parameters.size()) && (i<4); i++){
        stream << "sw $" << (i+4) << ", " << (i*4) << "($fp)" << std::endl;  
    }
    //if(type != NULL){type->printMips(ctx, stream);}
    ctx.funcDef = false;
    if(statement != NULL){statement->printMips(ctx, stream);} //prints actual statement
    ctx.endFunc(stream);
    stream << ".end " << ctx.funcName << std::endl;
    ctx.funcName.clear();
    ctx.functions.pop_back();
}

//FunctionDeclaration
void FunctionDeclaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(ctx.funcDef){
        if(funcName != NULL){funcName->printMips(ctx, stream);}
        if(argList != NULL){argList->printMips(ctx, stream);}
    }
}

void parameter_declaration::printMips(compilerContext& ctx, std::ostream& stream){
    bool temp = ctx.funcDef;
    ctx.funcDef = false;
    if(specifiers != NULL){specifiers->printMips(ctx, stream);}
    if(dec != NULL){dec->printMips(ctx, stream);}
    ctx.tempDeclarator.offset = -(ctx.currentFunc()->parameters.size()*4);
    ctx.currentFunc()->parameters[ctx.tempDeclarator.id] = varData(ctx.tempDeclarator.offset, ctx.tempDeclarator.elements, ctx.tempDeclarator.size, false, ctx.tempDeclarator.isPointer);
    ctx.tempDeclarator.purge();
    ctx.funcDef = temp;
    
}

//EnumConstants
void EnumConstants::printMips(compilerContext& ctx, std::ostream& stream){
    if(enumList != NULL){enumList->printMips(ctx, stream);}
}

//EnumSpecifier

void EnumSpecifier::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.tempDeclarator.size = 4;
}

void enumerator::printMips(compilerContext& ctx, std::ostream& stream){
    int enumVal;
    if(val != NULL){
        enumVal = val->eval();
        ctx.enumCtx.nextVal = enumVal + 1;
    }else{
        enumVal = ctx.enumCtx.nextVal++;
    }
	if(ctx.functions.size() == 0){
        ctx.globalVars[id] = varData(enumVal, true, true);
    }else{
        (*ctx.currentBindings())[id] = varData(enumVal, true, false);
    }
}


void declarator::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.tempDeclarator.isPointer = true;
    if(directDeclarator != NULL){directDeclarator->printMips(ctx, stream);}
}

void typedef_declaration::printMips(compilerContext& ctx, std::ostream& stream){
    if(defName != NULL){specifierList->printMips(ctx,stream);}
    if(specifierList != NULL){specifierList->printMips(ctx,stream);}
    if(ctx.functions.size() == 0){
        ctx.globalVars[ctx.tempDeclarator.id] = varData(true, ctx.tempDeclarator.size);
    }else{
        (*ctx.currentBindings())[ctx.tempDeclarator.id] = varData(true, ctx.tempDeclarator.size);
    }
    ctx.tempDeclarator.purge();
}

void TypdefSpecifier::printMips(compilerContext& ctx, std::ostream& stream){
    if(ctx.functions.size() == 0){
        ctx.tempDeclarator.size = ctx.globalVars[defName].type;
    }else{ 
        ctx.tempDeclarator.size = (*ctx.currentBindings())[defName].type;
    }
}