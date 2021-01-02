#include "NegativeExpr.h"
#include "ASTTree.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string NegativeExpr::TREE_ID = "NegativeExpr";

NegativeExpr::NegativeExpr(ASTree* a)
{
	ASTree::init(TREE_ID);
	_children.push_back(a);
}

NegativeExpr::NegativeExpr(const std::vector<ASTree*>& list)
	:ASTList(list)
{
}

ASTree* NegativeExpr::getOperand()
{
	return getChild(0);
}

std::string NegativeExpr::toString() const
{
	return "-" + getChild(0)->toString();
}

void NegativeExpr::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END