#ifndef __ParseException_H__
#define __ParseException_H__

#include <string>
#include <exception>
#include <sstream>

#include "StoneMarcos.h"
#include "Token.h"

NS_LAN_BEGIN

class ParseException : public std::exception
{
public:
	ParseException(const std::string& msg)
		:_msg(msg)
	{
	}
	ParseException(Token* token)
		:ParseException("", token)
	{
	}

	ParseException(const std::string& msg, Token* token)
	{
		std::stringstream in;
		in << "syntax error around ";

		if (token == Token::TOKEN_EOF)
			in << "the last line";
		else
		{
			in << "\"";
			in << token->asString();
			in << "\" at line ";
			in << token->getLineNumber();
		}
		in << msg;
		_msg = in.str();
	}

	virtual const char* what() const
	{
		return _msg.c_str();
	}
private:
	std::string _msg;
};
NS_LAN_END
#endif