#pragma execution_character_set("utf-8")
#include "enquire.h"
#include "ui_enquire.h"
#include <QString>
#include <QDebug>
#include <list>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStandardItem>
#include <QPixmap>
#include <QPalette>
enquire::enquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enquire)
{
    ui->setupUi(this);
    /////////////////////////////////////////////////////////////
    QPalette p;
    QPixmap pix(":/new/prefix1/image/p2548452779.jpg");   //背景图设置
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    ////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////
    this->modle =new QStandardItemModel;
    modle->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    modle->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    modle->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    modle->setHorizontalHeaderItem(3,new QStandardItem("年龄"));        //模板设置
    modle->setHorizontalHeaderItem(4,new QStandardItem("专业"));
    modle->setHorizontalHeaderItem(5,new QStandardItem("班级"));
    ui->tableView->setModel(modle);  //引用模板
    ////////////////////////////////////////////////////////////////////////////////////////////////

    infile();  //读取数据

}

enquire::~enquire()
{
    delete ui;
}
/////////////////////////////////////////////////////////////////////////////////////////////
int enquire::infile()
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
        student.append(line);   //读取一行存到容器里
    }
    file.close();
    return 0;
}

//查询按钮
//////////////////////////////////////////////////////////////////////////////////////////////////
void enquire::on_push_clicked()
{
    int number =ui->comboBox->currentIndex();  //获取查询方式
    QString data=ui->lineEdit->text();  //获取文本
    enquire_(number,data);  //查询
}
//////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
//查询（查询方式，需要匹的配的数据）
void enquire::enquire_(int number, QString data)
{
    int i=0;int row=0;
    for (i=0;i<student.length();i++)   //遍历查询
    {
        QString line =student.at(i);   //容器里取出一个元素
        //line.trimmed();
        QStringList sub =line.split(" ");  //进行分词
        switch (number) {
        case 1:                        //判断
            if (data==sub.at(1))
            {
                qDebug()<<line;
                enquire_1(row++,sub);
            }
            break;
        case 2:
            if (data==sub.at(0))
            {
                qDebug()<<line;
               enquire_1(row++,sub);
            }
            break;
       /*  case 3:
           if (data ==sub.at(5))
           {
               enquire_1(row++,sub);
           }*/
        default:break;

        }
    }

}
////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
//写入到表格模板函数（写道第几行，容器元素）
void enquire::enquire_1(int row, QStringList sub)
{

    int i=0;
    for (i=0;i<sub.length();i++)
    {
        modle->setItem(row,i,new QStandardItem(sub.at(i)));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////










