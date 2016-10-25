

/*
Author : Xieliujian
Data : 2016.9.12
Description : 编辑器基类
*/

#ifndef __GeniusEditor_h__
#define __GeniusEditor_h__

#include "Prerequest.h"
#include "Singleton.h"
#include "D3D9RenderSystem.h"

using namespace Genius;

NAMESPACEBEGIN(Editor)

class BaseEditor : public Singleton<BaseEditor>
{
public:
	BaseEditor();
	~BaseEditor();

	// 创建
	void Create(int hwnd);

	// 渲染
	void Render();
protected:
	int mhWnd;
	RenderSystem *mRenderSystem;
};

NAMESPACEEND

#endif