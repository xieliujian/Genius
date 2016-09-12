
/*
Author : Xieliujian
Data : 2016.9.11
Description : 渲染系统的D3D9实现
*/

#ifndef _D3D9RenderSystem_h_
#define _D3D9RenderSystem_h_

#include "D3D9Prerequest.h"
#include "RenderSystem.h"

NAMESPACEBEGIN(Genius)

class D3D9RenderSystem : public RenderSystem
{
public:
	D3D9RenderSystem();
	~D3D9RenderSystem();

	// 创建驱动
	virtual void CreateDevice(int hwnd, int width, int height);

	// 帧渲染开始
	virtual void BeginFrame();

	// 帧渲染结束
	virtual void EndFrame();

	// 渲染
	virtual void Render();

	// 设置视口
	virtual void SetViewport(int left, int top, int width, int height);

private:
	IDirect3D9 *mpD3D;
	IDirect3DDevice9 *mpDevice;
	D3DVIEWPORT9 mViewport;
	D3DPRESENT_PARAMETERS mD3Dpp;
};

NAMESPACEEND

#endif