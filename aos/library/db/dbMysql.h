#ifndef DB_MYSQL_H
#define DB_MYSQL_H

#include<mysql.h>
#include<string>
#include<iostream>
using namespace std;

class DBMysql {
    public:
        DBMysql();
        bool initDB(string server_host, string username, string passwd, string db_name);
        string executeSQL(string sql_str);
        bool create_table(string table_str_sql);
        ~DBMysql();
    private:
        MYSQL* connection;
        MYSQL_RES *res;
        MYSQL_ROW row;
};

#endif
