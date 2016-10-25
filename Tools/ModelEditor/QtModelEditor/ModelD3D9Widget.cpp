

#include "ModelD3D9Widget.h"
#include "Editor.h"

using namespace Editor;

ModelD3D9Widget::ModelD3D9Widget(QWidget *parent)
:QD3D9Widget(parent)
{

}

ModelD3D9Widget::~ModelD3D9Widget()
{

}

void ModelD3D9Widget::RenderScene()
{
	BaseEditor::GetInstance().Render();
}