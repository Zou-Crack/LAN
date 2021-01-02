#ifndef __Stone_NumberLiteral_H__
#define __Stone_NumberLiteral_H__

#include <string>

#include "ASTLeaf.h"
NS_LAN_BEGIN

class Token;
class Visitor;
class Environment;

class NumberLiteral : public ASTLeaf
{
public:
	static const std::string TREE_ID;
public:
	NumberLiteral(Token* token);
	//ªÒ»°÷µ
	int getValue() const;
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif