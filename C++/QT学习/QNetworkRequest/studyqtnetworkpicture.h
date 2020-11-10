#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>

class studyQtNetWorkPicture : public QMainWindow
{
	Q_OBJECT

public:
	studyQtNetWorkPicture(QWidget* parent = Q_NULLPTR);

private slots:
	void StartDownLoad();

	void FinishedReply(QNetworkReply*);

private:
	//QLabel* m_label;
	QPushButton* m_push_button;
	QNetworkAccessManager* m_network_manager;
};
