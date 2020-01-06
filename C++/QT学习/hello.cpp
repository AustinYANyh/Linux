#include "hello.h"
#include<iostream>

using namespace std;

hello::hello(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(setText()));
}

void hello::setText()
{
	QString text = "wo xi huan luzihan!~";
	ui.EDI->setText(((text)));
	//ui.EDI->setText(tr(QString::fromLocal8Bit(text)));
}
