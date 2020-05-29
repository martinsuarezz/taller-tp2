#ifndef CARPENTER_H
#define CARPENTER_H
#include "Producer.h"

// Modela un trabajador carpintero
class Carpenter: public Producer{
    private:
        bool obtainResources() const;
        void generatePoints() const;

    public:
        Carpenter(PointsStorage& points, Inventory& inventory): 
                                            Producer(points, inventory){}
};

#endif
