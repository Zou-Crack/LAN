#ifndef __Stone_ArrayLiteral_H__
#define __Stone_ArrayLiteral_H__

#include <string>
#include <vector>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

/*
	用于数组的声明, 如 a = [1, "2", "hello"]
*/
class ArrayLiteral : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	ArrayLiteral();
	ArrayLiteral(const std::vector<ASTree*>& list);
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif