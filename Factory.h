#ifndef __Stone_Factory_H__
#define __Stone_Factory_H__

#include <vector>
#include <string>

#include "StoneMarcos.h"

NS_LAN_BEGIN

class Token;
class ASTree;
class ASTList;
class ASTLeaf;

class Factory
{
public:
	static ASTree* make(const std::string& name, const std::vector<ASTree*>& list);
	static ASTLeaf* make(const std::string& name, Token* token);
};
NS_LAN_END
#endif