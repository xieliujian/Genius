#include "qtmodeleditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtModelEditor w;
	w.show();
	return a.exec();
}
