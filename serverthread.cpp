#include "serverthread.h"
#include<QtDebug>
#define data_length 12
#define TURE 1

Serverthread::Serverthread(QTcpSocket *Socket)
{
    sock=Socket;
    mysql_data=new Database();

}

void Serverthread::run()
{
      connect(sock,&QTcpSocket::readyRead,this,&Serverthread::ClientinfoSlots);
}

void Serverthread::ClientinfoSlots()
{
    QByteArray BUF=sock->readAll();
    //读取出来后，进行协议的解析
    protocol(BUF);
  //  qDebug()<<BUF.toHex();
    data_analy(Origin_data);
    if(!mysql_data->data_insert(device_id,on_bed,body_move,heart_rate,breath_rate,log_time))
    {
        qDebug("数据插入失败！\r\n");


    }
    int client_num=sock->peerPort();
    emit SendToWidget(Origin_data,client_num);

}

void Serverthread::data_analy(QByteArray DATA)
{
    QByteArray ID;//设备id
    QByteArray On_Bed;//1表示在床，0表示离床
    QByteArray Body_Move;//1表示存在体动，0表示不存在体动
    QByteArray Heart_Rate;//表示心率
    QByteArray Breath_Rate;//表示呼吸率
    QByteArray Log_time;//时间戳,时间戳是指格林威治时间1970年01月01日00时00分00秒(北京时间1970年01月01日08时00分00秒)起至现在的总秒数。
    QDateTime time_test=QDateTime::currentDateTime();//用于测试
    int TIME_TEST=time_test.toTime_t();
    ID=DATA.mid(0,1);
   //qDebug()<< DATA.toHex();
    On_Bed=DATA.mid(1,1);
    Body_Move=DATA.mid(2,1);
    Breath_Rate=DATA.mid(3,1);
    Heart_Rate=DATA.mid(4,1);
    Log_time=DATA.mid(5,4);
    //qDebug()<< Log_time.toHex();
    device_id=ID.toHex().toInt(NULL,16);
    on_bed=On_Bed.toHex().toInt(NULL,16);
    body_move=Body_Move.toHex().toInt(NULL,16);
    heart_rate=Heart_Rate.toHex().toInt(NULL,16);
    breath_rate=Breath_Rate.toHex().toInt(NULL,16);
    //log_time=Log_time.toHex().toInt(NULL,16);

    log_time=TIME_TEST;//用于测试
    //qDebug()<< log_time;
}

void Serverthread::protocol(QByteArray buffer)
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
    number_pac=buffer.length()/12;
   // qDebug()<< buffer.length();
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
                               for(int i=0;i<9;i++)
                               {
                                   Origin_data[i]=buf_judge[1+i];
                                 //  qDebug()<<Origin_data[i];

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
