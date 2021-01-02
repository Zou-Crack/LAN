#include "Name.h"
#include "Token.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string Name::TREE_ID = "Name";

Name::Name(Token* token)
	:ASTLeaf(token)
{
	ASTree::init(TREE_ID);
}

std::string Name::getName() const
{
	return getToken()->asString();
}

void Name::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END