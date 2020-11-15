#ifndef MENU01_H
#define MENU01_H

#include <QDialog>
#include "enquire.h"
namespace Ui {
class menu01;
}

class menu01 : public QDialog
{
    Q_OBJECT

public:
    explicit menu01(QWidget *parent = nullptr);
    enquire enquire;
    ~menu01();

private slots:


    void on_pushButton_clicked();

private:
    Ui::menu01 *ui;
};

#endif // MENU01_H
