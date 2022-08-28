#ifndef YONGHUXINXI_H
#define YONGHUXINXI_H

#include <QMainWindow>

namespace Ui {
class yonghuxinxi;
}

class QErrorMessage;  //错误信息的类前置声明

class yonghuxinxi : public QMainWindow
{
    Q_OBJECT

public:
    explicit yonghuxinxi(QWidget *parent = nullptr);
    ~yonghuxinxi();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::yonghuxinxi *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // YONGHUXINXI_H
