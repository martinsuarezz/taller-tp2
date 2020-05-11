#ifndef FARMER_H
#define FARMER_H
#include "Gatherer.h"

class Farmer: public Gatherer{
    public:
        Farmer(BlockingQueue* queue, Inventory& inventory): Gatherer(queue, inventory){};
        void closeResource();
        //~Farmer();
};

#endif
