#include "mainwindow.h"
#include "mainwindow_p.h"

#include "ui_mainwindow.h"

#include <QTime>

#include "../GoCore/observer/goobserver.h"

void staticFunction()
{
    qDebug("StaticFunction()");
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , GoPublicClass(*new MainWindowPrivate())
    , ui(new Ui::MainWindow())
{
    ui->setupUi(this);

    GoObserver::attach(ui->pushButton_1, SIGNAL(clicked()), "test_1");
    GoObserver::detach(ui->pushButton_1, SIGNAL(clicked()), "test_1");
    GoObserver::attach(ui->pushButton_1, SIGNAL(clicked()), "test_1");

    GoObserver::attach("test_1", this, SLOT(showTime()));
    GoObserver::detach("test_1", this, SLOT(showTime()));
    GoObserver::attach("test_1", this, SLOT(showTime()));

    GoObserver::attach(ui->pushButton_2, &QAbstractButton::clicked, "test_2");
    GoObserver::detach(ui->pushButton_2, &QAbstractButton::clicked, "test_2");
    GoObserver::attach(ui->pushButton_2, &QAbstractButton::clicked, "test_2");

    GoObserver::attach("test_2", this, &MainWindow::showTime);
    GoObserver::detach("test_2", this, &MainWindow::showTime);
    GoObserver::attach("test_2", this, &MainWindow::showTime);

    GoObserver::attach("test", staticFunction);

    connect(ui->pushButton_3, SIGNAL(clicked()),
            this, SLOT(notify()));
}

void MainWindow::showTime()
{
    setWindowTitle(QTime::currentTime().toString());
}

void MainWindow::notify()
{
    GoObserver::notify("test");
}

///

MainWindowPrivate::MainWindowPrivate()
{
}


MainWindowPrivate::~MainWindowPrivate()
{
}
