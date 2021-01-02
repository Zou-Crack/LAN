#ifndef __Stone_ParameterList_H__
#define __Stone_ParameterList_H__

#include <vector>
#include <string>

#include "ASTList.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

class ParameterList : public ASTList
{
public:
	static const std::string TREE_ID;
public:
	ParameterList();
	ParameterList(const std::vector<ASTree*>& list);
	virtual ~ParameterList();
	
	const std::string getName(unsigned &i) const;
	int getSize() const;
public:
	virtual void accept(Visitor* v, Environment* env);
};
NS_LAN_END
#endif