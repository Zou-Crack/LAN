#include "NativeFunction.h"
#include "EvalVisitor.h"

NS_LAN_BEGIN

NativeFunction::NativeFunction(const char* params[], int len, const nativeFunc& callback, Environment* env)
	:Function(env)
	,_paramNum(len)
	,_callback(callback)
{
	int i = 0;
	while (i < len)
		_parameters.push_back(params[i++]);
}

NativeFunction::~NativeFunction()
{
}

unsigned int NativeFunction::getParamSize() const
{
	return _paramNum;
}

std::string NativeFunction::getParamName(unsigned index) const
{
	return _parameters[index];
}

void NativeFunction::execute(Visitor* v, Environment* env)
{
	Value value = _callback(env);
	static_cast<EvalVisitor*>(v)->setResult(value);
}
NS_LAN_END
