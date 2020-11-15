#ifndef QUERY_H
#define QUERY_H

#include <QDialog>
#include <QString>
#include <list>
#include <QStandardItem>
#include <QStandardItemModel>
namespace Ui {
class query;
}

class query : public QDialog
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = nullptr);
    QList <QString> student; //QString类型容器
    QStandardItemModel *model; //表格模板指针
    int infile();
    void query_(int num ,QString data);
    ~query();

private slots:
    void on_pushButton_clicked();

private:
    Ui::query *ui;
};

#endif // QUERY_H
