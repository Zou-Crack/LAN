#ifndef __Stone_NegativeExpr_H__
#define __Stone_NegativeExpr_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class ASTree;
class Visitor;
class Environment;

class NegativeExpr : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	NegativeExpr(ASTree* a);
	NegativeExpr(const std::vector<ASTree*>& list);

	//?
	ASTree* getOperand();
	std::string toString() const;
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif