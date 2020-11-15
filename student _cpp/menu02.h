#ifndef MENU02_H
#define MENU02_H

#include <QDialog>
#include "add.h"
#include "enquire.h"
#include<list>
#include "delete_.h"
namespace Ui {
class menu02;
}

class menu02 : public QDialog
{
    Q_OBJECT

public:
    explicit menu02(QWidget *parent = nullptr);
    add add; //添加界面
    enquire enquire;
    delete_ delete_;
    ~menu02();

private slots:


    void on_exit_clicked();

    void on_add_clicked();

    void on_query_clicked();

    void on_delete__clicked();

private:
    Ui::menu02 *ui;
};

#endif // MENU02_H
