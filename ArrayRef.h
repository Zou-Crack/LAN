#ifndef __Stone_ArrayRef_H__
#define __Stone_ArrayRef_H__

#include <string>
#include <vector>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

/*
	用于数组的使用，即获得数组对应的元素
*/
class ArrayRef : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	ArrayRef(ASTree* t);
	ArrayRef(const std::vector<ASTree*>& list);
	ASTree* getIndex() const;
public:
	virtual void accept(Visitor* v, Environment* env);
	virtual std::string toString() const;
};
NS_LAN_END
#endif