#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer::singleShot(5,this,SLOT(initFunSlot())); //延时初始化
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initFunSlot()
{
    initWid();
}

void MainWindow::initWid()
{
    mHomeWid = new Home_MainWid(ui->stackedWid);
    ui->stackedWid->addWidget(mHomeWid);

//    mStatusWid = new Home_StatusTabWid(ui->stackedWid);
//    ui->stackedWid->addWidget(mStatusWid);
//    connect(mHomeWid, SIGNAL(startSig()), mStatusWid, SLOT(startSlot()));

//    mSetupWid = new Setup_MainWid(ui->stackedWid);
//    ui->stackedWid->addWidget(mSetupWid);

//    mLog = new LogMainWid(ui->stackedWid);
//    ui->stackedWid->addWidget(mLog);

    mNavBarWid = new NavBarWid(ui->barWid);
    connect(mNavBarWid, SIGNAL(navBarSig(int)), this, SLOT(navBarSlot(int)));
}

void MainWindow::navBarSlot(int id)
{
    ui->stackedWid->setCurrentIndex(id);
}
