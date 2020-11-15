#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //////////////////////////////////////////////////////////////////
    QPalette p;
    QPixmap pix(":/new/prefix1/image/123.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));          // 背景图模块
    this->setPalette(p);
    ///////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////////

void MainWindow::on_commandLinkButton_clicked()
{
    login.show();  //登录界面显示
    this->hide();  //主界面隐藏
}
////////////////////////////////////////////////////////////////////
