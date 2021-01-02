#ifndef __Stone_BlockStmnt_H__
#define __Stone_BlockStmnt_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class BlockStmnt : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	BlockStmnt(const std::vector<ASTree*>& list);
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif