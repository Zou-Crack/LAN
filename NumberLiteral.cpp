#include "NumberLiteral.h"
#include "Token.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string NumberLiteral::TREE_ID = "NumberLiteral";

NumberLiteral::NumberLiteral(Token* token)
	:ASTLeaf(token)
{
	ASTree::init(TREE_ID);
}

int NumberLiteral::getValue() const
{
	return getToken()->asInt();
}

void NumberLiteral::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

NS_LAN_END