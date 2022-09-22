#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostInfo>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("服务器");
    //本地主机名
    QString hostName = QHostInfo::localHostName();

    //本机IP地址
    QHostInfo hostInfo = QHostInfo::fromName(hostName);

    //IP地址列表
    QList<QHostAddress> addrList = hostInfo.addresses();
    for(int i=0;i<addrList.count();i++)
    {
        QHostAddress host = addrList.at(i);

        if(QAbstractSocket::IPv4Protocol == host.protocol())
        {
            QString ip = host.toString();
            ui->server_ip->addItem(ip);


        }
    }
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer,&QTcpServer::newConnection,this,&MainWindow::on_newConnection);
    my_database=new Database();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_server_clicked()
{
    //当前选择的ip
    QString ip = ui->server_ip->currentText();
    //端口
    int port = ui->listen_com->currentText().toInt();
    QHostAddress addr(ip);
    //监听
    m_tcpServer->listen(addr,port);
    ui->start_server->setDisabled(true);
    ui->stop_server->setDisabled(false);
    ui->log_show->append("开始监听！");
    ui->log_show->append("**服务器地址: "+m_tcpServer->serverAddress().toString());
    ui->log_show->append("**服务器端口: "+QString::number(m_tcpServer->serverPort()));
    ui->listen_state->setText("正在监听");


}

void MainWindow::on_stop_server_clicked()
{
    if(m_tcpServer->isListening())
       {

           m_tcpServer->close();
           ui->listen_state->setText("停止监听");
           ui->log_show->append("**停止监听**");
           ui->stop_server->setDisabled(true);
           ui->start_server->setDisabled(false);
       }

}

void MainWindow::on_clear_data_clicked()
{

}

void MainWindow::on_newConnection()
{


    m_tcpSocket = m_tcpServer->nextPendingConnection();
    count++;
    connect(m_tcpSocket,&QTcpSocket::connected,this,&MainWindow::onConnected);
    connect(m_tcpSocket,&QTcpSocket::disconnected,this,&MainWindow::onDisConnected);
   // connect(m_tcpSocket,&QTcpSocket::stateChanged,this,&MainWindow::onStateChanged);
 //   connect(m_tcpSocket,&QTcpSocket::readyRead,this,&MainWindow::onReadyRead);

    //使用多线程访问
    Serverthread *thread_server=new Serverthread(m_tcpSocket);
   thread_server->start();
   connect(thread_server,&Serverthread::SendToWidget,this,&MainWindow::ThreadSlots);
  //  serverThread *server_thread=new serverThread(m_tcpSocket);
    ui->log_show->append("** client socket connected");
    ui->log_show->append("** peer address: "+m_tcpSocket->peerAddress().toString());
    ui->log_show->append("** peer port: "+QString::number(m_tcpSocket->peerPort()));
    ui->device_numbers->clear();
    ui->device_numbers->setPlainText(QString::number(count));
  // qDebug()<<count;
}

void MainWindow::ThreadSlots(QByteArray DATA,int client)
{
    //线程返回数据
     ui->log_show->append("client:"+QString::number(client)+"  "+DATA);

}
void MainWindow::onConnected()
{
    ui->log_show->append("** client socket connected");
    ui->log_show->append("** peer address: "+m_tcpSocket->peerAddress().toString());
    ui->log_show->append("** peer port: "+QString::number(m_tcpSocket->peerPort()));
}

void MainWindow::onDisConnected()
{
    ui->log_show->append("** client socket disconnected");
    count--;
    ui->device_numbers->clear();
    ui->device_numbers->setPlainText(QString::number(count));
    m_tcpSocket->deleteLater();
}

void MainWindow::on_Send_data_clicked()
{
    QString msg =ui->data_to_send->toPlainText();
    ui->log_show->append("server:"+msg);
    QByteArray str = msg.toUtf8();
    str.append('\n');
    m_tcpSocket->write(str);
}

void MainWindow::onReadyRead()
{
     QString recvMsg =m_tcpSocket->readAll();
     ui->log_show->append("client:"+recvMsg);
}

void MainWindow::on_connect_database_clicked()
{
    int temp;
    temp=my_database->database_connect();

}
