#include "WhileStmnt.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string WhileStmnt::TREE_ID = "WhileStmnt";

WhileStmnt::WhileStmnt(const std::vector<ASTree*>& list)
	:ASTList(list)
{
	ASTree::init(TREE_ID);
}

ASTree* WhileStmnt::getCondition() const
{
	return getChild(0);
}

ASTree* WhileStmnt::getBody() const
{
	return getChild(1);
}

void WhileStmnt::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

std::string WhileStmnt::toString() const
{
	return "(while " + getCondition()->toString() + " " + getBody()->toString() + ")";
}
NS_LAN_END