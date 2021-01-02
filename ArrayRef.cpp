#include "ArrayRef.h"
#include "Visitor.h"
#include "Environment.h"

NS_LAN_BEGIN
const std::string ArrayRef::TREE_ID = "ArrayRef";

ArrayRef::ArrayRef(ASTree* t)
{
	_children.push_back(t);
	ASTree::init(TREE_ID);
}

ArrayRef::ArrayRef(const std::vector<ASTree*>& list)
	:ASTList(list)
{
}

ASTree* ArrayRef::getIndex() const
{
	return this->getChild(0);
}

void ArrayRef::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

std::string ArrayRef::toString() const
{
	return "[" + getIndex()->toString() + "]";
}
NS_LAN_END