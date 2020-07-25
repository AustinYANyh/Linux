#ifndef DIRECTORYVIEWER_H
#define DIRECTORYVIEWER_H

#include <QDialog>
#include "MyFileSystemModel.h"

class QDialogButtonBox;
class QDirModel;
class QTreeView;

class DirectoryViewer : public QDialog
{
	Q_OBJECT

public:
	DirectoryViewer(QWidget* parent = nullptr);

private slots:
	void createDirectory();
	void remove();

private:
	QTreeView* treeView;
	MyFileSystemModel* model;
	QDialogButtonBox* buttonBox;
};

#endif
