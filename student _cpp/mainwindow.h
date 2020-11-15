#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    login login;  //登录界面
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
