//设置执行字符集为utf8,解决程序运行时中文乱码
#pragma execution_character_set("utf-8")

#include "studyqttable.h"
#include <windows.h>

studyQtTable::studyQtTable(QWidget* parent)
	: QMainWindow(parent)
{
	ui->setupUi(this);
	

	//设置列数
	ui->tableWidget->setColumnCount(3);

	//设置表头不可点击
	ui->tableWidget->horizontalHeader()->setSectionsClickable(false);

	QStringList header;
	header.append(QString("排名"));
	header.append(QString("文件名"));
	header.append(QString("下载量"));

	ui->tableWidget->setHorizontalHeaderLabels(header);

	//获取表头原先的字体,加粗后设置
	QFont font = ui->tableWidget->horizontalHeader()->font();
	font.setBold(true);
	ui->tableWidget->horizontalHeader()->setFont(font);

	//设置默认列高40
	ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);

	ui->tableWidget->verticalHeader()->setVisible(false);

	//设置选择模式
	ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	//设置不可编辑
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	//第一个参数是列的索引,第二个参数是填充类型
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

	for (int i = 0; i < 10; ++i)
	{
		int rowcount = ui->tableWidget->rowCount();
		ui->tableWidget->insertRow(rowcount);

		QTableWidgetItem* item1 = new QTableWidgetItem();
		QTableWidgetItem* item2 = new QTableWidgetItem();
		QTableWidgetItem* item3 = new QTableWidgetItem();

		//设置字体居中
		item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		//number位于QString.h下,作用应该是将数字转为字符
		item1->setText(QString::number(i + 1));

		item2->setText(QString("filename%0").arg(QString::number(i + 1)));

		item3->setText(QString::number(4096 - i * 10));

		//设置item,第一个参数为行,第二个参数为列,第三个参数为item的指针
		ui->tableWidget->setItem(rowcount, 0, item1);
		ui->tableWidget->setItem(rowcount, 1, item2);
		ui->tableWidget->setItem(rowcount, 2, item3);

		Sleep(200);
	}
}
