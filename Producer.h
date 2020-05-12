#ifndef PRODUCER_H
#define PRODUCER_H
#include "Thread.h"
#include "Inventory.h"
#include "PointsStorage.h"

class Producer: public Thread{
    protected:
        PointsStorage& points;
        Inventory& inventory;
        virtual int obtainResources() = 0;
        virtual void generatePoints()= 0;

    public:
        Producer(PointsStorage& points, Inventory& inventory): points(points), inventory(inventory){};
        void run();
};

#endif
