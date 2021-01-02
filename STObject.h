#ifndef __Stone_Object_H__
#define __Stone_Object_H__

#include "StoneMarcos.h"

NS_LAN_BEGIN

class AutoreleasePool;

//所有类的基类
class Object
{
public:
	bool init();
	Object();
	virtual ~Object();
	//保留
	void retain();
	//释放
	void release(bool force = false);
	//自动释放
	Object*autorelease();
	//获得引用数量
	unsigned int getReferenceCount() const { return _referenceCount; }
	//是否交给释放池
	bool isManaged() const { return _managed; }

	bool isLock() const { return _lock; }
	void setLock(bool lock) { _lock = lock; }
	//友元
	friend class AutoreleasePool;
protected:
	//引用计数器
	unsigned int _referenceCount;
	//是否由内存管理器管理
	bool _managed;
	//锁定 如果锁定，则retain release不会改变计数。但如果交给管理器，还是会释放
	bool _lock;
};
NS_LAN_END
#endif