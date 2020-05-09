#ifndef GATHERER_H
#define GATHERER_H
#include "Thread.h"
#include "BlockingQueue.h"
#include "Inventory.h"

class Gatherer: public Thread{
    protected:
        BlockingQueue& queue;
        Inventory& inventory;

    public:
        Gatherer(BlockingQueue& queue, Inventory& inventory): queue(queue), inventory(inventory){};
        virtual void run();
        virtual void closeResource() = 0;
        virtual ~Gatherer();
};

#endif
