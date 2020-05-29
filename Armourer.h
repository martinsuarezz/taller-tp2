#ifndef ARMOURER_H
#define ARMOURER_H
#include "Producer.h"

class Armourer: public Producer{
    private:
        bool obtainResources();
        void generatePoints();

    public:
        Armourer(PointsStorage& points, Inventory& inventory):
                                                 Producer(points, inventory){}
};

#endif
