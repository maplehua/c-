#include<iostream>
#include "dbMysql.h"

using namespace std;

int main()
{
    DBMysql db;
    db.initDB("localhost", "root", "20062017", "xiaohua");
    string s ;
    s = db.executeSQL("select content,answer from civil_exam limit 1;");
    cout<<s<<endl;

    return 0;
}
