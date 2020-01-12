#include "hello.h"
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>
#include <iostream>
#include <windows.h>

using namespace std;

int a = 0;

hello::hello(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(setText()));
	connect(ui.BTN_ADD, SIGNAL(clicked()), this, SLOT(addMessage()));
	connect(ui.BTN_CLEAR, SIGNAL(clicked()), this, SLOT(clearText()));
}

void hello::setText()
{
	QString text = "wo xi huan luzihan!~";
	ui.EDI->setText((QStringLiteral("����ϲ��½�Ӻ�!~")));
}

void hello::clearText()
{
	ui.EDI->clear();
	ui.EDI->setFocus();
}

void hello::addMessage()
{
	//QMessageBox::information(this, QStringLiteral("�Ӵ"), QStringLiteral("����̫������!~������C++!~"));
	if (a % 2 == 0)
	{
		ui.EDI_MESSAGE->setAlignment(Qt::AlignRight);
		ui.EDI_MESSAGE->append(QStringLiteral("���!~"));
		a++;
	}
	else
	{
		ui.EDI_MESSAGE->setAlignment(Qt::AlignLeft);
		ui.EDI_MESSAGE->append(QStringLiteral("����!~"));
		a++;
	}
}
