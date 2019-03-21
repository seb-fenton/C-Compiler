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
        }
        else{
            int retrieveVariable = ctx.currentFunc()->memUsed - (*ctx.currentBindings())[identifier].offset;
            stream << "lw $2," << retrieveVariable << "($sp)" << std::endl;
        }
    }
    else{
        if(ctx.getAddr){
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
        storeOperand(8, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;
        
        stream << "sw $8, 0($2)" << std::endl;
        loadOperand(8, 0, stream);
        ctx.removeFromStack(4, stream);
    }      
    else if(op == "<<"){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "sllv $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;

        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }  
    else if(op == ">>"){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "srlv $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }  
    else if(op == "+="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "add $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }
    else if(op == "-="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "sub $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    } 
    else if(op == "*="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "mult $8,$9" << std::endl << "mflo $8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }  
    else if(op == "/="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "div $8,$9" << std::endl << "mflo $8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }
    else if(op == "%="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "div $8,$9" << std::endl << "mfhi $8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }    
    else if(op == "&="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "and $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }    
    else if(op == "|="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "or $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }  
    else if(op == "|="){
        ctx.addToStack(4, stream);
        storeOperand(8, 4, stream);
        storeOperand(9, 0, stream);

        if(right != NULL){right->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        if(left != NULL){left->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        ctx.getAddr = true;
        if(left != NULL){left->printMips(ctx, stream);}
        ctx.getAddr = false;

        stream << "xor $8,$9,$8" << std::endl;
        
        stream << "sw $8, 0($2)" << std::endl;
        
        loadOperand(8, 4, stream);
        loadOperand(9, 0, stream);
        ctx.removeFromStack(4, stream);
    }             
}


//conditional_expression

void conditional_expression::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(8, 4, stream);
    storeOperand(9, 0, stream);

    Cond->printMips(ctx,stream);

    std::string tempLabelTrue = ctx.generateLabel("true_");
    std::string tempLabelFalse = ctx.generateLabel("false_");


    stream << "addiu $8,$0,1" << std::endl;

    stream << "beq $2,$8," << tempLabelTrue << std::endl;
    stream << "nop" << std::endl;                         
    
    FalseExp->printMips(ctx, stream);

    stream << "j  " << tempLabelFalse << "\nnop" <<std::endl;
    stream << tempLabelTrue << ": \nnop" << std::endl;

    TrueExp->printMips(ctx, stream);

    stream << tempLabelFalse << ": \nnop" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabelOne = ctx.generateLabel("label");
    std::string tempLabelTwo = ctx.generateLabel("label");
    std::string tempLabelThree = ctx.generateLabel("label");

    stream << "bne $8,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $9,$0," << tempLabelTwo << std::endl << "nop" << std::endl;
    
    stream << tempLabelOne << ": \nli $2,1" << std::endl << "j " << tempLabelThree << std::endl << "nop" << std::endl;

    stream << tempLabelTwo << ": \nmove $2,$0" << std::endl;

    stream << tempLabelThree << ":" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabelOne = ctx.generateLabel("label");
    std::string tempLabelTwo = ctx.generateLabel("label");

    stream << "beq $8,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $9,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    
    stream << "li $2,1" << std::endl << "j " << tempLabelTwo << std::endl << "nop" << std::endl;

    stream << tempLabelOne << ": \nmove $2, $0" << std::endl;

    stream << tempLabelTwo << ":" << std::endl;


	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "or $2,$8,$9" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "xor $2,$8,$9" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "and $2,$8,$9" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "xor $2,$9,$8" << std::endl;            //magically works?
    stream << "slti $2,$2, 1" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream);
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "xor $2,$9,$8" << std::endl;            //magically works?
    stream << "slt $2,$0,$2" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream);
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 < $9
    stream << "andi $2,$2,0x00ff" << std::endl;         //magic?

	loadOperand(8, 0, stream);
	loadOperand(9, 0, stream);
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 < $9

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "slt $2,$8,$9" << std::endl;               // checks if $8 < $9
    stream << "xori $2,$2,0x1" << std::endl;            //magically works?
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 0, stream);
	loadOperand(9, 0, stream);
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "slt $2,$9,$8" << std::endl;                // checks if $8 > $9
    stream << "xori $2,$2,0x1" << std::endl;            //magically works?
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 0, stream);
	loadOperand(9, 0, stream);
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "sllv $2,$8,$9" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "srav $2,$8,$9" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
	storeOperand(8, 4,stream);
	storeOperand(9, 0,stream);

	left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);
		
	addOperands(2,8,9,stream);

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int AddOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() + right->eval());
    }
}

//SubOp

void SubOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
	storeOperand(8, 4,stream);
	storeOperand(9, 0,stream);

	left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);
		
	stream << "sub $2,$8,$9" << std::endl;
		
	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
}

int SubOp::eval(){
    if(left != NULL && right != NULL){
        return (left->eval() - right->eval());
    }
}

//MultOp

void MultOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(8, 4, stream);
    storeOperand(9, 0, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream); //not necessary; for clarity

    stream << "mult $8,$9" << std::endl;
    stream << "mflo $2" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream); //not necessary; for clarity

    stream << "div $8,$9" << std::endl;
    stream << "mflo $2" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "div $8,$9" << std::endl;
    stream << "mfhi $2" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
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
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,1" << std::endl;
}


//PreDecOp

void PreDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,-1" << std::endl;
}


//PreIncOp

void PostIncOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,1" << std::endl;
}


//PostDecOp

void PostDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,-1" << std::endl;
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
    stream << "subu $2,$0,$2" << std::endl;
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
    if(list != NULL){list->printMips(ctx, stream);}
    stream << "move $fp, $sp" << std::endl;
    ctx.funcCall = true;
    if(expr != NULL){expr->printMips(ctx, stream);}
    stream << "lw $fp, " << (ctx.currentFunc()->memUsed - 8) << "($sp)" << std::endl; //reset frame pointer
    ctx.funcCall = false;
}

void array_call::printMips(compilerContext& ctx, std::ostream& stream){
    if(ctx.getAddr){
        ctx.addToStack(8, stream);
        storeOperand(8, 4,stream);
        storeOperand(9, 0,stream);

        if(array != NULL){array->printMips(ctx, stream);}
        addOperands(8,2,0,stream);

        ctx.getAddr = false; //maybe need to set it back to true?
        if(idx != NULL){idx->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        stream << "sll $9, $9, 2" << std::endl;

        addOperands(2,8,9,stream);
        loadOperand(8, 4, stream);
	    loadOperand(9, 0, stream); 
        ctx.removeFromStack(8, stream);
        stream << std::endl;
    }else{
        ctx.addToStack(8, stream);
        storeOperand(8, 4,stream);
        storeOperand(9, 0,stream);

        ctx.getAddr = true;
        if(array != NULL){array->printMips(ctx, stream);}
        addOperands(8,2,0,stream);
        ctx.getAddr = false;

        if(idx != NULL){idx->printMips(ctx, stream);}
        addOperands(9,2,0,stream);

        stream << "sll $9, $9, 2" << std::endl;

        addOperands(2,8,9,stream);
        stream << "lw $2, 0($2)" << std::endl;
        loadOperand(8, 4, stream);
	    loadOperand(9, 0, stream); 
        ctx.removeFromStack(8, stream);
    }
}

