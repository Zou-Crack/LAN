#include "BlockStmnt.h"
#include "ASTTree.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string BlockStmnt::TREE_ID = "BlockStmnt";

BlockStmnt::BlockStmnt(const std::vector<ASTree*>& list)
	:ASTList(list)
{
	ASTree::init(TREE_ID);
}

void BlockStmnt::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END