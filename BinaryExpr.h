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

	//��ȡ�������
	ASTree* getLeft() const;
	//��ȡ������
	std::string getOperator() const;
	//��ȡ�Ҳ�����
	ASTree* getRight() const;
};

NS_LAN_END
#endif