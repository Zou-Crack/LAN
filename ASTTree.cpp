#include "ASTTree.h"
#include "Visitor.h"
#include "Environment.h"

NS_LAN_BEGIN

const std::string ASTree::TREE_ID = "ASTree";

ASTree::ASTree()
{
}

ASTree::~ASTree()
{
}

void ASTree::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

bool ASTree::init(const std::string& id)
{
	_treeID = id;
	return true;
}

NS_LAN_END