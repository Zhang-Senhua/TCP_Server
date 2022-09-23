#include "database.h"
#define data_length 12
QSqlDatabase  Database::db=QSqlDatabase::addDatabase("QODBC");
Database::Database()
{

}

Database::~Database()
{




}

bool Database::database_connect(){
//使用QOBDC连接到本地的服务器
    bool command;
  //  Database::db = QSqlDatabase::addDatabase("QODBC");
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
          return true;

    }
}

//将解析出来的数据插入数据库
bool Database::data_insert( int device_id, int on_bed,int body_move,int heart_rate,int breath_rate,long int log_time)
{

   QDateTime LOG_TIME= QDateTime::fromTime_t(log_time);
   string_time=LOG_TIME.toString("yyyy-MM-dd hh:mm:ss");
  // qDebug()<<string_time;
   QSqlQuery query(db);
   QString insert_cmd;
   insert_cmd=QString("INSERT INTO Sleep(id,off_bed,body_move,heart_rate,breath_rate,log_time) VALUES('%1','%2','%3','%4','%5','%6')").arg(device_id).arg(on_bed).arg(body_move).arg(heart_rate).arg(breath_rate).arg(string_time);
   if(!query.exec(insert_cmd))
   {
      qDebug()<<("ERROR:"+query.lastError().text());
       return 0;
   }else {
       return 1;

}




}

void Database::protocol(QByteArray buffer)
{
    //函数的作用，封装数据
    QByteArray buf_receive; //用于缓存串口新接收到的数据
    QByteArray buf_judge;   //用于存储待解析数据
    QByteArray temp1;
     static int index_vector=0;
    bool is_packet;      // 判断是否符合数据包的格式
    static int state; // enum枚举类型state所列举的项在程序编译的时候系统会自动给相应的标识字符串赋予一个常量整形值（const）
    state = is_long_enough;    // 因此可将begin等直接赋值于static int 的state
    QByteArray TEMP;
    int number_pac;
     static int index=0;
    QByteArray Not_Completed;
    buf_receive =buffer;
    number_pac=buffer.length()/10;
    qDebug()<< number_pac;
   // qDebug()<<buffer.toHex();
    buf_judge = buf_remained.append(buf_receive);// 将上次剩余的数据流和现在接收到的数据流拼接起来
    //UI->Send_text_window->clear();//调试用
    //UI->Send_text_window->append(QString::number(buf_receive.length()));
    //UI->Send_text_window->append(QString::number(buf_judge.length()));
    while(buf_judge.length() > 0){
        is_packet = true;
        while(is_packet){
              switch(state){
                case is_long_enough: {
                                if(data_length <= buf_judge.length()){
                                    is_packet = true; //当用于判断的数据包长度大于等于12时才进行判断
                                    state = is_head;
                                    //qDebug() <<"is_long_enough";
                                }
                                else {
                                    is_packet = false;
                                    buf_remained.clear();
                                    buf_remained = buf_judge.right(buf_judge.length());
                                    //UI->Send_text_window->append(QString::number(buf_remained.length()));
                                    //UI->Send_text_window->append(buf_remained.toHex());// 调试用
                                  //  qDebug() <<"isn't_long_enough";
                                    return ;   //当数据包长度小于7时保存到下次，然后直接退出这个函数
                                }
                             }break;
                case is_head:{
                                if((unsigned char)buf_judge[0] == 0x5A){
                                    is_packet = true; //判断是数据包帧头后再跳到判断是否帧尾也正确
                                    state = is_end;
                                   // qDebug() <<"is_head";
                                }
                                else{
                                    is_packet = false;
                                    state = is_long_enough; //不是数据帧头
                                    // 防止一直接收不到正确的包导致内存溢出
                                    buf_judge.remove(0,1);//移除数组第一个数据,再判断下一位
                                    // 防止一直接收不到正确的包导致内存溢出
                                  //  qDebug() <<"isn't_head";
                                }
                             }break;
                case is_end: {
                                if(buf_judge[buffer.length()-2] == '\r' && buf_judge[buffer.length()-1] == '\n'){
                                    is_packet = true; //若判断帧尾也正确，则夹在中间的就是要传输的数据
                                    state = is_data;
                                    //qDebug() <<"is_end";
                                }
                                else{
                                    is_packet = false;
                                    state = is_long_enough; //不是帧尾，则说明是假包，i++,再判断下一位
                                    // 防止一直接收不到正确的包导致内存溢出
                                    buf_judge.remove(0,1);//移除数组第一个数据
                                    // 防止一直接收不到正确的包导致内存溢出
                                   // qDebug() <<"isn't_end";
                                }
                             }break;
                case is_data:{
                               for(int i=0;i<10;i++)
                               {
                                   Origin_data[i]=buf_judge[2+i];
                                   qDebug()<<Origin_data[i];
                               }
                              // qDebug()<<temp1.toInt(NULL,16);
                               buf_judge = buf_judge.right(buf_judge.length()-12);

                               //先对buf_judge重新赋值，去掉buf_judge前面的数据，不然若还没跳出for循环会执行多余的步骤
                               buf_remained = buf_judge;
                               //UI->Send_text_window->append(QString::number(buf_remained.length()));//调试用
                               is_packet = false;
                               state = is_long_enough;  //再判断下一位
                             }break;
                default:;
             }
        }
     }


}

