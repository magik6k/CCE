#pragma once
#include <pthread.h>
#define thread_default_heap (512*1024)


class thread
{
    private:
        void* data;
        void *(*fn) (void *);
        pthread_t thr;
        void init(void *(*func) (void *), void* dp, unsigned int heapsz);

    public:
        thread(void *(*func) (void *));
        thread(void *(*func) (void *), void* dp);
        thread(void *(*func) (void *), unsigned int heapsz);
        thread(void *(*func) (void *), void* dp, unsigned int heapsz);
        ~thread();
};
