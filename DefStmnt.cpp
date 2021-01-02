#include "DefStmnt.h"
#include "ASTLeaf.h"
#include "Token.h"
#include "ParameterList.h"
#include "BlockStmnt.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string DefStmnt::TREE_ID = "DefStmnt";

DefStmnt::DefStmnt(const std::vector<ASTree*>& list)
	:ASTList(list)
{
	ASTree::init(TREE_ID);
}

DefStmnt::~DefStmnt()
{
}

std::string DefStmnt::getName() const
{
	return static_cast<ASTLeaf*>(getChild(0))->getToken()->asString();
}

ParameterList* DefStmnt::getParameters() const
{
	return static_cast<ParameterList*>(getChild(1));
}

BlockStmnt* DefStmnt::getBody() const
{
	return static_cast<BlockStmnt*>(getChild(2));
}

void DefStmnt::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

std::string DefStmnt::toString() const
{
	std::stringstream in;
	in << "(def " << getName() << " ";
	in << getParameters()->toString() << " ";
	in << getBody()->toString() << ")";

	return in.str();
}
NS_LAN_END