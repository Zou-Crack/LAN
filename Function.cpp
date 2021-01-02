#include "Function.h"
#include "Environment.h"
#include "NestedEnv.h"

NS_LAN_BEGIN
Function::Function(Environment* env)
	:_env(env)
{
	//引用该环境
	_env->retain();
}

Function::~Function()
{
	_env->release();
}

Environment* Function::getEnvironment() const
{
	return _env;
}

Environment* Function::makeEnv()
{
	//创建一个自动释放的环境
	auto env = new NestedEnv(_env);
	env->autorelease();
	return env;
}

NS_LAN_END