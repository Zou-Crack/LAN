#ifndef __Stone_ArrayParser_H__
#define __Stone_ArrayParser_H__

#include "ClosureParser.h"

NS_LAN_BEGIN

class Parser;

/**
 * 数组解析类主要包含数组的声明和数组的使用以及数组成员的修改
 * 数组的声明： a = {1, "hello world"} 函数在声明后长度不可改变
 * 数组的使用 a[0]
 * 数组值的改变 a[0] = 3
*/
class ArrayParser : public ClosureParser
{
public:
	ArrayParser();
	virtual ~ArrayParser();
private:
	bool init();
protected:
	Parser* _elements;
};
NS_LAN_END
#endif