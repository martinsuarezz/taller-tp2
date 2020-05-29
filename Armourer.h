#ifndef ARMOURER_H
#define ARMOURER_H
#include "Producer.h"

// Modela un trabajador armero
class Armourer: public Producer{
    private:
        bool obtainResources() const;
        void generatePoints() const;

    public:
        Armourer(PointsStorage& points, Inventory& inventory):
                                                 Producer(points, inventory){}
};

#endif
