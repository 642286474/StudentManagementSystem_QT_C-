#include "chaxun.h"
#include "ui_chaxun.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>  //数据库
#include <QErrorMessage>  //提示框
#include <QSqlQueryModel>

chaxun::chaxun(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chaxun)
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

chaxun::~chaxun()
{
    delete ui;
}


//批量查找
void chaxun::on_comboBox_5_currentIndexChanged(int index)
{
    if(index == 0){   //所有学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("所有专业");
    }
    if(index == 1){ //信工学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("智能科学与技术");
        ui->comboBox_6->addItem("信息管理与信息系统");
        ui->comboBox_6->addItem("软件工程");
        ui->comboBox_6->addItem("计算机科学与技术");
        ui->comboBox_6->addItem("物联网工程");
        ui->comboBox_6->addItem("数据科学与大数据技术");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 2){ //华为学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("智能科学与技术");
        ui->comboBox_6->addItem("软件工程");
        ui->comboBox_6->addItem("计算机科学与技术");
        ui->comboBox_6->addItem("数据科学与大数据技术");
        ui->comboBox_6->addItem("计算机应用技术（专）");
        ui->comboBox_6->addItem("软件技术（专）");
        ui->comboBox_6->addItem("物联网应用技术（专）");
        ui->comboBox_6->addItem("人工智能技术应用（专）");
        ui->comboBox_6->addItem("大数据技术（专）");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 3){ //法学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("法学");
        ui->comboBox_6->addItem("信用风险管理与法律防控");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 4){ //管理学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("市场营销");
        ui->comboBox_6->addItem("物流管理");
        ui->comboBox_6->addItem("电子商务");
        ui->comboBox_6->addItem("旅游管理");
        ui->comboBox_6->addItem("酒店管理");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 5){ //外国语学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("英语");
        ui->comboBox_6->addItem("德语");
        ui->comboBox_6->addItem("日语");
        ui->comboBox_6->addItem("商务英语");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 6){ //会计学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("会计学");
        ui->comboBox_6->addItem("财务管理");
        ui->comboBox_6->addItem("审计学");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 7){ //国际学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("物流管理（中外合作）");
        ui->comboBox_6->addItem("国际商务（国际联合）");
        ui->comboBox_6->addItem("财务管理（国际联合）");
        ui->comboBox_6->addItem("软件工程（国际联合）");
        ui->comboBox_6->addItem("金融学（国际联合）");
        ui->comboBox_6->addItem("金融学（中英双语）");
        ui->comboBox_6->addItem("会计学（中英双语）");
        ui->comboBox_6->addItem("国际商务（中英双语）");
        ui->comboBox_6->addItem("商务英语（中英双语）");
        ui->comboBox_6->addItem("国际商务（中英双语）（专）");
        ui->comboBox_6->addItem("大数据与会计（中英双语）（专）");
        ui->comboBox_6->addItem("商务英语（中英双语）（专）");
        ui->comboBox_6->addItem("国际金融（中英双语）（专）");
        ui->comboBox_6->addItem("视觉传达设计（中英双语）（专）");
        ui->comboBox_6->addItem("产品艺术设计（中英双语）（专）");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 8){ //经济学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("金融学");
        ui->comboBox_6->addItem("投资学");
        ui->comboBox_6->addItem("互联网金融");
        ui->comboBox_6->addItem("国际经济与贸易");
        ui->comboBox_6->addItem("所有专业");
    }
    else if(index == 9){ //艺术学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("视觉传达设计");
        ui->comboBox_6->addItem("环境设计");
        ui->comboBox_6->addItem("产品设计");
        ui->comboBox_6->addItem("数字媒体艺术");
        ui->comboBox_6->addItem("公共艺术");
        ui->comboBox_6->addItem("所有专业");
    }
}



//学号查询
void chaxun::on_pushButton_2_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //学号

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("查询失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条
        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）

               static QSqlQueryModel *mode= new QSqlQueryModel(ui->tableView);
               mode->setQuery(sql,mydb);
               mode->setHeaderData(0,Qt::Horizontal,tr("id"));
               mode->setHeaderData(1, Qt::Horizontal, tr("name"));
               ui->tableView->setModel(mode);
                errordlg->setWindowTitle(tr("查询成功！"));
                errordlg->showMessage(tr("查询成功！"));
            }

        else{
            errordlg->setWindowTitle(tr("查询失败！"));
            errordlg->showMessage(tr("查询失败！学号不存在。"));
        }
    }

}


//学院专业查找
void chaxun::on_pushButton_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xueyuan = ui->comboBox_5->currentText(); //获取学院
    QString zhuanye = ui->comboBox_6->currentText(); //获取专业
    QString  sql;
    if(xueyuan == "所有学院"){  //全部查询
        sql = QString("select * from students");
    }
    else if(zhuanye == "所有专业"){ //学院查询
        sql = QString("select * from students where college = '%1'").arg(xueyuan);

    }
    else{
        sql = QString("select * from students where college = '%1' and specialty = '%2'").arg(xueyuan).arg(zhuanye);
    }
    QSqlQuery query(QSqlDatabase::database("chen"));
    query.exec(sql);
    query.first(); //获取第一条

    if(query.first()){  //如果学院专业存在（查询到在数据库中）
           static QSqlQueryModel *mode= new QSqlQueryModel(ui->tableView);
           mode->setQuery(sql,mydb);
           mode->setHeaderData(0,Qt::Horizontal,tr("id"));
           mode->setHeaderData(1, Qt::Horizontal, tr("name"));
           ui->tableView->setModel(mode);
            errordlg->setWindowTitle(tr("查询成功！"));
            errordlg->showMessage(tr("查询成功！"));
        }

    else{
        errordlg->setWindowTitle(tr("查询失败！"));
        errordlg->showMessage(tr("查询失败！该专业不存在。"));
    }
}

