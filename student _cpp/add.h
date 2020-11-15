#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QString>
namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButton_clicked();  //确认添加
    void addDATA (QString total); //保存文件函数

private:
    Ui::add *ui;
};

#endif // ADD_H
