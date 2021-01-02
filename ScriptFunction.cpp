#include "ScriptFunction.h"
#include "ParameterList.h"
#include "BlockStmnt.h"

NS_LAN_BEGIN

ScriptFunction::ScriptFunction(ParameterList* parameters, BlockStmnt* block, Environment* env)
	:Function(env)
	,_parameters(parameters)
	,_body(block)
{
	_parameters->retain();
	_body->retain();
}

ScriptFunction::~ScriptFunction()
{
	_parameters->release();
	_body->release();
}

unsigned int ScriptFunction::getParamSize() const
{
	return _parameters->getSize();
}

std::string ScriptFunction::getParamName(unsigned index) const
{
	return _parameters->getName(index);
}

void ScriptFunction::execute(Visitor* v, Environment* env)
{
	_body->accept(v, env);
}
NS_LAN_END