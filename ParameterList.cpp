#include "ParameterList.h"
#include "ASTLeaf.h"
#include "Token.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string ParameterList::TREE_ID = "ParameterList";

ParameterList::ParameterList()
{
	ASTree::init(TREE_ID);
}

ParameterList::ParameterList(const std::vector<ASTree*>& list)
	:ASTList(list)
{
}

ParameterList::~ParameterList()
{
}
	
const std::string ParameterList::getName(unsigned &i) const
{
	return static_cast<ASTLeaf*>(getChild(i))->getToken()->asString();
}

int ParameterList::getSize() const
{
	return getNumChildren();
}

void ParameterList::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

NS_LAN_END