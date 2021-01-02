#ifndef __Stone_NullStmnt_H__
#define __Stone_NullStmnt_H__

#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class NullStmnt : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	NullStmnt();
};


NS_LAN_END
#endif