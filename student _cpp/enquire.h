#ifndef ENQUIRE_H
#define ENQUIRE_H

#include <QDialog>
#include <list>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>
namespace Ui {
class enquire;
}

class enquire : public QDialog
{
    Q_OBJECT

public:
    explicit enquire(QWidget *parent = nullptr);
    QList<QString>student;
    int  infile();
    void enquire_(int number,QString data);
    QStandardItemModel *modle;
    void enquire_1(int row,QStringList sub);
    ~enquire();

private slots:
    void on_push_clicked();

private:
    Ui::enquire *ui;
};

#endif // ENQUIRE_H
