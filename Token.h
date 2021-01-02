#ifndef __Stone_Token_H__
#define __Stone_Token_H__

#include <string>

#include "StoneMarcos.h"

NS_LAN_BEGIN
/*
	单词，有标识符、数字和字符串
*/
class Token
{
public:
	enum class Type
	{
		None,
		Identifier,//标识符
		Number,	   //数字
		String,	   //字符串
	};
public:
	Token(int line);
	~Token();
	//获取行号
	int getLineNumber() const { return _line; }
	//获取单词的类型
	Type getType() const { return _type; }
	//获取文本
	virtual std::string asString() const { return ""; }
	//获取数字
	virtual int asInt() const { return 0; }
protected:
	int _line;
	Type _type;
public:
	//end of file
	static Token* const TOKEN_EOF;
	//end of line
	static const char* TOKEN_EOL;
};

/*
	NumToken 数字
*/
class NumToken: public Token
{
public:
	NumToken(int line, int value);
	virtual std::string asString() const;
	virtual int asInt() const;
private:
	int _value;
};

/*
	标识符
*/
class IdToken : public Token
{
public:
	IdToken(int line, const std::string& id);
	virtual std::string asString() const;
private:
	std::string _text;
};

/*
	字符串StrToken
*/
class StrToken : public Token
{
public:
	StrToken(int line, const std::string& str);
	virtual std::string asString() const;
private:
	std::string _literal;
};
NS_LAN_END
#endif
