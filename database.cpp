#include "database.h"

Database::Database()
{

}

Database::~Database()
{




}

bool Database::database_connect(){
//使用QOBDC连接到本地的服务器
    bool command;
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
        command=query.exec("CREATE TABLE IF NOT EXISTS Sleep(id int,off_bed int,body_move int,heart_rate int,breath_rate int,log_time datetime)");
        //id表示设备Id,off_bed 表示是否在床，body_move表示是否体动，heart表示心率，breath表示呼吸，log_time表示log时间
        if(!command)
        {
            QMessageBox::information(0, QObject::tr("创建表失败"),
            "创建表失败 ", QMessageBox::Cancel);
        }
//        query.exec("insert into course values(0, '数学', '刘老师')");
//        query.exec("insert into course values(1, '英语', '张老师')");
//        query.exec("insert into course values(2, '计算机', '李老师')");
          return true;

    }
}

