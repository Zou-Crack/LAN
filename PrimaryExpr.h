#ifndef __Stone_PrimaryExpr_H__
#define __Stone_PrimaryExpr_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class PrimaryExpr : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	PrimaryExpr(const std::vector<ASTree*>& list);
	virtual ~PrimaryExpr();
public:
	virtual void accept(Visitor* v, Environment* env);

};
NS_LAN_END
#endif