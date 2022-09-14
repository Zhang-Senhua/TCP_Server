#include "database.h"

Database::Database()
{

}

Database::~Database()
{




}

bool Database::database_connect(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Data_Radar");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("TsNs2796");   //这里输入你的密码
    if (!db.open()) {
    QMessageBox::critical(0, QObject::tr("无法打开数据库"),
    "无法创建数据库连接！ ", QMessageBox::Cancel);
    return false;
    }
    else {
        QMessageBox::information(0, QObject::tr("成功打开数据库"),
        "已创建创建数据库连接！ ", QMessageBox::Cancel);
        //下面来创建表
       //    如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
        QSqlQuery query(db);
        // 使数据库支持中文
        query.exec("SET NAMES 'Latin1'");
        // 创建 course 表
        query.exec("create table course (id int primary key, "
        "name varchar(20), teacher varchar(20))");
        query.exec("insert into course values(0, '数学', '刘老师')");
        query.exec("insert into course values(1, '英语', '张老师')");
        query.exec("insert into course values(2, '计算机', '李老师')");

          return true;

    }
}

