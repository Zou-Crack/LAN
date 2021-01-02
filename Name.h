#ifndef __Stone_Name_H__
#define __Stone_Name_H__

#include <string>

#include "ASTLeaf.h"

NS_LAN_BEGIN

class Token;
class Visitor;
class Environment;

class Name : public ASTLeaf
{
public:
	static const std::string TREE_ID;
public:
	Name(Token* token);

	std::string getName() const;
public:
	virtual void accept(Visitor* v, Environment* env);
};

NS_LAN_END
#endif