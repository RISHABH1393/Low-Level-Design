#include <iostream>
#include "logger.hpp"
#include <thread>
using namespace std;

void userLogger1()
{
    logger *logger1 = logger::getlogger();
    logger1->log("heolllloooo logger1");
}

void userLogger2()
{
    logger *logger2 = logger::getlogger();
    logger2->log("logger2 here");
}
int main()
{
    thread t1(userLogger1);
    thread t2(userLogger2);
    t1.join();
    t2.join();

    return 0;
}

/*
#include <iostream>
#include "logger.hpp"
using namespace std;

int main(){
    logger* logger1 = logger::getlogger();
    logger1->log("heolllloooo logger1");

    logger* logger2 = logger::getlogger();
    logger2->log("logger2 here");

    return 0;
}
*/