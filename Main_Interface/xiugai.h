#ifndef XIUGAI_H
#define XIUGAI_H

#include <QMainWindow>

namespace Ui {
class xiugai;
}

class QErrorMessage;  //错误信息的类前置声明

class xiugai : public QMainWindow
{
    Q_OBJECT

public:
    explicit xiugai(QWidget *parent = nullptr);
    ~xiugai();

private slots:
    void on_comboBox_5_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::xiugai *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // XIUGAI_H
