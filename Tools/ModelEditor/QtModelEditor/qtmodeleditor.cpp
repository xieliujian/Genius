#include "qtmodeleditor.h"

QtModelEditor::QtModelEditor(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	ReadSetting();
}

QtModelEditor::~QtModelEditor()
{

}

void QtModelEditor::closeEvent(QCloseEvent *event)
{

}

void QtModelEditor::WriteSetting()
{

}

void QtModelEditor::ReadSetting()
{
	QMainWindow::setWindowState(Qt::WindowMaximized);
}
