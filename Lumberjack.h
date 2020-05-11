#ifndef LUMBERJACK_H
#define LUMBERJACK_H
#include "Gatherer.h"

class Lumberjack: public Gatherer{
    public:
        Lumberjack(BlockingQueue* queue, Inventory& inventory): Gatherer(queue, inventory){};
        void closeResource();
};

#endif
