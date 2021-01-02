#include "IfStmnt.h"
#include "Visitor.h"

NS_LAN_BEGIN

const std::string IfStmnt::TREE_ID = "IfStmnt";

IfStmnt::IfStmnt(const std::vector<ASTree*>& list)
{
	ASTree::init(TREE_ID);

	for (ASTree* t : list)
	{
		if (t->getTreeID() == ASTList::TREE_ID)
		{
			ASTList* children = static_cast<ASTList*>(t);

			//Î²²åÈë
			_children.insert(_children.end(), children->begin(), children->end());
		}
		else
		{
			_children.push_back(t);
		}
	}
}

ASTree* IfStmnt::getCondition(unsigned int i) const
{
	return getChild(i * 2);
}

ASTree* IfStmnt::getThenBlock(unsigned int i) const
{
	return getChild(i * 2 + 1);
}

ASTree* IfStmnt::getElseBlock() const
{
	auto size = this->getNumChildren();
	if (size % 2 == 0)
		return nullptr;
	else
		return getChild(size - 1);
}

unsigned int IfStmnt::getIfNumber() const
{
	return getNumChildren() / 2;
}

void IfStmnt::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

std::string IfStmnt::toString() const
{
	std::stringstream in;
	unsigned index = 0;
	in << "(if ";
	in << getCondition(index)->toString();
	in << " ";
	in << getThenBlock(index)->toString();

	for (index = 1; index < this->getIfNumber(); index++)
	{
		in << "(elseif ";
		in << getCondition(index)->toString();
		in << " ";
		in << getThenBlock(index)->toString();
	}

	if (getElseBlock() != nullptr)
		in << " else" << getElseBlock()->toString();
	in << ")";

	return in.str();
}

NS_LAN_END
