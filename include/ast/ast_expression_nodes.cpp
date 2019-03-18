#include "ast_expression_nodes.hpp"
#include "context.hpp"


//conditional_expression

void conditional_expression::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

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

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//LogicalOrOp

void LogicalOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    //TODO : WHAT DO WE DO FOR LOGICAL Or
    stream << "or $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//LogicalAndOp

void LogicalAndOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    //TODO : WHAT DO WE DO FOR LOGICAL AND
    stream << "and $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//OrOp

void InclusiveOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "or $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//XorOp

void ExclusiveOrOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "xor $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//AndOp

void AndOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "and $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//EOp

void EqualOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabel = ctx.generateUniqueLabel();
    std::string tempLabelSkip = ctx.generateUniqueLabel();

    stream << "beq $8,$9," << tempLabel << std::endl;
    stream << "nop" << std::endl;                         // needed?
    
    stream << "jump " << tempLabelSkip << std::endl;      // else goes to tempLabelSkip
    stream << "nop" << std::endl;                         // needed?

    stream << tempLabel << ": addiu $2,$0,1" << std::endl;
    stream << tempLabelSkip << ": nop" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//NEOp

void NotEqualOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabel = ctx.generateUniqueLabel();
    std::string tempLabelSkip = ctx.generateUniqueLabel();

    stream << "bne $8,$9," << tempLabel << std::endl;
    stream << "nop" << std::endl;                         // needed?
    
    stream << "jump " << tempLabelSkip << std::endl;      // else goes to tempLabelSkip
    stream << "nop" << std::endl;                         // needed?

    stream << tempLabel << ": addiu $2,$0,1" << std::endl;
    stream << tempLabelSkip << ": nop" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//GTOp

void GreaterThanOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabel = ctx.generateUniqueLabel();
    std::string tempLabelSkip = ctx.generateUniqueLabel();

    stream << "beq $8,$9," << tempLabelSkip << std::endl;
    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 < $9
    stream << "beq $2,0," << tempLabel << std::endl;      // if $8 > $9, goes to tempLabel
    
    stream << "jump " << tempLabelSkip << std::endl;      // else goes to tempLabelSkip
    stream << "nop" << std::endl;                         // needed?

    stream << tempLabel << ": addiu $2,$0,1" << std::endl;
    stream << tempLabelSkip << ": nop" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//LTOp

void LessThanOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 < $9

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//LTEOp

void LessThanEqOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabel = ctx.generateUniqueLabel();
    std::string tempLabelSkip = ctx.generateUniqueLabel();

    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 < $9
    stream << "beq $8,$9," << tempLabel << std::endl;     // if $s0 = $s2, goes to tempLabel
    
    stream << "jump " << tempLabelSkip << std::endl;      // else goes to tempLabelSkip
    stream << "nop" << std::endl;                         // needed?

    stream << tempLabel << ": addiu $2,$0,1" << std::endl;
    stream << tempLabelSkip << ": nop" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//GTEOp

void GreaterThanEqOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    std::string tempLabel = ctx.generateUniqueLabel();
    std::string tempLabelSkip = ctx.generateUniqueLabel();

    stream << "slt $2,$8,$9" << std::endl;                // checks if $8 > $9
    stream << "beq $2,0," << tempLabel << std::endl;      // if $8 > $9, goes to tempLabel
    stream << "beq $8,$9," << tempLabel << std::endl;     // if $s0 = $s2, goes to tempLabel - TODO : Redundant??
    
    stream << "jump " << tempLabelSkip << std::endl;      // else goes to tempLabelSkip
    stream << "nop" << std::endl;                         // needed?

    stream << tempLabel << ": addiu $2,$0,1" << std::endl;
    stream << tempLabelSkip << ": nop" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//LeftShiftOp

void LeftShiftOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "sllv $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//RightShiftOp

void RightShiftOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "srav $2,$8,$9" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//AddOp

void AddOp::printMips(compilerContext& ctx, std::ostream& stream){
	storeOperand(3,stream);
	storeOperand(4,stream);

	left->printMips(ctx,stream);
	addOperands(3,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(4,2,0,stream);
		
	addOperands(2,4,3,stream);

	loadOperand(3,stream);
	loadOperand(4,stream); 
    stream << std::endl;
}


//SubOp

void SubOp::printMips(compilerContext& ctx, std::ostream& stream){
	storeOperand(8,stream);
	storeOperand(9,stream);

	left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);
		
	stream << "sub $2,$8,$9" << std::endl;
		
	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//MultOp

void MultOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "mult $8,$9" << std::endl;
    stream << "addu $2,$lo,$0" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream);
    stream << std::endl; 
}


//DivOp

void DivOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "div $8,$9" << std::endl;
    stream << "mflo $8" << std::endl;
    stream << "addu $2,$8,$0" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//ModOp

void ModulusOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);
    storeOperand(9, stream);

    left->printMips(ctx,stream);
	addOperands(8,2,0,stream);

	right->printMips(ctx,stream);
	addOperands(9,2,0,stream);

    stream << "div $8,$9" << std::endl;
    stream << "mflo $8" << std::endl;
    stream << "addu $2,$8,$0" << std::endl;

	loadOperand(8,stream);
	loadOperand(9,stream); 
    stream << std::endl;
}


//PreIncOp

void PreIncOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,1" << std::endl;
}


//PreDecOp

void PreDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);

    expr->printMips(ctx,stream);
    
    stream << "addiu $8,$0,1" << std::endl;
    stream << "subu $2,$2,$8" << std::endl;

    loadOperand(8,stream); 
}


//PreIncOp

void PostIncOp::printMips(compilerContext& ctx, std::ostream& stream){
    expr->printMips(ctx,stream);
    stream << "addiu $2,$2,1" << std::endl;
}


//PostDecOp

void PostDecOp::printMips(compilerContext& ctx, std::ostream& stream){
    storeOperand(8, stream);

    expr->printMips(ctx,stream);
    
    stream << "addiu $8,$0,1" << std::endl;
    stream << "subu $2,$2,$8" << std::endl;

    loadOperand(8,stream); 
}