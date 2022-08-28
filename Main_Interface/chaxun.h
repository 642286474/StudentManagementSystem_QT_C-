#ifndef CHAXUN_H
#define CHAXUN_H

#include <QMainWindow>

namespace Ui {
class chaxun;
}

class QErrorMessage;  //错误信息的类前置声明

class chaxun : public QMainWindow
{
    Q_OBJECT

public:
    explicit chaxun(QWidget *parent = nullptr);
    ~chaxun();

private slots:
    void on_comboBox_5_currentIndexChanged(int index);


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::chaxun *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // CHAXUN_H
