#include "STObject.h"
#include "STAutoreleasePool.h"

NS_LAN_BEGIN
Object::Object()
	:_referenceCount(1)
	,_managed(false)
	,_lock(false)
{
}

Object::~Object() 
{
	//被自动释放管理器管理，调用内存管理器删除自己
	if (_managed)
	{
		AutoreleasePool::getInstance()->removeObject(this);
	}
}

void Object::retain()
{
	//未加锁才会添加引用
	if (!_lock)
	{
		_referenceCount++;
	}
}

void Object::release(bool force)
{
	//加锁且非强制，则退出
	if (_lock && !force)
		return;

	_referenceCount--;

	if (_referenceCount == 0)
		delete this;
}

Object* Object::autorelease()
{
	//不重复插入
	if (_managed == false)
	{
		//加入自动释放池中
		AutoreleasePool::getInstance()->addObject(this);
		_managed = true;
	}
	return this;
}

NS_LAN_END