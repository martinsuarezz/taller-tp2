#ifndef COOKER_H
#define COOKER_H
#include "Producer.h"

// Modela un trabajador cocinero
class Cooker: public Producer{
    private:
        bool obtainResources();
        void generatePoints();

    public:
        Cooker(PointsStorage& points, Inventory& inventory): 
                                            Producer(points, inventory){}
};

#endif
