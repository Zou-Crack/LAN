#ifndef __Stone_IfStmnt_H__
#define __Stone_IfStmnt_H__

#include <vector>
#include <string>
#include <sstream>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class IfStmnt : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	IfStmnt(const std::vector<ASTree*>& list);

	ASTree* getCondition(unsigned int i) const;
	ASTree* getThenBlock(unsigned int i) const;
	ASTree* getElseBlock() const;
	unsigned int getIfNumber() const;
public:
	virtual void accept(Visitor* v, Environment* env);
	virtual std::string toString() const;
};
NS_LAN_END
#endif