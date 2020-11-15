#include "menu01.h"
#include "ui_menu01.h"
#include <QPushButton>
menu01::menu01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu01)
{
    ui->setupUi(this);
    /////////////////////////////////////////////////////////////////
    QPalette p;
    QPixmap pix(":/new/prefix1/image/p2548452778.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    /////////////////////////////////////////////////////////////////
}

menu01::~menu01()
{
    delete ui;
}

//////////////////////////////////////////////////////////////////////////////////
void menu01::on_pushButton_clicked()
{
    enquire.show();
    this->hide();
    enquire.exec();
    this->show();
}
/////////////////////////////////////////////////////////////////////////////////
