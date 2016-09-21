#ifndef QTMODELEDITOR_H
#define QTMODELEDITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_qtmodeleditor.h"

class QtModelEditor : public QMainWindow
{
	Q_OBJECT

public:
	QtModelEditor(QWidget *parent = 0);
	~QtModelEditor();

	void closeEvent(QCloseEvent *event);	// event ...
	void WriteSetting();
	void ReadSetting();
private:
	//Ui::QtModelEditorClass ui;
};

#endif // QTMODELEDITOR_H
