#ifndef DATABASE_H
#define DATABASE_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

class Database
{


public:

    Database();
    ~Database();
    static bool database_connect();
private:




};


#endif // DATABASE_H
