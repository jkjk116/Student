#pragma execution_character_set("utf-8")
#include "menu02.h"
#include "ui_menu02.h"
menu02::menu02(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu02)
{
    ui->setupUi(this);
    //////////////////////////////////////////////////////////////////////////
    QPalette p;
    QPixmap pix(":/new/prefix1/image/p2548452771.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    /////////////////////////////////////////////////////////////////////////////////
}

menu02::~menu02()
{
    delete ui;
}

////////////////////////////////////////////
void menu02::on_exit_clicked()  //退出按钮
{
    this->close();
}
////////////////////////////////////////////

void menu02::on_add_clicked()  //进入添加界面
{
    add.show();
    this->hide();
    add.exec();
    this->show();
}

////////////////////////////////////////////
void menu02::on_query_clicked()   //进入查询界面
{
    enquire.show();
    this->hide();
    enquire.exec();
    //this->show();
}
////////////////////////////////////////////

void menu02::on_delete__clicked()   //进入删除界面
{
    delete_.show();
    this->hide();
    delete_.exec();
    this->close();
}
////////////////////////////////////////////
