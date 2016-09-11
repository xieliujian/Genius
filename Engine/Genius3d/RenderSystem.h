
/*
Author : Xieliujian
Data : 2016.9.11
Description : 渲染系统的基类
*/

#ifndef _RenderSystem_h_
#define _RenderSystem_h_

class RenderSystem
{
public:
	RenderSystem();
	~RenderSystem();

	// 帧渲染开始
	virtual void BeginFrame() = 0;

	// 帧渲染结束
	virtual void EndFrame() = 0;

	// 渲染
	virtual void Render() = 0;
};

#endif