

#include "QD3D9Widget.h"

QD3D9Widget::QD3D9Widget(QWidget *parent)
{
	QWidget::setAttribute(Qt::WA_PaintOnScreen); // 允许DX渲染 ...
	setFocusPolicy(Qt::WheelFocus); // 允许按键时间 ...
	setMouseTracking(true); // 允许鼠标移动 ...

	mTimer.setInterval(0);
	QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(Idle()));
	mTimer.start();
}

QD3D9Widget::~QD3D9Widget()
{

}

void QD3D9Widget::Idle()
{
	RenderScene();
}