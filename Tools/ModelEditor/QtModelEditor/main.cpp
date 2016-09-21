
#include "qtmodeleditor.h"
#include <QtWidgets/QApplication>
#include <QtGui>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 解决在win7上中文显示为乱码的问题
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));

	QtModelEditor w;
	w.show();

	return a.exec();
}
