#ifndef CARPENTER_H
#define CARPENTER_H
#include "Producer.h"

class Carpenter: public Producer{
    private:
        int obtainResources();
        void generatePoints();

    public:
        Carpenter(PointsStorage& points, Inventory& inventory): 
                                            Producer(points, inventory){}
};

#endif
