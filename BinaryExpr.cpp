#include "BinaryExpr.h"
#include "ASTLeaf.h"
#include "Token.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string BinaryExpr::TREE_ID = "BinaryExpr";

BinaryExpr::BinaryExpr(const std::vector<ASTree*>& list)
	:ASTList(list)
{
	ASTree::init(TREE_ID);
}

BinaryExpr::BinaryExpr(ASTree* left, ASTLeaf* op, ASTree* right)
{
	_children.push_back(left);
	_children.push_back(op);
	_children.push_back(right);
}


BinaryExpr::~BinaryExpr()
{
}

void BinaryExpr::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

ASTree* BinaryExpr::getLeft() const
{
	return getChild(0);
}

std::string BinaryExpr::getOperator() const
{
	return static_cast<ASTLeaf*>(getChild(1))->getToken()->asString();
}

ASTree* BinaryExpr::getRight() const
{
	return getChild(2);
}
NS_LAN_END
