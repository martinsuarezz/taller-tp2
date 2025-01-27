#ifndef PRODUCER_H
#define PRODUCER_H
#include "Thread.h"

class PointsStorage;
class Inventory;

// Esta clase abstracta modela a los productores.
class Producer: public Thread{
    protected:
        PointsStorage& points;
        Inventory& inventory;

        // Obtiene los reecursos necesarios del inventario.
        // Cada clase que hereda de productor debe implementarlo.
        virtual bool obtainResources() const = 0;

        // Genera puntos que agrega al contador de puntos.
        // Cada clase que hereda de productor debe implementarlo.
        virtual void generatePoints() const = 0;

    public:
        Producer(PointsStorage& points, Inventory& inventory): 
                                        points(points), inventory(inventory){}
        void run();
};

#endif
