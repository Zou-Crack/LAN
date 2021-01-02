#ifndef __Stone_Postfix_H__
#define __Stone_Postfix_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class Postfix : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	Postfix();
	Postfix(const std::vector<ASTree*>& list);
	virtual ~Postfix();
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif