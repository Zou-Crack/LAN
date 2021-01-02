#include "ClosureStmnt.h"
#include "ASTLeaf.h"
#include "Token.h"
#include "ParameterList.h"
#include "BlockStmnt.h"
#include "Visitor.h"

NS_LAN_BEGIN
const std::string ClosureStmnt::TREE_ID = "ClosureStmnt";

ClosureStmnt::ClosureStmnt(const std::vector<ASTree*>& list)
	:ASTList(list)
{
	ASTree::init(TREE_ID);
}

ClosureStmnt::~ClosureStmnt()
{
}

ParameterList* ClosureStmnt::getParameters() const
{
	return static_cast<ParameterList*>(getChild(0));
}

BlockStmnt* ClosureStmnt::getBody() const
{
	return static_cast<BlockStmnt*>(getChild(1));
}

void ClosureStmnt::accept(Visitor* v, Environment* env)
{
	v->visit(this, env);
}

std::string ClosureStmnt::toString() const
{
	std::stringstream in;
	in << "(closure " << getParameters()->toString() << " ";
	in << getBody()->toString() << ")";

	return in.str();
}
NS_LAN_END