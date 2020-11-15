#pragma execution_character_set("utf-8")
#include "delete_.h"
#include "ui_delete_.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <list>
#include <QMessageBox>
delete_::delete_(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_)
{
    ui->setupUi(this);
   // infile(); //加载数据


}

///////////////////////////////////////////////////////////////////////////////////
delete_::~delete_()
{
    delete ui;
    //delete []s;
}
void delete_::delete_data() //删除全部
{

    QFile file("a.text");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
    file.close();
}


void delete_::on_pushButton_clicked()          //全部删除
{
    delete_data();
}

///////////////////////////////////////////////////////////////////////////////////////
int delete_::infile(QString number)
{
    QFile file("a.text");  //路径
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);
    in.setCodec("utf-8");
    while (!in.atEnd())
    {
        QString line=in.readLine();
        QStringList word =line.split(" ");
        if (word.at(0)==number)
        {

        }
        else
        {
        data.append(line);
        }//读取一行存到容器里
    }
    file.close();
    for(int i=0;i<data.length();i++)
    {
        qDebug()<<data.at(i);
    }
    file.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
    file.close();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void delete_::on_pushButton_2_clicked()  //删除按钮
{
    QString number =ui->lineEdit->text();
    infile(number);
   // change(number);
   // delete_data();

    resWrite();
    this->close();
}
/////////////////////////////////////////////////////////////////////////////////////////
void delete_::resWrite()
{
    QFile file("a.text");
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    out.setCodec("utf-8");
    for (int i=0;i<data.length();i++)
    {
        out<<data.at(i);
        out<<"\n";
    }
}
