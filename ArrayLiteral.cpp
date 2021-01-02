#include "ArrayLiteral.h"
#include "Visitor.h"
#include "Environment.h"

NS_LAN_BEGIN
const std::string ArrayLiteral::TREE_ID = "ArrayLiteral";

ArrayLiteral::ArrayLiteral()
{
	ASTree::init(TREE_ID);
}

ArrayLiteral::ArrayLiteral(const std::vector<ASTree*>& list)
	:ASTList(list)
{
}

void ArrayLiteral::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END