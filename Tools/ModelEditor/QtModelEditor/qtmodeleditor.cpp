
#include "qtmodeleditor.h"

QtModelEditor::QtModelEditor(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	mEditor = new BaseEditor();
	mModelWidget = new ModelD3D9Widget(parent);
	setCentralWidget(mModelWidget);
	ReadSetting();	

	mEditor->Create(mModelWidget->winId());
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
