#ifndef ZENGJIA_H
#define ZENGJIA_H

#include <QMainWindow>

namespace Ui {
class zengjia;
}

class QErrorMessage;  //错误信息的类前置声明

class zengjia : public QMainWindow
{
    Q_OBJECT

public:
    explicit zengjia(QWidget *parent = nullptr);
    ~zengjia();


private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::zengjia *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // ZENGJIA_H
