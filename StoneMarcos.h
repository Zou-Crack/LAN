#ifndef __Stone_StoneMacros_H__
#define __Stone_StoneMacros_H__

#define NS_LAN_BEGIN namespace Stone{
#define NS_LAN_END }

#define USING_NS_LAN using namespace Stone;

#define STONE_SAFE_DELETE(p) do{ if(p) delete p; p=nullptr;}while(0)

#endif