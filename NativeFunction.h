#ifndef __Stone_NativeFunction_H__
#define __Stone_NativeFunction_H__

#include <vector>
#include <string>
#include <functional>

#include "Function.h"
#include "Value.h"

NS_LAN_BEGIN

class Environment;
class Visitor;
typedef std::function<Value(Environment*)> nativeFunc;

class NativeFunction : public Function
{
public:
	NativeFunction(const char* params[], int len, const nativeFunc& callback, Environment* env);
	virtual ~NativeFunction();
public:
	//获取参数个数
	virtual unsigned int getParamSize() const;
	//获取参数名
	virtual std::string getParamName(unsigned index) const;
	//执行函数
	virtual void execute(Visitor* v, Environment* env);
private:
	std::vector<std::string> _parameters;
	int _paramNum;
	nativeFunc _callback;
};
NS_LAN_END
#endif
