#pragma execution_character_set("utf-8")

#include <QFileInfo>
#include "studyqtnetworkpicture.h"
#include <QtNetwork/QNetworkRequest>

studyQtNetWorkPicture::studyQtNetWorkPicture(QWidget* parent)
	: QMainWindow(parent)
{
	this->resize(600, 480);
	QWidget* widget = new QWidget(this);
	setCentralWidget(widget);

	m_push_button = new QPushButton();
	m_push_button->setFixedSize(60, 40);
	m_push_button->setText(QString("开始下载"));
	connect(m_push_button, SIGNAL(clicked(bool)), this, SLOT(StartDownLoad()));

	QGridLayout* layout = new QGridLayout();
	layout->addWidget(m_push_button);

	widget->setLayout(layout);
}

void studyQtNetWorkPicture::StartDownLoad()
{
	m_network_manager = new QNetworkAccessManager();

	//设置按钮禁用
	m_push_button->setEnabled(false);

	//网络请求
	QNetworkRequest request;
	request.setUrl(QUrl("https://inews.gtimg.com/newsapp_bt/0/12750757392/1000"));

	//信号、槽函数
	connect(m_network_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(FinishedReply(QNetworkReply*)));

	//获取请求
	m_network_manager->get(request);
}

void studyQtNetWorkPicture::FinishedReply(QNetworkReply* reply)
{
	m_push_button->setEnabled(true);

	//if (reply->error() == QNetworkReply::NoError)
	{
		QFile of("E:/csdn.png");
		if (of.open(QIODevice::Append))
		{
			QByteArray data = reply->readAll();
			of.write(data);
		}
		//不同于C#,必须自己手动关闭
		of.close();
	}
}
