#ifndef __Stone_AutoreleasePool_H__
#define __Stone_AutoreleasePool_H__

#include<vector>
#include <algorithm>

NS_LAN_BEGIN

class Object;

class AutoreleasePool
{
public:
	static AutoreleasePool* getInstance();
	static void purge();
protected:
	AutoreleasePool();
public:
	virtual ~AutoreleasePool();
	//insert dirfferent
	void addObject(Object* pObject);
	void removeObject(Object* pObject);
	//«Â¿Ì»›∆˜
	void clear();
private:
	std::vector<Object*> _managedObjects;
	static AutoreleasePool* _pInstance;
};
NS_LAN_END
#endif