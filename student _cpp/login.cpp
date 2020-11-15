#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ///////////////////////////////////////////////////////////////////////////////////////////
    QPalette p;
    QPixmap pix(":/new/prefix1/image/p2548452761.jpg");
    p.setBrush(QPalette::Window,QBrush(pix));                  //背景图模块
    this->setPalette(p);
    //////////////////////////////////////////////////////////////////////////////////////////
}

login::~login()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void login::on_login_2_clicked()  //登录按钮
{
    //获取用户名和密码
    QString name =ui->input_name->text();
    QString password =ui->input_password->text();
    if (ui->admin->isChecked())
    {
        if (password.length()<6){
            QMessageBox::about(this,"错误","密码少于6位");

        }
        else{
            if (name=="admin"&&password=="654321")
            {
                qDebug()<<"登陆成功";                                     //管理员界面
                menu02.show();
                this->hide();

            }
            else
            {
                QMessageBox::about(this,"错误","用户名或密码错误");
            }

        }


    }
    /////////////////////////////////////////////////////////////////////////////
    else
    {
        if (password.length()<6){
            QMessageBox::about(this,"错误","密码少于6位");

        }
        else{
            if (name=="9AM"&&password=="123456")
            {
                qDebug()<<"登陆成功";                                       //普通用户界面
                menu01.show();
                this->hide();

            }
            else
            {
                QMessageBox::about(this,"错误","用户名或密码错误");
            }

        }

    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
