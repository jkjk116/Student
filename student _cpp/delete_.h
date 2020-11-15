#ifndef DELETE__H
#define DELETE__H

#include <QDialog>
#include <QString>
#include <list>
namespace Ui {
class delete_;
}

class delete_ : public QDialog
{
    Q_OBJECT

public:
    explicit delete_(QWidget *parent = nullptr);
    void delete_data();
    int infile(QString number);
    QList <QString> data;
   // QString *s;
    void resWrite();//重写文件
    void change (QString number);
    ~delete_();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::delete_ *ui;
};

#endif // DELETE__H
