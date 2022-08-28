#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

#include <QMainWindow>
//自定义窗口文件
#include "zhuce.h"
#include "guanli.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Main_Interface; }
QT_END_NAMESPACE

class QErrorMessage;  //错误信息的类前置声明

class Main_Interface : public QMainWindow
{
    Q_OBJECT

public:
    Main_Interface(QWidget *parent = nullptr);
    ~Main_Interface();
    static QString yonghu; //全局变量
private slots:
    void on_zhuce_bt_clicked();

    void on_denglu_bt_clicked();

private:
    Ui::Main_Interface *ui;
    //新窗口公有成员声明
    zhuce * zhuce_win;
    guanli * guanli_win;
    QErrorMessage * errordlg; //错误信息的私有对象
};
#endif // MAIN_INTERFACE_H
