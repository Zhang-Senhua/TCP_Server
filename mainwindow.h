#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QTcpServer>
#include<QTcpSocket>
#include"database.h"
#include<QThread>
#include"serverthread.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_server_clicked();

    void on_stop_server_clicked();

    void on_clear_data_clicked();

    void on_newConnection();
    void onConnected();

    void onDisConnected();

    //void onStateChanged(QAbstractSocket::SocketState socketState);

    void onReadyRead();

    void on_Send_data_clicked();

    void on_connect_database_clicked();
    void ThreadSlots(QByteArray DATA,int client);

private:
    Ui::MainWindow *ui;
    QTcpServer *m_tcpServer = nullptr;
    QTcpSocket  *m_tcpSocket = nullptr;
    Database *my_database;
    int count;//用于计算连接设备数

};

#endif // MAINWINDOW_H
