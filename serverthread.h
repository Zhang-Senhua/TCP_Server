#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QObject>
#include <QWidget>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Serverthread: public QThread
{
    Q_OBJECT
public:
     explicit Serverthread(QTcpSocket *Socket);
     void run();
    void protocol(QByteArray buffer);//协议解析的函数
     QByteArray Origin_data;//用于截取数据帧中的数据段

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
