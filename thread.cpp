#include "thread.h"
#include <iostream>
using namespace std;

void thread::init(void *(*func) (void *), void* dp, unsigned int heapsz)
{
    this->fn = func;
    this->data = dp;

    pthread_attr_t at;
    if (pthread_attr_init(&at) != 0)
    {
        cerr << "ERROR Starting thread\n";
        return;
    }
    if (pthread_attr_setstacksize(&at, heapsz) != 0)
    {
        cerr << "ERROR Setting stack size\n";
        return;
    }
    pthread_create(&(this->thr), &at, this->fn, this->data);
}


thread::thread(void *(*func) (void *))
{
    this->init(func, nullptr, thread_default_heap);
}

thread::thread(void *(*func) (void *), void* dp)
{
    this->init(func, dp, thread_default_heap);
}

thread::thread(void *(*func) (void *), unsigned int heapsz)
{
    this->init(func, nullptr, heapsz);
}

thread::thread(void *(*func) (void *), void* dp, unsigned int heapsz)
{
    this->init(func, dp, heapsz);
}

thread::~thread()
{
    cerr << "[WARNING][CROSE]thread.cpp: tell programmer to kill threads when losing object\n";
}
