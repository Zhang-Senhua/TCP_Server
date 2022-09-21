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
     void Protocol_analy(); //协议解析的函数

signals:
    void SendToWidget(QByteArray ba,int client);

public slots:
    void ClientinfoSlots();
    //void Thread_slot();

private:
    QTcpSocket *sock;



};

#endif // SERVERTHREAD_H
