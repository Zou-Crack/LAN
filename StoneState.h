#ifndef __Stone_StoneState_H__
#define __Stone_StoneState_H__

#include <string>
#include <iostream>

#include "StoneMarcos.h"
#include "Value.h"
#include "Environment.h"

NS_LAN_BEGIN

class Lexer;
class NestedEnv;
class EvalVisitor;
class ArrayParser;

class StoneState
{
public:
	StoneState();
	~StoneState();

	bool init(const char* text);
	//执行脚本语句，并返回值
	Value* execute();
	//是否还存在语句
	bool hasNext();

	void putNative(const std::string& name, const nativeFunc& callback, const char** params, int len);
private:
	Lexer* _lexer;
	NestedEnv* _environment;
	EvalVisitor* _visitor;
	ArrayParser* _parser;
};
NS_LAN_END
#endif