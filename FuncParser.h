#ifndef __Stone_FuncParser_H__
#define __Stone_FuncParser_H__

#include "BasicParser.h"

NS_LAN_BEGIN

class Parser;

class FuncParser : public BasicParser
{
public:
	FuncParser();
	virtual ~FuncParser();
protected:
	bool init();
protected:
	Parser* _param;
	Parser* _params;
	Parser* _paramList;
	Parser* _def;
	Parser* _args;
	Parser* _postfix;
};
NS_LAN_END
#endif