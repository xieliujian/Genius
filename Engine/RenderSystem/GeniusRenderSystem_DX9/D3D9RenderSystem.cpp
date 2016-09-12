

#include "D3D9RenderSystem.h"

NAMESPACEBEGIN(Genius)

D3D9RenderSystem::D3D9RenderSystem()
{
	mpD3D = NULL;
	mpDevice = NULL;
}

D3D9RenderSystem::~D3D9RenderSystem()
{

}

void D3D9RenderSystem::Init(int hwnd, int width, int height)
{
	mpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	CreateDevice(hwnd, width, height);
	SetViewport(0, 0, width, height);
}

void D3D9RenderSystem::CreateDevice(int hwnd, int width, int height)
{
	D3DPRESENT_PARAMETERS param;
	ZeroMemory(&param, sizeof(param));
	param.Windowed = TRUE;
	param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	param.BackBufferFormat = D3DFMT_X8R8G8B8;
	param.BackBufferWidth = width;
	param.BackBufferHeight = height;
	param.hDeviceWindow = (HWND)hwnd;
	param.BackBufferCount = 1;
	param.MultiSampleType = D3DMULTISAMPLE_NONE;
	param.MultiSampleQuality = 0;
	param.EnableAutoDepthStencil = TRUE;
	param.AutoDepthStencilFormat = D3DFMT_D24S8;
	param.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	//m_D3Dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE; 用这个移动的时候屏幕上会有条线
	// 而且帧率足够的情况下也只有60帧
	param.FullScreen_RefreshRateInHz = 0;
	mD3Dpp = param;

	DWORD BehaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;

	// Hardware Device
	HRESULT hr = mpD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, (HWND)hwnd, BehaviorFlags, &param, &mpDevice);

}

void D3D9RenderSystem::BeginFrame()
{
	if (mpDevice == NULL) 
		return;

	HRESULT hr;
	if (FAILED(hr = mpDevice->BeginScene()))
	{
		return;
	}

	mpDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_COLORVALUE(0.0f, 0.0f, 0.0f, 0.0f), 1.0f, 0);
	mpDevice->SetViewport(&mViewport);

	mpDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	mpDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	mpDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
	mpDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
}

void D3D9RenderSystem::EndFrame()
{
	if (mpDevice == NULL) 
		return;

	HRESULT hr;
	if (FAILED(hr = mpDevice->EndScene()))
		return;

	mpDevice->Present(0, 0, 0, 0);

}

void D3D9RenderSystem::Render()
{

}

void D3D9RenderSystem::SetViewport(int left, int top, int width, int height)
{
	if (mpDevice == NULL)
		return;

	mViewport.X = left;
	mViewport.Y = top;
	mViewport.Width = width;
	mViewport.Height = height;
	mViewport.MinZ = 0.0f;
	mViewport.MaxZ = 1.0f;
}

NAMESPACEEND