#include "ast_expression_nodes.hpp"
#include "context.hpp"


//primary_expression

void primary_expression::printMips(compilerContext& ctx, std::ostream& stream){
    if(ctx.funcCall){
        stream << "jal " << identifier << std::endl;
    }else if(!((*ctx.currentBindings())[identifier].global)){
        if(ctx.getAddr){
            int retrieveVariable = ctx.currentFunc()->memUsed - (*ctx.currentBindings())[identifier].offset;
            stream << "addi $2, $sp, " << retrieveVariable << std::endl;
        }else if((*ctx.currentBindings())[identifier].isEnum){
            stream << "addi $2, $0, " << ((*ctx.currentBindings())[identifier].enumVal) << std::endl;
        }else{
            int retrieveVariable = ctx.currentFunc()->memUsed - (*ctx.currentBindings())[identifier].offset;
            stream << "lw $2," << retrieveVariable << "($sp)" << std::endl;
        }
        ctx.ptrCheck = (*ctx.currentBindings())[identifier].isPointer;
        if(((*ctx.currentBindings())[identifier].elements != 1) && (!ctx.arrayCall)){ctx.ptrCheck = true;}
    }
    else{
        if(ctx.getAddr || ctx.arrayCall){
            stream << "lui $2, %hi(" << identifier << ")" << std::endl;
            stream << "addi $2, $2, %lo(" << identifier << ")" << std::endl;
        }
        else{
            stream << "lui $2, %hi(" << identifier << ")" << std::endl;
            stream << "lw $2, %lo(" << identifier << ")($2) \nnop" << std::endl;
        }
    }
}


//constantNode

void constantNode::printMips(compilerContext& ctx, std::ostream& stream){
    stream << "addiu $2,$0," << floor(init) << std::endl;
}

int constantNode::eval(){
    return init;
}


//assignment_expression

void assignment_expression::printMips(compilerContext& ctx, std::ostream& stream){
    if(op == "="){
        ctx.addToStack(4, stream);
        storeOperand(16, 0, stream);


        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;
        addOperands(16,2,0,stream);

        if(right != NULL){right->printMips(ctx, stream);}
        
        stream << "sw $2, 0($16)" << std::endl;
        loadOperand(16, 0, stream);
        ctx.removeFromStack(4, stream);
    }      
    else if(op == "<<="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "sllv $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  

        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }  
    else if(op == ">>="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "srlv $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }  
    else if(op == "+="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        bool op1, op2 = false; //whether or not to shift

        ctx.ptrCheck = false;
        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);
        op2 = ctx.ptrCheck;

        ctx.ptrCheck = false;
        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);
        op1 = ctx.ptrCheck;

        if(op1 && !op2){
            stream << "sll $16, $16, 2" << std::endl;
        }

        if(!op1 && op2){
            stream << "sll $17, $17, 2" << std::endl;
        }


        stream << "add $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
        ctx.ptrCheck = op1 || op2;
    }
    else if(op == "-="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        bool op1, op2 = false; //whether or not to shift        

        ctx.ptrCheck = false;
        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);
        op2 = ctx.ptrCheck;

        ctx.ptrCheck = false;
        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);
        op1 = ctx.ptrCheck;

        if(op1 && !op2){
            stream << "sll $16, $16, 2" << std::endl;
        }

        if(!op1 && op2){
            stream << "sll $17, $17, 2" << std::endl;
        }

        stream << "sub $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;


        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
        ctx.ptrCheck = op1 || op2;
    } 
    else if(op == "*="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "mult $16,$17" << std::endl << "mflo $16" << std::endl;
        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }  
    else if(op == "/="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "div $17,$16" << std::endl << "mflo $16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

       
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }
    else if(op == "%="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "div $17,$16" << std::endl << "mfhi $16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }    
    else if(op == "&="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "and $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;
        
        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }    
    else if(op == "|="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "or $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }  
    else if(op == "^="){
        ctx.addToStack(8, stream);
        storeOperand(16, 4, stream);
        storeOperand(17, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(16,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(17,2,0,stream);

        stream << "xor $16,$17,$16" << std::endl;

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "sw $16, 0($2)" << std::endl;
        addOperands(2,16,0,stream);  
        
        loadOperand(16, 4, stream);
        loadOperand(17, 0, stream);
        ctx.removeFromStack(8, stream);
    }             
}


//conditional_expression

void conditional_expression::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4, stream);
    storeOperand(17, 0, stream);

    Cond->printMips(ctx,stream);

    std::string tempLabelTrue = ctx.generateLabel("true_");
    std::string tempLabelFalse = ctx.generateLabel("false_");


    stream << "addiu $16,$0,1" << std::endl;

    stream << "beq $2,$16," << tempLabelTrue << std::endl;
    stream << "nop" << std::endl;                         
    
    FalseExp->printMips(ctx, stream);

    stream << "j  " << tempLabelFalse << "\nnop" <<std::endl;
    stream << tempLabelTrue << ": \nnop" << std::endl;

    TrueExp->printMips(ctx, stream);

    stream << tempLabelFalse << ": \nnop" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int conditional_expression::eval(){
    if(Cond != NULL){
        if(Cond->eval()){
            if(TrueExp != NULL){return TrueExp->eval();}
        }else{
            if(FalseExp != NULL){return FalseExp->eval();}
        }
    }
}


//LogicalOrOp

void LogicalOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    std::string tempLabelOne = ctx.generateLabel("label");
    std::string tempLabelTwo = ctx.generateLabel("label");
    std::string tempLabelThree = ctx.generateLabel("label");

    stream << "bne $16,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $17,$0," << tempLabelTwo << std::endl << "nop" << std::endl;
    
    stream << tempLabelOne << ": \nli $2,1" << std::endl << "j " << tempLabelThree << std::endl << "nop" << std::endl;

    stream << tempLabelTwo << ": \nmove $2,$0" << std::endl;

    stream << tempLabelThree << ":" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}


int LogicalOrOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() || right->eval());
    }
}

//LogicalAndOp

void LogicalAndOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    std::string tempLabelOne = ctx.generateLabel("label");
    std::string tempLabelTwo = ctx.generateLabel("label");

    stream << "beq $16,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $17,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    
    stream << "li $2,1" << std::endl << "j " << tempLabelTwo << std::endl << "nop" << std::endl;

    stream << tempLabelOne << ": \nmove $2, $0" << std::endl;

    stream << tempLabelTwo << ":" << std::endl;


	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int LogicalAndOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() && right->eval());
    }
}

//OrOp

void InclusiveOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "or $2,$16,$17" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int InclusiveOrOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() | right->eval());
    }
}

//XorOp

void ExclusiveOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "xor $2,$16,$17" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int ExclusiveOrOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() ^ right->eval());
    }
}


//AndOp

void AndOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "and $2,$16,$17" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int AndOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() & right->eval());
    }
}

//EOp

void EqualOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "xor $2,$17,$16" << std::endl;            //magically works?
    stream << "slti $2,$2, 1" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int EqualOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() == right->eval());
    }
}

//NEOp

void NotEqualOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "xor $2,$17,$16" << std::endl;            //magically works?
    stream << "slt $2,$0,$2" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int NotEqualOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() != right->eval());
    }
}

//GTOp

void GreaterThanOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "slt $2,$17,$16" << std::endl;                // checks if $16 < $17
    stream << "andi $2,$2,0x00ff" << std::endl;         //magic?

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int GreaterThanOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() > right->eval());
    }
}


//LTOp

void LessThanOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "slt $2,$16,$17" << std::endl;                // checks if $16 < $17

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int LessThanOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() < right->eval());
    }
}



//LTEOp

void LessThanEqOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "slt $2,$17,$16" << std::endl;               // checks if $16 < $17
    stream << "xori $2,$2,0x1" << std::endl;            //magically works?
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int LessThanEqOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() <= right->eval());
    }
}

//GTEOp

void GreaterThanEqOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "slt $2,$16,$17" << std::endl;                // checks if $16 > $17
    stream << "xori $2,$2,0x1" << std::endl;            //magically works?
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int GreaterThanEqOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() >= right->eval());
    }
}

//LeftShiftOp

void LeftShiftOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "sllv $2,$16,$17" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int LeftShiftOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() << right->eval());
    }
}

//RightShiftOp

void RightShiftOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "srav $2,$16,$17" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int RightShiftOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() >> right->eval());
    }
}

//AddOp

void AddOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
	storeOperand(16, 4,stream);
	storeOperand(17, 0,stream);

    bool op1, op2 = false; //whether or not to shift

    ctx.ptrCheck = false;
	left->printMips(ctx,stream);
	addOperands(16,2,0,stream);
    op2 = ctx.ptrCheck;
    ctx.ptrCheck = false;
	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);
    op1 = ctx.ptrCheck;
    if(op1 && !op2){
        stream << "sll $16, $16, 2" << std::endl;
    }

    if(!op1 && op2){
        stream << "sll $17, $17, 2" << std::endl;
    }
		
	addOperands(2,16,17,stream);

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
    ctx.ptrCheck = op1 || op2;
}

int AddOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() + right->eval());
    }
}

//SubOp

void SubOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
	storeOperand(16, 4,stream);
	storeOperand(17, 0,stream);

    bool op1, op2 = false;

    ctx.ptrCheck = false;
	left->printMips(ctx,stream);
	addOperands(16,2,0,stream);
    op2 = ctx.ptrCheck;

    ctx.ptrCheck = false;
	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);
    op1 = ctx.ptrCheck;

    if(op1 && !op2){
        stream << "sll $16, $16, 2" << std::endl;
    }

    if(!op1 && op2){
        stream << "sll $17, $17, 2" << std::endl;
    }
		
	stream << "sub $2,$16,$17" << std::endl;
		
	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
    ctx.ptrCheck = op1 || op2;
}

int SubOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() - right->eval());
    }
}

//MultOp

void MultOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4, stream);
    storeOperand(17, 0, stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream); //not necessary; for clarity

    stream << "mult $16,$17" << std::endl;
    stream << "mflo $2" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl; 
    ctx.removeFromStack(8, stream);
}

int MultOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() * right->eval());
    }
}

//DivOp

void DivOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream); //not necessary; for clarity

    stream << "div $16,$17" << std::endl;
    stream << "mflo $2" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int DivOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() / right->eval());
    }
}

//ModOp

void ModulusOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    left->printMips(ctx,stream);
	addOperands(16,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(17,2,0,stream);

    stream << "div $16,$17" << std::endl;
    stream << "mfhi $2" << std::endl;

	loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int ModulusOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() % right->eval());
    }
}


//PreIncOp

void PreIncOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(4, stream);
    storeOperand(16, 0, stream);

    ctx.getAddr = true;
    expr->printMips(ctx,stream);
    ctx.getAddr = false;
    addOperands(16,2,0,stream);
    
    ctx.ptrCheck = false;
    expr->printMips(ctx,stream);
    if(ctx.ptrCheck){stream << "addi $2, $2, 4" << std::endl;}
    else{stream << "addi $2, $2, 1" << std::endl;}

    stream << "sw $2, 0($16) " << std::endl;
    loadOperand(16, 0, stream);
    ctx.removeFromStack(4, stream);
    

}


//PreDecOp

void PreDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(4, stream);
    storeOperand(16, 0, stream);

    ctx.getAddr = true;
    expr->printMips(ctx,stream);
    ctx.getAddr = false;
    addOperands(16,2,0,stream);
    ctx.ptrCheck = false;
    expr->printMips(ctx,stream);
    
    if(ctx.ptrCheck){stream << "addi $2, $2, -4" << std::endl;}
    else{stream << "addi $2, $2, -1" << std::endl;}
    stream << "sw $2, 0($16) " << std::endl;
    
    loadOperand(16, 0, stream);
    ctx.removeFromStack(4, stream);
}


//PreIncOp

void PostIncOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(4, stream);
    storeOperand(16, 0, stream);

    ctx.getAddr = true;
    expr->printMips(ctx,stream);
    ctx.getAddr = false;
    addOperands(16,2,0,stream);
    
    ctx.ptrCheck = false;
    expr->printMips(ctx,stream);
    if(ctx.ptrCheck){
        stream << "addi $2, $2, 4" << std::endl;
        stream << "sw $2, 0($16) " << std::endl;
        stream << "addi $2, $2, -4" << std::endl;
    }else{
        stream << "addi $2, $2, 1" << std::endl;
        stream << "sw $2, 0($16) " << std::endl;
        stream << "addi $2, $2, -1" << std::endl;

    }
    loadOperand(16, 0, stream);
    ctx.removeFromStack(4, stream);
}


//PostDecOp

void PostDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(4, stream);
    storeOperand(16, 0, stream);

    ctx.getAddr = true;
    expr->printMips(ctx,stream);
    ctx.getAddr = false;
    addOperands(16,2,0,stream);
    
    ctx.ptrCheck = false;
    expr->printMips(ctx,stream);
    if(ctx.ptrCheck){
        stream << "addi $2, $2, -4" << std::endl;
        stream << "sw $2, 0($16) " << std::endl;
        stream << "addi $2, $2, 4" << std::endl;
    }else{
        stream << "addi $2, $2, -1" << std::endl;
        stream << "sw $2, 0($16) " << std::endl;
        stream << "addi $2, $2, 1" << std::endl;

    }
    loadOperand(16, 0, stream);
    ctx.removeFromStack(4, stream);
}



//UAddOp

void UAddOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
}

int UAddOp::eval(){
    if(expr != NULL){
        return expr->eval();
    }
}


//USubOp

void USubOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "sub $2,$0,$2" << std::endl;
}

int USubOp::eval(){
    if(expr != NULL){
        return -(expr->eval());
    }
}

//BitwiseNotOp

void BitwiseNotOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "nor $2,$0,$2" << std::endl;
}

int BitwiseNotOp::eval(){
    if(expr != NULL){
        return ~(expr->eval());
    }
}

//LogicalNotOp

void LogicalNotOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "sltu $2,$2,1" << std::endl << "andi $2,$2,0x00ff" << std::endl;
}

int LogicalNotOp::eval(){
    if(expr != NULL){
        return !(expr->eval());
    }
}

//-------------

void function_call::printMips(compilerContext& ctx, std::ostream& stream){
    //print arguments
    //move frame pointer down to stack pointer
    ctx.addToStack(16, stream); //store previous function args
	storeOperand(4, 0, stream);
	storeOperand(5, 4, stream);
	storeOperand(6, 8, stream);
	storeOperand(7, 12, stream);
    int memUsedStore = ctx.currentFunc()->memUsed;
    if(list != NULL){list->printMips(ctx, stream);}
    stream << "move $fp, $sp" << std::endl;
    ctx.funcCall = true;
    if(expr != NULL){expr->printMips(ctx, stream);}
    stream << "lw $fp, " << (ctx.currentFunc()->memUsed - 8) << "($sp)\nnop" << std::endl; //reset frame pointer
    ctx.funcCall = false;
    int funcOffset = ctx.currentFunc()->memUsed - memUsedStore;
    stream << "addi $sp, $sp, " << funcOffset << std::endl;
    ctx.currentFunc()->memUsed = memUsedStore; //data used for function call needs to reset
    loadOperand(4, 0, stream);
	loadOperand(5, 4, stream);
	loadOperand(6, 8, stream);
	loadOperand(7, 12, stream);
	ctx.removeFromStack(16, stream);
}

void array_call::printMips(compilerContext& ctx, std::ostream& stream){
    bool temp = ctx.getAddr;
    ctx.getAddr = false;

    ctx.addToStack(8, stream);
    storeOperand(16, 4,stream);
    storeOperand(17, 0,stream);

    ctx.arrayCall = true;
    if(array != NULL){array->printMips(ctx, stream);}
    addOperands(16,2,0,stream);
    ctx.arrayCall = true;

    if(idx != NULL){idx->printMips(ctx, stream);}
    addOperands(17,2,0,stream);

    ctx.getAddr = temp;
    stream << "sll $17, $17, 2" << std::endl;
    addOperands(2,16,17, stream);

    if(!ctx.getAddr){
        stream << "lw $2, 0($2)" << std::endl;
    }

    loadOperand(16, 4, stream);
	loadOperand(17, 0, stream); 
    ctx.removeFromStack(8, stream);
}

void RefOp::printMips(compilerContext& ctx, std::ostream& stream){
    bool temp = ctx.getAddr;
    ctx.getAddr = true;
    if(expr != NULL){expr->printMips(ctx, stream);}
    ctx.getAddr = temp;
}

void PtrOp::printMips(compilerContext& ctx, std::ostream& stream){
    bool temp = ctx.getAddr;
    ctx.getAddr = false;
    expr->printMips(ctx, stream);

    ctx.getAddr = temp;
    if(!ctx.getAddr){
        stream << "lw $2, 0($2)" << std::endl;
    }
}
