#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_studyqttable.h"

class studyQtTable : public QMainWindow
{
    Q_OBJECT

public:
    studyQtTable(QWidget *parent = Q_NULLPTR);

private:
    Ui::studyQtTableClass* ui = new Ui::studyQtTableClass();
};
