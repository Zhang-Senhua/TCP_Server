/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *data_to_send;
    QPushButton *Send_data;
    QTextBrowser *log_show;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *start_server;
    QPushButton *stop_server;
    QPushButton *clear_data;
    QLabel *label;
    QComboBox *server_ip;
    QLabel *label_2;
    QComboBox *listen_com;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *database_name;
    QComboBox *comboBox_3;
    QLabel *user_passwd;
    QComboBox *comboBox_4;
    QPushButton *connect_database;
    QLabel *label_5;
    QComboBox *cloundserver_ip;
    QLabel *label_6;
    QComboBox *cloudserver_com;
    QPushButton *upload_data;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QTextBrowser *device_numbers;
    QLabel *label_8;
    QTextBrowser *listen_state;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(582, 665);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        data_to_send = new QTextEdit(centralWidget);
        data_to_send->setObjectName(QStringLiteral("data_to_send"));
        data_to_send->setGeometry(QRect(10, 100, 371, 31));
        Send_data = new QPushButton(centralWidget);
        Send_data->setObjectName(QStringLiteral("Send_data"));
        Send_data->setGeometry(QRect(400, 100, 171, 31));
        log_show = new QTextBrowser(centralWidget);
        log_show->setObjectName(QStringLiteral("log_show"));
        log_show->setGeometry(QRect(10, 140, 561, 271));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 561, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        start_server = new QPushButton(layoutWidget);
        start_server->setObjectName(QStringLiteral("start_server"));

        gridLayout->addWidget(start_server, 0, 0, 1, 2);

        stop_server = new QPushButton(layoutWidget);
        stop_server->setObjectName(QStringLiteral("stop_server"));

        gridLayout->addWidget(stop_server, 0, 2, 1, 1);

        clear_data = new QPushButton(layoutWidget);
        clear_data->setObjectName(QStringLiteral("clear_data"));

        gridLayout->addWidget(clear_data, 0, 3, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        server_ip = new QComboBox(layoutWidget);
        server_ip->setObjectName(QStringLiteral("server_ip"));

        gridLayout->addWidget(server_ip, 1, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        listen_com = new QComboBox(layoutWidget);
        listen_com->setObjectName(QStringLiteral("listen_com"));

        gridLayout->addWidget(listen_com, 1, 4, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 430, 561, 101));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        database_name = new QLabel(layoutWidget1);
        database_name->setObjectName(QStringLiteral("database_name"));

        gridLayout_2->addWidget(database_name, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(layoutWidget1);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_2->addWidget(comboBox_3, 0, 1, 1, 2);

        user_passwd = new QLabel(layoutWidget1);
        user_passwd->setObjectName(QStringLiteral("user_passwd"));

        gridLayout_2->addWidget(user_passwd, 0, 3, 1, 1);

        comboBox_4 = new QComboBox(layoutWidget1);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_2->addWidget(comboBox_4, 0, 4, 1, 2);

        connect_database = new QPushButton(layoutWidget1);
        connect_database->setObjectName(QStringLiteral("connect_database"));

        gridLayout_2->addWidget(connect_database, 0, 6, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 2);

        cloundserver_ip = new QComboBox(layoutWidget1);
        cloundserver_ip->setObjectName(QStringLiteral("cloundserver_ip"));

        gridLayout_2->addWidget(cloundserver_ip, 1, 2, 1, 2);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 1, 4, 1, 1);

        cloudserver_com = new QComboBox(layoutWidget1);
        cloudserver_com->setObjectName(QStringLiteral("cloudserver_com"));

        gridLayout_2->addWidget(cloudserver_com, 1, 5, 1, 1);

        upload_data = new QPushButton(layoutWidget1);
        upload_data->setObjectName(QStringLiteral("upload_data"));

        gridLayout_2->addWidget(upload_data, 1, 6, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 560, 561, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        device_numbers = new QTextBrowser(layoutWidget2);
        device_numbers->setObjectName(QStringLiteral("device_numbers"));

        horizontalLayout->addWidget(device_numbers);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        listen_state = new QTextBrowser(layoutWidget2);
        listen_state->setObjectName(QStringLiteral("listen_state"));

        horizontalLayout->addWidget(listen_state);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Send_data->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        start_server->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        stop_server->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        clear_data->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\225\260\346\215\256", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP\357\274\232 ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        listen_com->clear();
        listen_com->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5988", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7812", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12121", Q_NULLPTR)
        );
        database_name->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "root", Q_NULLPTR)
        );
        user_passwd->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        connect_database->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\254\345\234\260\346\225\260\346\215\256\345\272\223", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\344\272\221\346\234\215\345\212\241\345\231\250IP:", Q_NULLPTR));
        cloundserver_ip->clear();
        cloundserver_ip->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "120.25.152.4", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243:", Q_NULLPTR));
        upload_data->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\346\225\260\346\215\256\350\207\263\344\272\221\347\253\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\267\262\350\277\236\346\216\245\350\256\276\345\244\207\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
