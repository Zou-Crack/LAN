#ifndef __Stone_ClosureParser_H__
#define __Stone_ClosureParser_H__

#include "FuncParser.h"

NS_LAN_BEGIN

class ClosureParser : public FuncParser
{
public:
	ClosureParser();
private:
	bool init();
};
NS_LAN_END
#endif // !__Stone_ClosureParser_H__
