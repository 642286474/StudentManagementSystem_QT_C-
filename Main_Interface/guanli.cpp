#include "guanli.h"
#include "ui_guanli.h"

guanli::guanli(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guanli)
{
    ui->setupUi(this);
}

guanli::~guanli()
{
    delete ui;
}

//增加数据
void guanli::on_pushButton_clicked()
{
    zengjia_win = new zengjia(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    zengjia_win->show();//注册窗口显示

    //this->hide();//隐藏当前窗口
}


//删除数据
void guanli::on_pushButton_2_clicked()
{
    shanchu_win = new shanchu(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    shanchu_win->show();//注册窗口显示

    //this->hide();//隐藏当前窗口
}


//修改数据
void guanli::on_pushButton_3_clicked()
{
    xiugai_win = new xiugai(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    xiugai_win->show();//注册窗口显示

    //this->hide();//隐藏当前窗口
}


//查询数据
void guanli::on_pushButton_4_clicked()
{
    chaxun_win = new chaxun(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    chaxun_win->show();//注册窗口显示

    //this->hide();//隐藏当前窗口
}


//用户信息
void guanli::on_action_triggered()
{
    yonghu_win = new yonghuxinxi(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    yonghu_win->show();//注册窗口显示

    //this->hide();//隐藏当前窗口
}


//退出登陆
void guanli::on_action_2_triggered()
{
    delete this;//销毁注册窗口，释放堆内存
}





//操作
void guanli::on_action_11_triggered()
{
    caozuo_win = new caozuo(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    caozuo_win->show();//注册窗口显示
}


//关于
void guanli::on_action_12_triggered()
{
    guanyu_win = new guanyu(this);//创建注册窗口界面对象，并指明第二个窗口界面的父窗口是当前窗口
    guanyu_win->show();//注册窗口显示
}

