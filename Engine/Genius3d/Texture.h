

/*
Author : Xieliujian
Data : 2016.9.11
Description : 基础材质
*/

#ifndef __Texture_h__
#define __Texture_h__

#include "Prerequest.h"

NAMESPACEBEGIN(Genius)

class Texture
{
public:
	Texture();
	~Texture();

private:
	int mWidth;			// 材质宽度
	int mHeight;		// 材质高度
};

NAMESPACEEND

#endif