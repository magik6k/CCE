#include "eventPool.h"
#include <time.h>

eventPool::eventPool()
{

}

eventPool& eventPool::getInstance()
{
    static eventPool instance;
    return instance;
}

void eventPool::push(event e)
{
    this->epool.push(e);
}
event eventPool::pool()
{
    while(this->epool.empty())
    {
        timespec tim, tim2;
        tim.tv_sec = 0;
        tim.tv_nsec = 1000000L;

        nanosleep(&tim , &tim2);
    }
    event t = this->epool.front();
    this->epool.pop();
    return t;
}
