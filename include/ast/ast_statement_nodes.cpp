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
    if(_false != NULL){stream << "b " << falseEnd << std::endl;}
    stream << trueEnd << ":" << std::endl;
    if(_false != NULL){
        _false->printMips(ctx, stream);
        stream << falseEnd << std::endl;
    }
    stream << "move $2, $0" << std::endl;
}

//WhileStatement
void WhileStatement::printMips(compilerContext& ctx, std::ostream& stream){
    std::string startLabel = ctx.generateLabel("start_");
    std::string endLabel = ctx.generateLabel("end_");
    ctx.currentFunc()->whileLoops.push_back(WhileContext(startLabel, endLabel));
    stream << startLabel << ":" << std::endl;
    cond->printMips(ctx, stream);
    stream << "beq $2, 0, " << endLabel << "\nnop" << std::endl;
    stmt->printMips(ctx, stream);
    stream << "b " << startLabel << "\nnop" << std::endl;
    stream << endLabel << ":" << std::endl;
    stream << "move $2, $0" << std::endl;

}