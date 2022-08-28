#include "zhuce.h"
#include "ui_zhuce.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>  //数据库
#include <QErrorMessage>  //提示框
#include <QCryptographicHash> //密码加密

int huadong_value; //存储滑动条当前值

zhuce::zhuce(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zhuce)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

zhuce::~zhuce()
{
    delete ui;
}


//返回按钮
void zhuce::on_pushButton_2_clicked()
{
    this->parentWidget()->show();//父窗口界面显示
    delete this;//销毁注册窗口，释放堆内存

}


//注册按钮
void zhuce::on_pushButton_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString add_user = ui->lineEdit->text(); //获取用户名
    QString add_passwd = ui->lineEdit_2->text(); //获取密码
    QString queren_passwd = ui->lineEdit_3->text(); //获取确认密码

    //查询数据库是否存在该用户名
    QString  sql = QString("select * from users where user = '%1'").arg(add_user);
    QSqlQuery query(QSqlDatabase::database("chen"));
    query.exec(sql);
    //输出查询到的数据
    if(query.first())
        qDebug()<<query.value(0).toString()<<query.value(1).toString();  //返回获取到的账户密码
    if(add_user == "" || add_passwd == "" || queren_passwd == ""){ //存在未填写
        errordlg->setWindowTitle(tr("注册失败！"));
        errordlg->showMessage(tr("请填写完整！"));
    }
    else if(add_passwd != queren_passwd){//两次密码不一致
        errordlg->setWindowTitle(tr("注册失败！"));
        errordlg->showMessage(tr("两次密码不一致！"));

    }
    else if(huadong_value != 99){//未通过验证
        errordlg->setWindowTitle(tr("注册失败！"));
        errordlg->showMessage(tr("请拉验证条！"));

    }

    else{//两次密码正确且通过验证
        query.first();
        if(query.value(0).toString() == add_user){  //如果账户已存在（查询到在数据库中）
            qDebug()<<query.value(0).toString();
            errordlg->setWindowTitle(tr("注册失败！"));
            errordlg->showMessage(tr("注册失败！账户已存在。"));
        }
        else{  //写入数据库
                //加密
                QCryptographicHash h(QCryptographicHash::Md5);
                h.addData(add_passwd.toUtf8());
                QString jm_passwd = h.result();
                //写数据
                QString  sql = QString("insert into users values('%1','%2')").arg(add_user).arg(jm_passwd);
                QSqlQuery query(QSqlDatabase::database("chen"));
                query.exec(sql);
                errordlg->setWindowTitle(tr("注册成功！"));
                errordlg->showMessage(tr("注册成功！"));
         }
    }
}


//获取滑动条当前值
void zhuce::on_horizontalSlider_valueChanged(int value)
{
    huadong_value = value;
    qDebug()<<huadong_value;
}

