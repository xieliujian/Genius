
/*
Author : Xieliujian
Data : 2016.9.11
Description : 材质的d3d9的具体实现
*/

#ifndef __D3D9Texture_h__
#define __D3D9Texture_h__

#include "Prerequest.h"
#include "Texture.h"

NAMESPACEBEGIN(Genius)

class D3D9Texture : public Texture
{
public:
	D3D9Texture();
	~D3D9Texture();
};

NAMESPACEEND

#endif