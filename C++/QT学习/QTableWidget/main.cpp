#include "studyqttable.h"
#include <QtWidgets/QApplication>
#include <QGridLayout>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	studyQtTable* w = new studyQtTable();

	w->show();
	return a.exec();
}
