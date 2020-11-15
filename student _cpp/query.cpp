#include "query.h"
#include "ui_query.h"
#include <QString>
#include <QDebug>
#include <list>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
query::query(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::query)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;
    model->setHorizontalHeaderItem(0,new QStandardItem("学号"));
    model->setHorizontalHeaderItem(1,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4,new QStandardItem("专业"));
    model->setHorizontalHeaderItem(5,new QStandardItem("班级"));
    ui->tableView->setModel(model);
    infile();
}

query::~query()
{
    delete ui;
}
int  query::infile()
{
    QFile file ("G:\\Desktop\\a.text");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1 ;
    }
    QTextStream in(&file);
    while (!in.atEnd()) //如果没到解为
    {
        QString line =in.readLine();//获取当前行
        student.append(line); //添加到容器
    }
    file.close();
    int i=0;
    for (i=0;i<student.length();i++) //测试
    {
        qDebug()<<student.at(i);
    }
    return 0;

}

void query::on_pushButton_clicked()
{
    int num=ui->comboBox->currentIndex(); //获取查询方式 0:无 1：按学号 2：按姓名 3：按专业 4：按班级查询
    QString data=ui->data->text(); //获取查询文本内容
   // query_(num,data);
    qDebug()<<num<<data;
}
/*void query::query_(int num, QString data)
{
    int i=0;int row=0;
    for (i=0;i<student.length();i++)
    {
        QString line =student.at(i);
        //line.trimmed();
        QStringList sub =line.split(" ");
        switch (num) {
        case 1:
            if (data==sub.at(1))
            {
                qDebug()<<line;

            }
            break;
        case 2:
            if (data==sub.at(0))
            {
                qDebug()<<line;

            }
            break;
        default:break;

        }
    }
}*/
