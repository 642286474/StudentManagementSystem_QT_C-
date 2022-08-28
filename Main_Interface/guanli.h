#ifndef GUANLI_H
#define GUANLI_H

#include <QMainWindow>
#include "zengjia.h"
#include "shanchu.h"
#include "xiugai.h"
#include "chaxun.h"
#include "yonghuxinxi.h"
#include "caozuo.h"
#include "guanyu.h"

namespace Ui {
class guanli;
}

class guanli : public QMainWindow
{
    Q_OBJECT

public:
    explicit guanli(QWidget *parent = nullptr);
    ~guanli();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_action_2_triggered();

    void on_action_triggered();

    void on_action_11_triggered();

    void on_action_12_triggered();

private:
    Ui::guanli *ui;

    //公有成员
    zengjia * zengjia_win;
    shanchu * shanchu_win;
    xiugai * xiugai_win;
    chaxun * chaxun_win;
    yonghuxinxi * yonghu_win;
    caozuo * caozuo_win;
    guanyu * guanyu_win;
};

#endif // GUANLI_H
