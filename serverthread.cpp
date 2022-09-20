#include "serverthread.h"

Serverthread::Serverthread(QTcpSocket *Socket)
{
    sock=Socket;

}

void Serverthread::run()
{
      connect(sock,&QTcpSocket::readyRead,this,&Serverthread::ClientinfoSlots);
}

void Serverthread::ClientinfoSlots()
{
    QByteArray BUF=sock->readAll();
    int client_num=sock->peerPort();
    emit SendToWidget(BUF,client_num);

}
