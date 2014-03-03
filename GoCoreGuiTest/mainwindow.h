#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../GoCore/datahiding/godatahiding.h"

#include <QWidget>
#include <QSharedPointer>

namespace Ui {
class MainWindow;
}

class MainWindowPrivate;
class MainWindow : public QWidget, public GoPublicClass
{
    Q_OBJECT
    GO_PRIVATE_INFO(MainWindow)

public:
    explicit MainWindow(QWidget *parent = 0);
private:
    QSharedPointer<Ui::MainWindow> ui;

private Q_SLOTS:
    void showTime();
    void notify();
};

#endif // MAINWINDOW_H
