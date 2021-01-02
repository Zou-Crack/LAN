#ifndef __Stone_BasicParser_H__
#define __Stone_BasicParser_H__

#include <string>
#include <unordered_set>

#include "StoneMarcos.h"
NS_LAN_BEGIN

class ASTree;
class Parser;
class Lexer;
class Operators;

/**
 * 基础解析类，包含了基础的语法树生成结构，目前包含了if  elif else | while 
 * 和一般的表达式
*/
class BasicParser
{
public:
	BasicParser();
	virtual ~BasicParser();

	ASTree* parse(Lexer* lexer);
protected:
	bool init();
protected:
	//操作符
	Operators* _operators;
	std::unordered_set<std::string>* _reserved;

	Parser* _primary;
	Parser* _factor;
	Parser* _expr;
	Parser* _block;
	Parser* _simple;
	Parser* _statement;
	Parser* _program;
};
NS_LAN_END
#endif