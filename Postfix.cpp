#include "Postfix.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string Postfix::TREE_ID = "Postfix";

Postfix::Postfix()
{
	ASTree::init(TREE_ID);
}

Postfix::Postfix(const std::vector<ASTree*>& list)
	:ASTList(list)
{
}

Postfix::~Postfix()
{
}

void Postfix::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END