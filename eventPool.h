#include "queue.h"
#include "event.h"

class eventPool
{
    private:
        eventPool();
        data::queue<event> epool;
    public:
        static eventPool& getInstance();
        event pool();
        void push(event e);
};

