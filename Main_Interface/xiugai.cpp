#include "xiugai.h"
#include "ui_xiugai.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>  //数据库
#include <QErrorMessage>  //提示框

xiugai::xiugai(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::xiugai)
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
//    QString  sql = QString("create table students(id varchar(64),name varchar(64),college varchar(64),specialty varchar(64),sex varchar(32),age varchar(32),enrollment_data varchar(64),primary key(id))");
//        QSqlQuery query(QSqlDatabase::database("chen"));
//        query.exec(sql);
}

xiugai::~xiugai()
{
    delete ui;
}


//多项查询
void xiugai::on_comboBox_5_currentIndexChanged(int index)
{
    if(index == 0){ //信工学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("智能科学与技术");
        ui->comboBox_6->addItem("信息管理与信息系统");
        ui->comboBox_6->addItem("软件工程");
        ui->comboBox_6->addItem("计算机科学与技术");
        ui->comboBox_6->addItem("物联网工程");
        ui->comboBox_6->addItem("数据科学与大数据技术");
    }
    else if(index == 1){ //华为学院
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
    }
    else if(index == 2){ //法学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("法学");
        ui->comboBox_6->addItem("信用风险管理与法律防控");
    }
    else if(index == 3){ //管理学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("市场营销");
        ui->comboBox_6->addItem("物流管理");
        ui->comboBox_6->addItem("电子商务");
        ui->comboBox_6->addItem("旅游管理");
        ui->comboBox_6->addItem("酒店管理");
    }
    else if(index == 4){ //外国语学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("英语");
        ui->comboBox_6->addItem("德语");
        ui->comboBox_6->addItem("日语");
        ui->comboBox_6->addItem("商务英语");
    }
    else if(index == 5){ //会计学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("会计学");
        ui->comboBox_6->addItem("财务管理");
        ui->comboBox_6->addItem("审计学");
    }
    else if(index == 6){ //国际学院
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
    }
    else if(index == 7){ //经济学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("金融学");
        ui->comboBox_6->addItem("投资学");
        ui->comboBox_6->addItem("互联网金融");
        ui->comboBox_6->addItem("国际经济与贸易");
    }
    else if(index == 8){ //艺术学院
        ui->comboBox_6->clear(); //清除之前添加的所有选项
        ui->comboBox_6->addItem("视觉传达设计");
        ui->comboBox_6->addItem("环境设计");
        ui->comboBox_6->addItem("产品设计");
        ui->comboBox_6->addItem("数字媒体艺术");
        ui->comboBox_6->addItem("公共艺术");
    }
}


//单项修改
void xiugai::on_comboBox_currentIndexChanged(int index)
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

//多项修改
void xiugai::on_comboBox_3_currentIndexChanged(int index)
{
    if(index == 0){ //信工学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("智能科学与技术");
        ui->comboBox_4->addItem("信息管理与信息系统");
        ui->comboBox_4->addItem("软件工程");
        ui->comboBox_4->addItem("计算机科学与技术");
        ui->comboBox_4->addItem("物联网工程");
        ui->comboBox_4->addItem("数据科学与大数据技术");
    }
    else if(index == 1){ //华为学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("智能科学与技术");
        ui->comboBox_4->addItem("软件工程");
        ui->comboBox_4->addItem("计算机科学与技术");
        ui->comboBox_4->addItem("数据科学与大数据技术");
        ui->comboBox_4->addItem("计算机应用技术（专）");
        ui->comboBox_4->addItem("软件技术（专）");
        ui->comboBox_4->addItem("物联网应用技术（专）");
        ui->comboBox_4->addItem("人工智能技术应用（专）");
        ui->comboBox_4->addItem("大数据技术（专）");
    }
    else if(index == 2){ //法学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("法学");
        ui->comboBox_4->addItem("信用风险管理与法律防控");
    }
    else if(index == 3){ //管理学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("市场营销");
        ui->comboBox_4->addItem("物流管理");
        ui->comboBox_4->addItem("电子商务");
        ui->comboBox_4->addItem("旅游管理");
        ui->comboBox_4->addItem("酒店管理");
    }
    else if(index == 4){ //外国语学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("英语");
        ui->comboBox_4->addItem("德语");
        ui->comboBox_4->addItem("日语");
        ui->comboBox_4->addItem("商务英语");
    }
    else if(index == 5){ //会计学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("会计学");
        ui->comboBox_4->addItem("财务管理");
        ui->comboBox_4->addItem("审计学");
    }
    else if(index == 6){ //国际学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("物流管理（中外合作）");
        ui->comboBox_4->addItem("国际商务（国际联合）");
        ui->comboBox_4->addItem("财务管理（国际联合）");
        ui->comboBox_4->addItem("软件工程（国际联合）");
        ui->comboBox_4->addItem("金融学（国际联合）");
        ui->comboBox_4->addItem("金融学（中英双语）");
        ui->comboBox_4->addItem("会计学（中英双语）");
        ui->comboBox_4->addItem("国际商务（中英双语）");
        ui->comboBox_4->addItem("商务英语（中英双语）");
        ui->comboBox_4->addItem("国际商务（中英双语）（专）");
        ui->comboBox_4->addItem("大数据与会计（中英双语）（专）");
        ui->comboBox_4->addItem("商务英语（中英双语）（专）");
        ui->comboBox_4->addItem("国际金融（中英双语）（专）");
        ui->comboBox_4->addItem("视觉传达设计（中英双语）（专）");
        ui->comboBox_4->addItem("产品艺术设计（中英双语）（专）");
    }
    else if(index == 7){ //经济学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("金融学");
        ui->comboBox_4->addItem("投资学");
        ui->comboBox_4->addItem("互联网金融");
        ui->comboBox_4->addItem("国际经济与贸易");
    }
    else if(index == 8){ //艺术学院
        ui->comboBox_4->clear(); //清除之前添加的所有选项
        ui->comboBox_4->addItem("视觉传达设计");
        ui->comboBox_4->addItem("环境设计");
        ui->comboBox_4->addItem("产品设计");
        ui->comboBox_4->addItem("数字媒体艺术");
        ui->comboBox_4->addItem("公共艺术");
    }
}


//单项查询学号修改
void xiugai::on_pushButton_3_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    QString new_xuehao = ui->lineEdit_2->text(); //新学号

    if(new_xuehao == "" or xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //查询数据库是否存在新学号
            QString  sql1 = QString("select * from students where id = '%1'").arg(new_xuehao);
            QSqlQuery query1(QSqlDatabase::database("chen"));
            query1.exec(sql1);

            if(query1.value(0).toString() == new_xuehao){ //新学号存在
                errordlg->setWindowTitle(tr("修改失败！"));
                errordlg->showMessage(tr("修改失败！新学号已存在。"));
            }
            else{
                //修改数据
                QString  sql = QString("update students set id = '%1' where id = '%2'").arg(new_xuehao).arg(xuehao);
                QSqlQuery query(QSqlDatabase::database("chen"));
                query.exec(sql);
                errordlg->setWindowTitle(tr("修改成功！"));
                errordlg->showMessage(tr("修改成功！"));
            }

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}


//单项查询姓名修改
void xiugai::on_pushButton_4_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    QString name = ui->lineEdit_3->text(); //姓名

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //修改数据
            QString  sql = QString("update students set name = '%1' where id = '%2'").arg(name).arg(xuehao);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}


//单项查询修改学院专业
void xiugai::on_pushButton_5_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    QString xueyuan = ui->comboBox->currentText(); //获取学院
    QString zhuanye = ui->comboBox_2->currentText(); //获取专业

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //修改数据
            QString  sql = QString("update students set college = '%1',specialty = '%2' where id = '%3'").arg(xueyuan).arg(zhuanye).arg(xuehao);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}



//单项查找修改性别
void xiugai::on_pushButton_6_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    //获取性别
    QString xingbie;
    if(ui->radioButton->isChecked()){  //男性被选中
        xingbie = ui->radioButton->text();
    }
    else if(ui->radioButton_2->isChecked()){  //女性被选中
        xingbie = ui->radioButton_2->text();
    }

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //修改数据
            QString  sql = QString("update students set sex = '%1' where id = '%2'").arg(xingbie).arg(xuehao);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}



//单项查找修改年龄
void xiugai::on_pushButton_7_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    QString nianling = ui->spinBox->text(); //获取年龄

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //修改数据
            QString  sql = QString("update students set age = '%1' where id = '%2'").arg(nianling).arg(xuehao);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}


//单项查找修改入学时间
void xiugai::on_pushButton_8_clicked()
{
    //在QSQLITE数据库中建立连接
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE","chen");
    mydb.setDatabaseName("user_passwd.db"); //创建数据库
    //检测是否连接成功
    if(!mydb.open())
       {
           qDebug()<<"open fail";
       }

    QString xuehao = ui->lineEdit->text(); //原学号
    QString ruxue = ui->dateEdit->text(); //获取入学时间

    if(xuehao == ""){
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请输入完整的学号！"));
    }
    else{
        //查询数据库是否存在该学号
        QString  sql = QString("select * from students where id = '%1'").arg(xuehao);
        QSqlQuery query(QSqlDatabase::database("chen"));
        query.exec(sql);
        query.first(); //获取第一条

        if(query.value(0).toString() == xuehao){  //如果学号存在（查询到在数据库中）
            //修改数据
            QString  sql = QString("update students set enrollment_data = '%1' where id = '%2'").arg(ruxue).arg(xuehao);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{
            errordlg->setWindowTitle(tr("修改失败！"));
            errordlg->showMessage(tr("修改失败！学号不存在。"));
        }
    }
}


//多项修改修改学院专业
void xiugai::on_pushButton_9_clicked()
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
    QString new_xueyuan = ui->comboBox_3->currentText(); //获取新学院
    QString new_zhuanye = ui->comboBox_4->currentText(); //获取新专业
    //获取性别
    QString xingbie;
    if(ui->radioButton_3->isChecked()){  //男性被选中
        xingbie = ui->radioButton_3->text();
    }
    else if(ui->radioButton_4->isChecked()){  //女性被选中
        xingbie = ui->radioButton_4->text();
    }
    else if(ui->radioButton_5->isChecked()){  //所有被选中
        xingbie = ui->radioButton_5->text();
    }
    //查询数据库是否存在该学院专业
    QString  sql = QString("select * from students where college = '%1' and specialty = '%2'").arg(xueyuan).arg(zhuanye);
    QSqlQuery query(QSqlDatabase::database("chen"));
    query.exec(sql);
    query.first(); //获取第一条
    qDebug()<<query.value(2).toString();
    if(query.value(2).toString() != xueyuan || query.value(3).toString() != zhuanye){ //不存在该学院专业
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请选择正确的学院专业！"));
    }
    else{
        if(xingbie == "所有"){  //如果是所有人
            //修改数据
            QString  sql = QString("update students set college = '%1',specialty = '%2' where college = '%3' and specialty = '%4'").arg(new_xueyuan).arg(new_zhuanye).arg(xueyuan).arg(zhuanye);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{  //仅修改男性或女性
            //查询数据库是否存在该学院专业
            QString  sql = QString("select * from students where college = '%1' and specialty = '%2' and sex = '%3'").arg(xueyuan).arg(zhuanye).arg(xingbie);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            query.first(); //获取第一条
            qDebug()<<query.value(2).toString();
            if(query.value(4).toString() != xingbie ){ //不存在该性别
                errordlg->setWindowTitle(tr("修改失败！"));
                errordlg->showMessage(tr("修改修改！无此性别"));
            }
            else{
                //修改数据
                QString  sql = QString("update students set college = '%1',specialty = '%2' where college = '%3' and specialty = '%4' and sex = '%5'").arg(new_xueyuan).arg(new_zhuanye).arg(xueyuan).arg(zhuanye).arg(xingbie);
                QSqlQuery query(QSqlDatabase::database("chen"));
                query.exec(sql);
                errordlg->setWindowTitle(tr("修改成功！"));
                errordlg->showMessage(tr("修改成功！"));
            }
        }
    }
}


//批量修改修改入学时间
void xiugai::on_pushButton_10_clicked()
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
    QString ruxue = ui->dateEdit_2->text(); //获取入学时间
    //获取性别
    QString xingbie;
    if(ui->radioButton_3->isChecked()){  //男性被选中
        xingbie = ui->radioButton_3->text();
    }
    else if(ui->radioButton_4->isChecked()){  //女性被选中
        xingbie = ui->radioButton_4->text();
    }
    else if(ui->radioButton_5->isChecked()){  //所有被选中
        xingbie = ui->radioButton_5->text();
    }
    //查询数据库是否存在该学院专业
    QString  sql = QString("select * from students where college = '%1' and specialty = '%2'").arg(xueyuan).arg(zhuanye);
    QSqlQuery query(QSqlDatabase::database("chen"));
    query.exec(sql);
    query.first(); //获取第一条

    if(query.value(2).toString() != xueyuan || query.value(3).toString() != zhuanye){ //不存在该学院专业
        errordlg->setWindowTitle(tr("修改失败！"));
        errordlg->showMessage(tr("请选择正确的学院专业！"));
    }
    else{
        if(xingbie == "所有"){  //如果是所有人
            //修改数据
            QString  sql = QString("update students set  enrollment_data = '%1' where college = '%2' and specialty = '%3'").arg(ruxue).arg(xueyuan).arg(zhuanye);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            errordlg->setWindowTitle(tr("修改成功！"));
            errordlg->showMessage(tr("修改成功！"));

        }
        else{  //仅修改男性或女性
            //查询数据库是否存在该学院专业
            QString  sql = QString("select * from students where college = '%1' and specialty = '%2' and sex = '%3'").arg(xueyuan).arg(zhuanye).arg(xingbie);
            QSqlQuery query(QSqlDatabase::database("chen"));
            query.exec(sql);
            query.first(); //获取第一条
            qDebug()<<query.value(2).toString();
            if(query.value(4).toString() != xingbie){ //不存在该性别
                errordlg->setWindowTitle(tr("修改失败！"));
                errordlg->showMessage(tr("修改修改！无此性别"));
            }
            else{
                //修改数据
                QString  sql = QString("update students set enrollment_data = '%1' where college = '%2' and specialty = '%3' and sex = '%4'").arg(ruxue).arg(xueyuan).arg(zhuanye).arg(xingbie);
                QSqlQuery query(QSqlDatabase::database("chen"));
                query.exec(sql);
                errordlg->setWindowTitle(tr("修改成功！"));
                errordlg->showMessage(tr("修改成功！"));
            }
        }
    }
}

