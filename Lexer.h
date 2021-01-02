#ifndef __Stone_Lexer_H__
#define __Stone_Lexer_H__
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>

#include "StoneMarcos.h"

NS_LAN_BEGIN
//一行的最大字符个数
#define MAX_LENGTH 256

class Token;
class Lexer
{
public:
	static std::string REGEX_POT;
public:
	Lexer(const char* buffer);
	~Lexer();
	Token* read();
	Token* peek(int i);

protected:
	//读取行
	void readLine();
	//添加token
	void addToken(int lineNo, std::cmatch& matcher);
	//遍历字符串，去掉一些字符
	std::string toStringLiteral(const std::string& s);
private:
	bool fillQueue(unsigned int i);
private:
	//c++的正则匹配类
	std::regex _pattern;
	//保存字符串
	std::stringstream _reader;
	bool _hasMore;
	//当前行
	int _lineNo;
	std::vector<Token*> _queue;
};

NS_LAN_END
#endif
