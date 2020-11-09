//设置执行字符集为utf8,解决程序运行时中文乱码
#pragma execution_character_set("utf-8")

#include "studyqtlistview.h"
#include <QStringListModel>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

studylistview::studylistview(QWidget* parent) : QDialog(parent)
{
	ui = new QListView();

	//QT提供的字符串列表
	QStringList strlist;
	strlist << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saterday" << "Sunday";

	QAbstractItemModel* model = new QStringListModel(strlist);

	//数据绑定
	ui->setModel(model);

	//三行零列的索引
	QModelIndex index = model->index(3, 0);

	QLabel* label = new QLabel();
	label->setText(model->data(index, Qt::DisplayRole).toString());

	QGridLayout* layout = new QGridLayout();
	layout->addWidget(ui);
	layout->addWidget(label);

	setLayout(layout);
}