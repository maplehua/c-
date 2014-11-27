#include<iostream>
#include<unistd.h>
#include<time.h>
#include<sstream>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string>
#include "log.h"
using namespace std;

char* Log::getCurTime() {
    time_t time_cur;
    time(&time_cur);
    return asctime(gmtime(&time_cur));
}

bool Log::writeLog(string logContent, int type) {
    string filename;
    switch(type) {
        case SERVER:
            filename = "/home/xiaohua/git/aos/log/server.log";
            break;
        case CLIENT:
            filename = "/home/xiaohua/git/aos/log/client.log";
            break;
        case API:
            filename = "/home/xiaohua/git/aos/log/api.log";
            break;
        case OTHER:
            filename = "/home/xiaohua/git/aos/log/other.log";
            break;
        default:
            filename = "/home/xiaohua/git/aos/log/other.log";
            break;
    }
    int fd = open(filename.c_str(), O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd < 0) {
        return false;
    }
    string time(getCurTime());
    time.append(logContent+"\n");
    if (write(fd, time.c_str(), strlen(time.c_str())) != strlen(time.c_str())) {
        return false;
    }
    close(fd);
    
}

void Log::log(string content, int type) {
    writeLog(content, type);
}

void Log::log(const char* filename, int linenum, const char* fct_name, string errMsg, int type) {
    string tmp_str="";
    tmp_str.append(filename);
    tmp_str.append("   ");
    stringstream ss;
    ss<<linenum;
    string tmp;
    ss>>tmp;
    tmp_str.append(tmp);
    tmp_str.append("   ");
    tmp_str.append(fct_name);
    tmp_str.append("   ");
    tmp_str.append(errMsg);
    log(tmp_str, type);
}
