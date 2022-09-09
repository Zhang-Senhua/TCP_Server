#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
       }

}

void MainWindow::on_clear_data_clicked()
{

}

void MainWindow::on_newConnection()
{

}
