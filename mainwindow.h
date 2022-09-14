#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpServer>
#include <QTcpSocket>
#include"database.h"
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

private:
    Ui::MainWindow *ui;
    QTcpServer *m_tcpServer = nullptr;
    QTcpSocket *m_tcpSocket = nullptr;
     Database *my_database;

};

#endif // MAINWINDOW_H
