

/*
Author : Xieliujian
Data : 2016.9.12
Description : ¹Ç÷ÀÀà
*/

#ifndef __Skeleton_h__
#define __Skeleton_h__

#include "Prerequest.h"
#include "Bone.h"

NAMESPACEBEGIN(Genius)

class Skeleton
{
public:
	Skeleton();
	~Skeleton();

private:
	typedef std::vector<Bone> BoneVec;
	BoneVec mBoneVec;
};

NAMESPACEEND

#endif