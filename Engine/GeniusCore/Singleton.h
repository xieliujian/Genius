

/*
Author : Xieliujian
Data : 2016.9.12
Description : µ¥¼þÀà
*/

#ifndef __Singleton_h__
#define __Singleton_h__

#include "Prerequest.h"

NAMESPACEBEGIN(Genius)

template <class T> class Singleton
{
public:
	Singleton()
	{
		mInstance = static_cast<T*>(this);
	}

	~Singleton()
	{
		mInstance = NULL;
	}

	static T* GetInstancePtr()
	{
		return mInstance;
	}

	static T& GetInstance()
	{
		return *mInstance;
	}
protected:
	static T *mInstance;
};

NAMESPACEEND

#endif