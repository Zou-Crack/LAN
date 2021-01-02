#ifndef __Stone_ASTLeaf_H__
#define __Stone_ASTLeaf_H__

#include <vector>
#include <string>

#include "ASTTree.h"

NS_LAN_BEGIN
class Token;
class Visitor;
class Environment;

/**
 * 叶子节点，在抽象语法树中只有ASTLeaf及其子类才有Token对象
*/
class ASTLeaf : public ASTree 
{
public:
	static const std::string TREE_ID;
public:
	ASTLeaf(Token* token);
	virtual ~ASTLeaf();
	//获取token
	Token* getToken() const;

	virtual void accept(Visitor* v, Environment* env);
	virtual ASTree* getChild(unsigned int i) const;
	virtual int getNumChildren() const;
	virtual std::string getLocation() const;

	virtual std::vector<ASTree*>::iterator begin();
	virtual std::vector<ASTree*>::iterator end();
	virtual std::string toString() const;
private:
	static std::vector<ASTree*> empty;
private:
	Token* _token;
};

NS_LAN_END
#endif