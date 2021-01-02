#ifndef __Stone_NestedEnv_H__
#define __Stone_NestedEnv_H__

#include <unordered_map>

#include "Environment.h"

NS_LAN_BEGIN

class NestedEnv : public Environment
{
public:
	NestedEnv();
	NestedEnv(Environment* env);
	virtual ~NestedEnv();

	void setOuter(Environment* env);
	
	//查找包含该变量名字所对应的环境并返回该环境
	Environment* where(const std::string& name);

	//直接在本环境中添加/更新变量
	virtual void putNew(const std::string& name, const Value& value);
	virtual void put(const std::string& name, const Value& value);
	virtual const Value* get(const std::string& name) const;
	virtual Value* get(const std::string& name);
private:
	std::unordered_map<std::string, Value> _values;
	Environment* _outer;
};
NS_LAN_END
#endif