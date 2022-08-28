#ifndef ZHUCE_H
#define ZHUCE_H

#include <QMainWindow>

namespace Ui {
class zhuce;
}

class QErrorMessage;  //错误信息的类前置声明

class zhuce : public QMainWindow
{
    Q_OBJECT

public:
    explicit zhuce(QWidget *parent = nullptr);
    ~zhuce();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::zhuce *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // ZHUCE_H
