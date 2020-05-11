#ifndef MINER_H
#define MINER_H
#include "Gatherer.h"

class Miner: public Gatherer{
    public:
        Miner(BlockingQueue* queue, Inventory& inventory): Gatherer(queue, inventory){};
        void closeResource();
};

#endif
