#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QObject>
#include <QWidget>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include"database.h"

class Serverthread: public QThread
{
    Q_OBJECT
public:
     explicit Serverthread(QTcpSocket *Socket);
     void run();
    void protocol(QByteArray buffer);//协议解析的函数
     QByteArray Origin_data;//用于截取数据帧中的数据段
     void data_analy(QByteArray DATA);
     Database *mysql_data;
     int device_id;//设备id
     int on_bed;//1表示在床，0表示离床
     int body_move;//1表示存在体动，0表示不存在体动
     int heart_rate;//表示心率
     int breath_rate;//表示呼吸率
     long int log_time;//时间戳,时间戳是指格林威治时间1970年01月01日00时00分00秒(北京时间1970年01月01日08时00分00秒)起至现在的总秒数。

signals:
    void SendToWidget(QByteArray ba,int client);

public slots:
    void ClientinfoSlots();
    //void Thread_slot();

private:
    QTcpSocket *sock;
    enum State{is_long_enough,is_head,is_end,is_data};// 列举数据包解析存在的状态
    QByteArray buf_remained; // 存储之前没有处理完的数据
    union MyUnion
    {
    unsigned char buf[4];
    float f;
    }FLOAT_DATA;

    union MyUnion1
    {
    unsigned char buf[2];
    uint16_t f;
    }FLOAT_body_dis;




};

#endif // SERVERTHREAD_H
