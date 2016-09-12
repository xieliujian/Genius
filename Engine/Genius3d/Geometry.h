

/*
Author : Xieliujian
Data : 2016.9.12
Description : º∏∫Œ¿‡
*/

#ifndef __Geometry_h__
#define __Geometry_h__

#include "Prerequest.h"
#include "GeoChunk.h"

NAMESPACEBEGIN(Genius)

class Geometry
{
public:
	Geometry();
	~Geometry();

private:
	typedef std::vector<GeoChunk> ChunkVec;
	ChunkVec mChunkVec;
};

NAMESPACEEND

#endif