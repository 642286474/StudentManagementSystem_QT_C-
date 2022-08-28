#ifndef SHANCHU_H
#define SHANCHU_H

#include <QMainWindow>

namespace Ui {
class shanchu;
}

class QErrorMessage;  //错误信息的类前置声明

class shanchu : public QMainWindow
{
    Q_OBJECT

public:
    explicit shanchu(QWidget *parent = nullptr);
    ~shanchu();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::shanchu *ui;
    QErrorMessage * errordlg; //错误信息的私有对象
};

#endif // SHANCHU_H
