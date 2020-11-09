#include "studyqtlistview.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	studylistview* listview = new studylistview();

	listview->show();

	return a.exec();
}
