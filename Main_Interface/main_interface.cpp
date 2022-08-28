#include "main_interface.h"
#include "ui_main_interface.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>  //数据库
#include <QErrorMessage>  //提示框
#include <QCryptographicHash> //密码加密
#include <QSqlDatabase>

QString Main_Interface::yonghu;

Main_Interface::Main_Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Interface)
{
    ui->setupUi(this);

    errordlg = new QErrorMessage(this);

        //在QSQLITE数据库中建立连接
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
        mydb.setDatabaseName("user_passwd.db"); //创建数据库
        //检测是否连接成功
        if(!mydb.open())
           {
               qDebug()<<"open fail";
           }
        //建表
        QString  sql = QString("create table users(user char(32),passwd varchar(64),primary key(user))");
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
}

Main_Interface::~Main_Interface()
{
    delete ui;
}


//注册按钮
void Main_Interface::on_zhuce_bt_clicked()
{
    zhuce_win = new zhuce(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    zhuce_win->show();//注册窗口显示

    this->hide();//隐藏当前窗口

}


//登陆
void Main_Interface::on_denglu_bt_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

       QString dl_user = ui->zhanghao_lineEdit->text(); //获取用户名
       Main_Interface::yonghu = dl_user; //全局变量
       QString dl_passwd = ui->mima_lineEdit->text(); //获取密码

       //加密
       QCryptographicHash h(QCryptographicHash::Md5);
       h.addData(dl_passwd.toUtf8());
       QString jm_passwd = h.result();

       //查询数据库是否存在该用户并获取其数据（uesr,passwd）
       QString  sql = QString("select * from users where user = '%1'").arg(dl_user);
       QSqlQuery query(QSqlDatabase::database("chen"));
       query.exec(sql);
       //获取查找到的数据
       QString sql_user,sql_passwd;
       if(query.first()){
           qDebug()<<query.value(0).toString()<<query.value(1).toString();  //返回获取到的账户密码
           sql_user = query.value(0).toString();  //记录用户名
           sql_passwd = query.value(1).toString();  //记录密码
       }
       if(dl_user == ""){ //账号未填写
           errordlg->setWindowTitle(tr("登陆失败！"));
           errordlg->showMessage(tr("请输入账号！"));
       }
       else if(dl_passwd == ""){ //密码未填写
           errordlg->setWindowTitle(tr("登陆失败！"));
           errordlg->showMessage(tr("请输入密码！"));
       }
       else if(sql_user == dl_user and sql_passwd == jm_passwd){ //用户存在且密码正确
           QSqlDatabase::removeDatabase("chen");
           guanli_win = new guanli(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
           guanli_win->show();//管理窗口显示

           this->hide();//隐藏当前窗口·
       }
       else{  //用户不存在或密码错误
           errordlg->setWindowTitle(tr("登陆失败！"));
           errordlg->showMessage(tr("登陆失败！账户不存在或密码错误。"));
        }

}

