

#include "Editor.h"

template <> Editor::BaseEditor* Genius::Singleton<Editor::BaseEditor>::mInstance = NULL;

NAMESPACEBEGIN(Editor)

BaseEditor::BaseEditor()
{
	mhWnd = NULL;
	mRenderSystem = NULL;
}

BaseEditor::~BaseEditor()
{

}

void BaseEditor::Create(int hwnd)
{
	mhWnd = hwnd;
	mRenderSystem = new D3D9RenderSystem();
	mRenderSystem->Init(mhWnd, 800, 600);
}

void BaseEditor::Render()
{
	mRenderSystem->BeginFrame();
	mRenderSystem->Render();
	mRenderSystem->EndFrame();
}

NAMESPACEEND