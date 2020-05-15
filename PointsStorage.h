#ifndef POINTSSTORAGE_H
#define POINTSSTORAGE_H
#include "Thread.h"
#include "Inventory.h"

class PointsStorage{
    private:
        int points;
        std::mutex m;

    public:
        PointsStorage(): points(0) {};

        // Se agrega la cantidad determinada de puntos.
        void addPoints(int ammount);

        // Se obtiene los puntos acumulados.
        int getPoints() const;

        // Imprime los puntos acumulados.
        void printFormatedPoints() const;
};

#endif