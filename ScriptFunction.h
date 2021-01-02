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
	//��ȡ��������
	virtual unsigned int getParamSize() const;
	//��ȡ������
	virtual std::string getParamName(unsigned index) const;
	//ִ�к���
	virtual void execute(Visitor* v, Environment* env);
private:
	ParameterList* _parameters;
	BlockStmnt* _body;
};
NS_LAN_END
#endif