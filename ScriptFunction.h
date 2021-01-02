#ifndef __Stone_ScriptFunction_H__
#define __Stone_ScriptFunction_H__

#include "Function.h"

NS_LAN_BEGIN

class ParameterList;
class BlockStmnt;
class Environment;

class ScriptFunction : public Function
{
public:
	explicit ScriptFunction(ParameterList* parameters, BlockStmnt* block, Environment* env);
	virtual ~ScriptFunction();
public:
	//获取参数个数
	virtual unsigned int getParamSize() const;
	//获取参数名
	virtual std::string getParamName(unsigned index) const;
	//执行函数
	virtual void execute(Visitor* v, Environment* env);
private:
	ParameterList* _parameters;
	BlockStmnt* _body;
};
NS_LAN_END
#endif