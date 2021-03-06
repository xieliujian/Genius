
/*
Author : Xieliujian
Data : 2016.9.11
Description : 渲染系统的基类
*/

#ifndef _RenderSystem_h_
#define _RenderSystem_h_

#include "Prerequest.h"

NAMESPACEBEGIN(Genius)

class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	// 创建驱动
	virtual void Init(int hwnd, int width, int height) = 0;

	// 帧渲染开始
	virtual void BeginFrame() = 0;

	// 帧渲染结束
	virtual void EndFrame() = 0;

	// 渲染
	virtual void Render() = 0;

	// 设置视口
	virtual void SetViewport(int left, int top, int width, int height) = 0;
};

NAMESPACEEND

#endif