#ifndef __Stone_ArrayParser_H__
#define __Stone_ArrayParser_H__

#include "ClosureParser.h"

NS_LAN_BEGIN

class Parser;

/**
 * �����������Ҫ��������������������ʹ���Լ������Ա���޸�
 * ����������� a = {1, "hello world"} �����������󳤶Ȳ��ɸı�
 * �����ʹ�� a[0]
 * ����ֵ�ĸı� a[0] = 3
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