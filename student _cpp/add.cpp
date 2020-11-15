#pragma execution_character_set("utf-8")
#include "add.h"
#include "ui_add.h"
#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QTextCodec>
#include <QSettings>
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    QPalette p;
    QPixmap pix(":/new/prefix1/image/p2548452775.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
}

add::~add()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////////
void add::on_pushButton_clicked()
{
    QString number;
    QString name;
    QString sex;               //添加按钮
    QString age;
    QString pro;
    QString class_2;
    QString total;
    number =ui->number->text();
    name =ui->name->text();
    if (ui->boy->isChecked())
    {
        sex="男";                    //获取信息
    }
    else {sex ="女";}
    age =ui->age->text();
    pro =ui->pro->text();
    class_2= ui->class_2->text();
    total =number +" "+ name + " " + sex + " " + age+ " " + pro +" "+class_2+ " "+"\n";  //整合
    qDebug()<<total;
    addDATA(total);      //写入文件
}
////////////////////////////////////////////////////////////////////////////////////////
void add::addDATA(QString total)
{


    QFile file ("a.text");
    if (!file.open(QIODevice::Append|QIODevice::Text))   //文件打开不成功
    {

       return ;
    }
    QTextStream out(&file);
    out<<total;
    out.setCodec("utf-8");
    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
