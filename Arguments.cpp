#include "Arguments.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string Arguments::TREE_ID = "Arguments";

Arguments::Arguments()
{
	ASTree::init(TREE_ID);
}

Arguments::Arguments(const std::vector<ASTree*>& list)
	:Postfix(list)
{
	ASTree::init(TREE_ID);
}

Arguments::~Arguments()
{
}

unsigned Arguments::getSize() const
{
	return getNumChildren();
}

void Arguments::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}
NS_LAN_END