#include "zengjia.h"
#include "ui_zengjia.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>  //数据库
#include <QErrorMessage>  //提示框

zengjia::zengjia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zengjia)
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
    QString  sql = QString("create table students(id varchar(64),name varchar(64),college varchar(64),specialty varchar(64),sex varchar(32),age varchar(32),enrollment_data varchar(64),primary key(id))");
    QSqlQuery query(QSqlDatabase::database("chen"));
    query.exec(sql);
}

zengjia::~zengjia()
{
    delete ui;

}


//根据学院出现不同的专业
void zengjia::on_comboBox_currentIndexChanged(int index)
{

    if(index == 0){ //信工学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("智能科学与技术");
        ui->comboBox_2->addItem("信息管理与信息系统");
        ui->comboBox_2->addItem("软件工程");
        ui->comboBox_2->addItem("计算机科学与技术");
        ui->comboBox_2->addItem("物联网工程");
        ui->comboBox_2->addItem("数据科学与大数据技术");
    }
    else if(index == 1){ //华为学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("智能科学与技术");
        ui->comboBox_2->addItem("软件工程");
        ui->comboBox_2->addItem("计算机科学与技术");
        ui->comboBox_2->addItem("数据科学与大数据技术");
        ui->comboBox_2->addItem("计算机应用技术（专）");
        ui->comboBox_2->addItem("软件技术（专）");
        ui->comboBox_2->addItem("物联网应用技术（专）");
        ui->comboBox_2->addItem("人工智能技术应用（专）");
        ui->comboBox_2->addItem("大数据技术（专）");
    }
    else if(index == 2){ //法学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("法学");
        ui->comboBox_2->addItem("信用风险管理与法律防控");
    }
    else if(index == 3){ //管理学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("市场营销");
        ui->comboBox_2->addItem("物流管理");
        ui->comboBox_2->addItem("电子商务");
        ui->comboBox_2->addItem("旅游管理");
        ui->comboBox_2->addItem("酒店管理");
    }
    else if(index == 4){ //外国语学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("英语");
        ui->comboBox_2->addItem("德语");
        ui->comboBox_2->addItem("日语");
        ui->comboBox_2->addItem("商务英语");
    }
    else if(index == 5){ //会计学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("会计学");
        ui->comboBox_2->addItem("财务管理");
        ui->comboBox_2->addItem("审计学");
    }
    else if(index == 6){ //国际学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("物流管理（中外合作）");
        ui->comboBox_2->addItem("国际商务（国际联合）");
        ui->comboBox_2->addItem("财务管理（国际联合）");
        ui->comboBox_2->addItem("软件工程（国际联合）");
        ui->comboBox_2->addItem("金融学（国际联合）");
        ui->comboBox_2->addItem("金融学（中英双语）");
        ui->comboBox_2->addItem("会计学（中英双语）");
        ui->comboBox_2->addItem("国际商务（中英双语）");
        ui->comboBox_2->addItem("商务英语（中英双语）");
        ui->comboBox_2->addItem("国际商务（中英双语）（专）");
        ui->comboBox_2->addItem("大数据与会计（中英双语）（专）");
        ui->comboBox_2->addItem("商务英语（中英双语）（专）");
        ui->comboBox_2->addItem("国际金融（中英双语）（专）");
        ui->comboBox_2->addItem("视觉传达设计（中英双语）（专）");
        ui->comboBox_2->addItem("产品艺术设计（中英双语）（专）");
    }
    else if(index == 7){ //经济学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("金融学");
        ui->comboBox_2->addItem("投资学");
        ui->comboBox_2->addItem("互联网金融");
        ui->comboBox_2->addItem("国际经济与贸易");
    }
    else if(index == 8){ //艺术学院
        ui->comboBox_2->clear(); //清除之前添加的所有选项
        ui->comboBox_2->addItem("视觉传达设计");
        ui->comboBox_2->addItem("环境设计");
        ui->comboBox_2->addItem("产品设计");
        ui->comboBox_2->addItem("数字媒体艺术");
        ui->comboBox_2->addItem("公共艺术");
    }
}


//添加按钮
void zengjia::on_pushButton_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }


    QString xuehao = ui->lineEdit->text(); //获取学号
    QString xingming = ui->lineEdit_2->text(); //获取姓名
    QString xueyuan = ui->comboBox->currentText(); //获取学院
    QString zhuanye = ui->comboBox_2->currentText(); //获取专业
    //获取性别
    QString xingbie;
    if(ui->radioButton->isChecked()){  //男性被选中
        xingbie = ui->radioButton->text();
    }
    else if(ui->radioButton_2->isChecked()){  //女性被选中
        xingbie = ui->radioButton_2->text();
    }
    QString nianling = ui->spinBox->text(); //获取年龄
    QString ruxue = ui->dateEdit->text(); //获取入学时间
    qDebug()<<xuehao<<xingming<<xueyuan<<zhuanye<<xingbie<<nianling<<ruxue;
    //必填选项检测：姓名、学好
    if(xuehao == ""){
        errordlg->setWindowTitle(tr("添加失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else if(xingming == ""){
        errordlg->setWindowTitle(tr("添加失败！"));
        errordlg->showMessage(tr("请输入完整的姓名！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first();
        qDebug()<<query.value(0).toString();
        if(query.value(0).toString() == xuehao){  //如果学号已存在（查询到在数据库中）
            errordlg->setWindowTitle(tr("添加失败！"));
            errordlg->showMessage(tr("添加失败！学号已存在。"));
        }
        else{  //写入数据库
            //写数据id varchar(64),name varchar(64)),college varchar(64),specialty varchar(64)),sex varchar(32),age varchar（32）,enrollment_data varchar(64)
            QString  sql = QString("insert into students values('%1','%2','%3','%4','%5','%6','%7')").arg(xuehao).arg(xingming).arg(xueyuan).arg(zhuanye).arg(xingbie).arg(nianling).arg(ruxue);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("添加成功！"));
            errordlg->showMessage(tr("添加成功！"));
        }
    }

    mydb.close();
    QSqlDatabase::removeDatabase("chen");
}

