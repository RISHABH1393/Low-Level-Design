#ifndef logger_hpp
#define logger_hpp
#include <string>
#include <mutex>
using namespace std;

class logger
{
    static int cnt;
    static logger* loggerInstance;
    static mutex mtx;
    logger();
public:
    
    void log(string msg);
    static logger* getlogger();
};
#endif