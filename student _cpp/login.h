#ifndef LOGIN_H
#define LOGIN_H
#include "menu01.h"
#include "menu02.h"
#include <QMainWindow>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    menu01 menu01; //普通用户菜单
    menu02 menu02; //管理员菜单
    ~login();

private slots:
    void on_login_2_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
