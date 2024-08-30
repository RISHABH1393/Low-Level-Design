#include <iostream>
#include "logger.hpp"
using namespace std;
int logger::cnt = 0;
logger *logger::loggerInstance;
mutex logger::mtx;

logger::logger()
{
    cnt++;
    cout << "new instance of logger cnt " << cnt << endl;
}
void logger::log(string msg)
{
    cout << "message  " << msg << endl;
}

logger *logger::getlogger()
{
    if (loggerInstance == NULL)
    {
        mtx.lock();
        if (loggerInstance == NULL)
        {
            loggerInstance = new logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}
