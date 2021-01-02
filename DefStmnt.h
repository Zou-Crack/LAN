#ifndef __Stone_DefStmnt_H__
#define __Stone_DefStmnt_H__

#include <vector>
#include <string>
#include <sstream>

#include "ASTList.h"

NS_LAN_BEGIN

class ParameterList;
class BlockStmnt;
class Visitor;
class Environment;

class DefStmnt : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	DefStmnt(const std::vector<ASTree*>& list);
	virtual ~DefStmnt();

	//获取函数名字
	std::string getName() const;
	//获取函数参数列表
	ParameterList* getParameters() const;
	//获取函数体
	BlockStmnt* getBody() const;
public:
	virtual void accept(Visitor* v, Environment* env);
	virtual std::string toString() const;
};
NS_LAN_END
#endif
