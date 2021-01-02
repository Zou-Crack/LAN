#ifndef __Stone_BinaryExpr_H__
#define __Stone_BinaryExpr_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class ASTLeaf;
class Visitor;
class Environment;

class BinaryExpr : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	BinaryExpr(const std::vector<ASTree*>& list);
	BinaryExpr(ASTree* left, ASTLeaf* op, ASTree* right);
	virtual ~BinaryExpr();
public:
	virtual void accept(Visitor* v, Environment* env);

	//获取左操作树
	ASTree* getLeft() const;
	//获取操作符
	std::string getOperator() const;
	//获取右操作树
	ASTree* getRight() const;
};

NS_LAN_END
#endif
