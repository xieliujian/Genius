
/*
Author : Xieliujian
Data : 2016.9.12
Description : d3d9µÄäÖÈ¾´°¿Ú
*/

#ifndef __QD3D9Widget_h__
#define __QD3D9Widget_h__

#include "Prerequest.h"
#include <QWidget>
#include <QTimer>

class QD3D9Widget : public QWidget
{
	Q_OBJECT
public:
	QD3D9Widget(QWidget *parent);
	virtual ~QD3D9Widget();
public slots:
	void Idle();
protected:
	virtual void RenderScene(){}

	// event
	QPaintEngine* paintEngine() const { return 0; }	// ÔÊĞídxäÖÈ¾

	QTimer mTimer;
	QPoint mCurMousePt;
};

#endif

