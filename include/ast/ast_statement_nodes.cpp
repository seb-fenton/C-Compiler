#include "ast_statement_nodes.hpp"

//Compound Statement
void compound_statement::printMips(compilerContext& ctx, std::ostream& stream){
    ctx.currentFunc()->incScope();
    if(block_list != NULL){block_list->printMips(ctx, stream);}
    ctx.currentFunc()->decScope(stream);
}

//Block Item List
void block_item_list::printMips(compilerContext& ctx, std::ostream& stream){
    for(int i = 0; i < (int)branches.size(); i++){
		branches[i]->printMips(ctx, stream);
	}
}


//IfStatement
void IfStatement::printMips(compilerContext& ctx, std::ostream& stream){
    std::string trueEnd = ctx.generateLabel("TRUE_END_");
    std::string falseEnd = ctx.generateLabel("FALSE_END_");
    if(cond != NULL){cond->printMips(ctx, stream);}
    stream << "beq $2, $0, " << trueEnd << "\nnop" << std::endl;
    _true->printMips(ctx, stream);
    if(_false != NULL){stream << "j " << falseEnd << "\nnop" << std::endl;}
    stream << trueEnd << ":" << std::endl;
    if(_false != NULL){
        _false->printMips(ctx, stream);
        stream << falseEnd << ":" << std::endl;
    }
    stream << "nop" << std::endl;
    stream << "move $2, $0" << std::endl;
}

//WhileStatement
void WhileStatement::printMips(compilerContext& ctx, std::ostream& stream){
    std::string startLabel = ctx.generateLabel("start_");
    std::string endLabel = ctx.generateLabel("end_");
    ctx.currentFunc()->LoopsLabels.push_back(LoopContext(startLabel, endLabel));
    stream << startLabel << ":" << std::endl;
    cond->printMips(ctx, stream);
    stream << "beq $2, $0, " << endLabel << "\nnop" << std::endl;
    stmt->printMips(ctx, stream);
    stream << "j " << startLabel << "\nnop" << std::endl;
    stream << endLabel << ":" << std::endl;
    stream << "move $2, $0" << std::endl;

}

//Do statement
void DoStatement::printMips(compilerContext& ctx, std::ostream& stream){
    std::string startLabel = ctx.generateLabel("start_");
    std::string endLabel = ctx.generateLabel("end_");
    std::string doTrueLabel = ctx.generateLabel("doTrue_");

    ctx.currentFunc()->LoopsLabels.push_back(LoopContext(startLabel, endLabel));

    stream << doTrueLabel << ":" << std::endl;
    stmt->printMips(ctx, stream);

    stream << startLabel << ":" << std::endl;
    cond->printMips(ctx, stream);

    stream << "bne $2, 0, " << doTrueLabel << "\nnop" << std::endl;
    stream << endLabel << ":" << std::endl;

    stream << "move $2, $0" << std::endl;

}

//ForStatement

void ForStatement::printMips(compilerContext& ctx, std::ostream& stream){
    std::string startLabel = ctx.generateLabel("start_");
    std::string endLabel = ctx.generateLabel("end_");
    std::string iterateLabel = ctx.generateLabel("iterate_");

    ctx.currentFunc()->LoopsLabels.push_back(LoopContext(iterateLabel, endLabel));

    if(init != NULL){init->printMips(ctx,stream);}

    stream << startLabel << ":" << std::endl;
    if(cond != NULL){cond->printMips(ctx,stream);}
    stream << "beq $2, $0, " << endLabel << "\nnop" << std::endl;

    if(stmt != NULL){stmt->printMips(ctx,stream);}

    stream << iterateLabel << ":" << std::endl;
    if(iter != NULL){iter->printMips(ctx,stream);}
    stream << "j " << startLabel << "\nnop" << std::endl;

    stream << endLabel << ":" << std::endl;
    stream << "move $2, $0" << std::endl;
}


//ReturnStatement
void ReturnStatement::printMips(compilerContext& ctx, std::ostream& stream){
    if(expr != NULL){expr->printMips(ctx, stream);}
    ctx.endFunc(stream);
}

void ContinueStatement::printMips(compilerContext& ctx, std::ostream& stream){
    stream << "j " << ctx.currentFunc()->LoopsLabels.back().cont << " \nnop" << std::endl;
}

void BreakStatement::printMips(compilerContext& ctx, std::ostream& stream){
    stream << "j " << ctx.currentFunc()->LoopsLabels.back().brk << " \nnop" << std::endl;
}

void expression_statement::printMips(compilerContext& ctx, std::ostream& stream){
    if(stmt != NULL){stmt->printMips(ctx,stream);}
}