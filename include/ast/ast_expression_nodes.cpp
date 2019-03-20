#include "ast_expression_nodes.hpp"
#include "context.hpp"


//primary_expression

void primary_expression::printMips(compilerContext& ctx, std::ostream& stream){
    int retrieveVariable = ctx.currentFunc()->memUsed - (*ctx.currentBindings())[identifier].offset;
    stream << "lw $2," << retrieveVariable << "($sp)" << std::endl;
}


//constantNode

void constantNode::printMips(compilerContext& ctx, std::ostream& stream){
    stream << "addiu $2,$0," << (int)init << std::endl;
}


//conditional_expression

void conditional_expression::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    Cond->printMips(ctx,stream);

    std::string tempLabelTrue = ctx.generateUniqueLabel();
    std::string tempLabelFalse = ctx.generateUniqueLabel();


    stream << "addiu $8,$0,1" << std::endl;

    stream << "beq $2,$8," << tempLabelTrue << std::endl;
    stream << "nop" << std::endl;                         
    
    FalseExp->printMips(ctx, stream);

    stream << "jump " << tempLabelFalse << std::endl;
    stream << tempLabelTrue << ": nop" << std::endl;

    TrueExp->printMips(ctx, stream);

    stream << tempLabelFalse << ": nop" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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

    std::string tempLabelOne = ctx.generateUniqueLabel();
    std::string tempLabelTwo = ctx.generateUniqueLabel();
    std::string tempLabelThree = ctx.generateUniqueLabel();

    stream << "bne $8,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $9,$0," << tempLabelTwo << std::endl << "nop" << std::endl;
    
    stream << tempLabelOne << ": li $2,1" << std::endl << "b " << tempLabelThree << std::endl << "nop" << std::endl;

    stream << tempLabelTwo << ": move $2,$0" << std::endl;

    stream << tempLabelThree << ":" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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

    std::string tempLabelOne = ctx.generateUniqueLabel();
    std::string tempLabelTwo = ctx.generateUniqueLabel();

    stream << "beq $8,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    stream << "beq $9,$0," << tempLabelOne << std::endl << "nop" << std::endl;
    
    stream << ": li $2,1" << std::endl << "b " << tempLabelTwo << std::endl << "nop" << std::endl;

    stream << tempLabelOne << "move $2, $0" << std::endl;

    stream << tempLabelTwo << ":" << std::endl;


	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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


//EOp

void EqualOp::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.addToStack(8, stream);
    storeOperand(8, 4,stream);
    storeOperand(9, 0,stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "xoru $2,$9,$8" << std::endl;            //magically works?
    stream << "slti $2,$2, 1" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 0, stream);
	loadOperand(9, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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

    stream << "xoru $2,$9,$8" << std::endl;            //magically works?
    stream << "slt $2,$0,$2" << std::endl;
    stream << "andi $2,$2,0x00ff" << std::endl;

	loadOperand(8, 0, stream);
	loadOperand(9, 0, stream);
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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
    stream << "mflo $2" << std::endl;

	loadOperand(8, 4, stream);
	loadOperand(9, 0, stream); 
    stream << std::endl;
    ctx.removeFromStack(8, stream);
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


//USubOp

void USubOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "subu $2,$0,$2" << std::endl;
}


//BitwiseNotOp

void BitwiseNotOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "nor $2,$0,$2" << std::endl;
}


//LogicalNotOp


void function_call::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.funcCall = true;
    //print arguments
    if(list != NULL){list->printMips(ctx, stream);}
    if(expr != NULL){expr->printMips(ctx, stream);}
}

void LogicalNotOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx, stream);
    stream << "sltu $2,$2,1" << std::endl << "andi $2,$2,0x00ff" << std::endl;
}