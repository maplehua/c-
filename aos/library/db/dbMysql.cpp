#include<iostream>
#include<string>
#include<string.h>
#include "dbMysql.h"
#include<mysql.h>
#include "../log/log.h"
using namespace std;

DBMysql::DBMysql() {
    connection = mysql_init(NULL);
    if (connection == NULL) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"mysql init error", 2);
        return;
    }
}

DBMysql::~DBMysql() {
    if (connection != NULL) {
        mysql_close(connection);
    }
}

bool DBMysql::initDB(string server_host, string username, string passwd, string db_name) {
    connection = mysql_real_connect(connection, server_host.c_str(), username.c_str(), passwd.c_str(), db_name.c_str(), 0, NULL, 0);
    if (connection == NULL) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,"mysql real connect error", 2);
        return false;
    }
    return true;
}

string DBMysql::executeSQL(string str_sql) {
    string result = "";
    if (mysql_query(connection, "set names utf8")) {// utf8 not utf-8
        Log::log(__FILE__,__LINE__,__FUNCTION__,string("set names error ")+string(mysql_error(connection)), 2);
        return NULL;
    }
    int t = mysql_query(connection, str_sql.c_str());
    if (t) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,string("Error making query : ")+string(mysql_error(connection)), 2); 
        return NULL;
    } else {
        res = mysql_use_result(connection);
        if (res) {
            //mysql_field_count : return the query lines
            for (int i=0; i<mysql_field_count(connection); i++) {
                //get a result
                row = mysql_fetch_row(res);
                if (row < 0) {
                    break;
                }
                //cout<<"row = "<<row[5]<<endl;
                //for (int i=0; i<strlen(*row); i++)
                //cout<<"row = "<<row[i]<<endl;
                //cout<<"column = "<<mysql_num_fields(res)<<endl;
                //mysql_num_fields(res) : columns
                for (int r=0; r<mysql_num_fields(res); r++) {
                    cout<<row[r]<<"\t";
                    //cout<<"11111"<<endl;
                    result.append(row[r]);
                }
                cout<<endl;
            }
        }
    }
    mysql_free_result(res);

    return result;
}

bool DBMysql::create_table(string table_str_sql) {
    int t = mysql_query(connection, table_str_sql.c_str());
    if (t) {
        Log::log(__FILE__,__LINE__,__FUNCTION__,string("create table error")+string(mysql_error(connection)), 2);
        return false;
    }
    return true;
}
