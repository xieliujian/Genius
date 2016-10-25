#ifndef QTMODELEDITOR_H
#define QTMODELEDITOR_H

#include <QtWidgets/QMainWindow>
#include "ui_qtmodeleditor.h"
#include "Editor.h"
#include "ModelD3D9Widget.h"

using namespace Editor;

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
	BaseEditor *mEditor;
	ModelD3D9Widget *mModelWidget;
};

#endif // QTMODELEDITOR_H
