#ifndef __ASTree_H__
#define __ASTree_H__

#include <string>
#include <vector>

#include "STObject.h"

NS_LAN_BEGIN

class Visitor;
class Environment;

/*抽象语法树的节点基类*/
class ASTree: public Object
{
public:
	static const std::string TREE_ID;
public:
	ASTree();
	virtual ~ASTree();
	bool init(const std::string& id);
	const std::string& getTreeID() const { return _treeID; }
public:
	virtual void accept(Visitor* v, Environment* env);
	virtual ASTree* getChild(unsigned int i) const = 0;
	virtual int getNumChildren() const = 0;
	virtual std::string getLocation() const = 0;
	virtual std::vector<ASTree*>::iterator begin() = 0;
	virtual std::vector<ASTree*>::iterator end() = 0;
	virtual std::string toString() const = 0;
protected:
	std::string _treeID;
};
NS_LAN_END
#endif
