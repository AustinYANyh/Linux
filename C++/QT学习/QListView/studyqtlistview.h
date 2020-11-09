#pragma once

#include <QtWidgets/QListView>
#include <QtWidgets/QDialog>
#include <iostream>

class studylistview : public QDialog
{
    Q_OBJECT
public:
    studylistview(QWidget *parent = Q_NULLPTR);

private:
    QListView *ui;
};