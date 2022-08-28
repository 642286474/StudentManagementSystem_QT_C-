#include "yonghuxinxi.h"
#include "ui_yonghuxinxi.h"
#include "main_interface.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QErrorMessage>
#include <QCryptographicHash>
#include <QSqlQuery>

int huadong_value1; //存储滑动条当前值

yonghuxinxi::yonghuxinxi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::yonghuxinxi)
{
    ui->setupUi(this);

    errordlg = new QErrorMessage(this);
    ui->textBrowser->setText(Main_Interface::yonghu); //展示用户账号
}

yonghuxinxi::~yonghuxinxi()
{
    delete ui;
}


//修改密码
void yonghuxinxi::on_pushButton_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString old_passwd = ui->lineEdit->text(); //获取原密码
    QString new_passwd = ui->lineEdit_2->text(); //获取密码
    QString queren_passwd = ui->lineEdit_3->text(); //获取确认密码

    if(old_passwd == "" || new_passwd == "" || queren_passwd == ""){ //存在未填写
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请填写完整！"));
    }
    else if(new_passwd != queren_passwd){//两次密码不一致
        errordlg->setWindowTitle(tr("注册失败！"));
        errordlg->showMessage(tr("两次密码不一致！"));

    }
    else if(huadong_value1 != 99){//未通过验证
        errordlg->setWindowTitle(tr("注册失败！"));
        errordlg->showMessage(tr("请拉验证条！"));

    }

    else{//两次密码正确且通过验证

        //旧密码加密用于与数据库密码匹配
        QCryptographicHash h1(QCryptographicHash::Md5);
        h1.addData(old_passwd.toUtf8());
        QString jm_old_passwd = h1.result();

        //获取原密码
        QString  sql = QString("select * from users where user = '%1'").arg(Main_Interface::yonghu);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first();
        qDebug()<<jm_old_passwd<<query.value(1).toString();
        if(jm_old_passwd == query.value(1).toString()){ //原密码正确
            //写入数据库
            //新密码加密
            QCryptographicHash h(QCryptographicHash::Md5);
            h.addData(new_passwd.toUtf8());
            QString jm_passwd = h.result();
            //修改数据
            QString  sql = QString("update users set passwd = '%1' where user = '%2'").arg(jm_passwd).arg(Main_Interface::yonghu);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("密码修改成功！"));
            errordlg->showMessage(tr("密码修改成功！"));
        }
        else {
            errordlg->setWindowTitle(tr("密码修改是失败！"));
            errordlg->showMessage(tr("密码修改失败！原密码错误。"));
        }

    }
}


//获取滑动条当前值
void yonghuxinxi::on_horizontalSlider_valueChanged(int value)
{
    huadong_value1 = value;
    qDebug()<<huadong_value1;
}

