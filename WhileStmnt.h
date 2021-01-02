#ifndef __Stone_WhileStmnt_H__
#define __Stone_WhileStmnt_H__

#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class WhileStmnt : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	WhileStmnt(const std::vector<ASTree*>& list);

	ASTree* getCondition() const;
	ASTree* getBody() const;

public:
	virtual void accept(Visitor* v, Environment* env);
	virtual std::string toString() const;
};
NS_LAN_END
#endif