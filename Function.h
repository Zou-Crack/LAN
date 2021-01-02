#ifndef __Stone_Function_H__
#define __Stone_Function_H__

#include <string>

#include "StObject.h"

NS_LAN_BEGIN

class ParameterList;
class BlockStmnt;
class Environment;
class Visitor;

class Function: public Object
{
public:
	Function(Environment* env);
	~Function();
	Environment* getEnvironment() const;
	//基于本环境创建环境
	Environment* makeEnv();
public:
	//获取参数个数
	virtual unsigned int getParamSize() const = 0;
	//获取参数名
	virtual std::string getParamName(unsigned index) const = 0;
	//执行函数
	virtual void execute(Visitor* v, Environment* env) = 0;
protected:
	Environment* _env;
};
NS_LAN_END
#endif // !__Stone_Function_H__
