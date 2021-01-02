#ifndef __Stone_Visitor_H__
#define __Stone_Visitor_H__

#include "StoneMarcos.h"
#include "Value.h"

NS_LAN_BEGIN

class Environment;
class ASTree;
class ASTList;
class ASTLeaf;
class NumberLiteral;
class StringLiteral;
class Name;
class NegativeExpr;
class BinaryExpr;
class BlockStmnt;
class IfStmnt;
class WhileStmnt;

class PrimaryExpr;
class Postfix;
class Arguments;
class ParameterList;
class DefStmnt;
class ClosureStmnt;

class ArrayLiteral;
class ArrayRef;

class Visitor
{
public:
	virtual void visit(ASTree* t, Environment* env) = 0;
	virtual void visit(ASTList* t, Environment* env) = 0;
	virtual void visit(ASTLeaf* t, Environment* env) = 0;
	virtual void visit(NumberLiteral* t, Environment* env) = 0;
	virtual void visit(StringLiteral* t, Environment* env) = 0;
	virtual void visit(Name* t, Environment* env) = 0;
	virtual void visit(NegativeExpr* t, Environment* env) = 0;
	virtual void visit(BinaryExpr* t, Environment* env) = 0;
	virtual void visit(BlockStmnt* t, Environment* env) = 0;
	virtual void visit(IfStmnt* t, Environment* env) = 0;
	virtual void visit(WhileStmnt* t, Environment* env) = 0;
	
	//函数相关
	virtual void visit(PrimaryExpr* t, Environment* env) = 0;
	virtual void visit(Postfix* t, Environment* env) = 0;
	virtual void visit(Arguments* t, Environment* env) = 0;
	virtual void visit(DefStmnt* t, Environment* env) = 0;

	//闭包函数
	virtual void visit(ClosureStmnt* t, Environment* env) = 0;

	//数组
	virtual void visit(ArrayLiteral* t, Environment* env) = 0;
	virtual void visit(ArrayRef* t, Environment* env) = 0;
};

NS_LAN_END
#endif