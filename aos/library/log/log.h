//LOG FILE /log/xx.log
#ifndef LOG_H
#define LOG_H
#include<string>
using namespace std;
#define SERVER 0
#define CLIENT 1
#define API    2
#define OTHER  3

class Log {
    public :
        Log(){};
        static void log(string logContent, int logType);
        static void log(const char* filename, int linenum, const char* fct_name, string errMsg, int type);
    private :
        static bool writeLog(string logContent, int type);
        static char* getCurTime();
      

};

#endif
