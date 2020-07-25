#pragma once
#include <QFileIconProvider>
#include <QFileSystemModel>

class MyFileIconProvider
	: public QFileIconProvider
{
public:
	MyFileIconProvider()
		: QFileIconProvider()
	{}

	QIcon icon(const QFileInfo& info) const
	{
		if (info.isExecutable())
		{
			return QIcon();
		}
		return QFileIconProvider::icon(info);
	}
};

class MyFileSystemModel
	: public QFileSystemModel
{
	Q_OBJECT

public:
	MyFileSystemModel(QObject* parent = 0)
		: QFileSystemModel(parent)
	{
		setIconProvider(&m_myFileIconProvider);
	}

private:
	MyFileIconProvider m_myFileIconProvider;
};
