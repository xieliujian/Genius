

#ifndef __ModelD3D9Widget_h__
#define __ModelD3D9Widget_h__

#include "QD3D9Widget.h"

class ModelD3D9Widget : public QD3D9Widget
{
	Q_OBJECT
public:
	ModelD3D9Widget(QWidget *parent);
	~ModelD3D9Widget();

	virtual void RenderScene();
};

#endif