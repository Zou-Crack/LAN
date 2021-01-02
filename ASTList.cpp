#include "ASTList.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string ASTList::TREE_ID = "ASTList";

ASTList::ASTList()
{
	ASTree::init(TREE_ID);
}

ASTList::ASTList(const std::vector<ASTree*>& list) 
{
	ASTree::init(TREE_ID);
	for (auto it = list.begin(); it != list.end(); it++)
	{
		auto t = *it;
		t->retain();
		_children.push_back(t);
	}
}

ASTList::~ASTList() 
{
	auto it = _children.begin();

	while (it != _children.end())
	{
		auto t = *it;
		t->release();

		it = _children.erase(it);
	}
}

void ASTList::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

ASTree* ASTList::getChild(unsigned int i) const
{
	return _children.at(i);
}

int ASTList::getNumChildren() const
{
	return _children.size();
}

std::string ASTList::getLocation() const
{
	std::string str;
	for (ASTree* t : _children) 
	{
		str = t->getLocation();

		if (!str.empty())
			break;
	}
	return str;
}

std::vector<ASTree*>::iterator ASTList::begin()
{
	return _children.begin();
}

std::vector<ASTree*>::iterator ASTList::end()
{
	return _children.end();
}

std::string ASTList::toString() const
{
	std::stringstream buffer;

	buffer << "(";
	std::string sep = "";

	for (auto it = _children.begin(); it != _children.end(); it++)
	{
		buffer << sep;
		sep = " ";
		buffer << (*it)->toString();
	}
	buffer << ")";
	return buffer.str();
}
NS_LAN_END