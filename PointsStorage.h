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
        void addPoints(int ammount);
        int getPoints() const;
        void printFormatedPoints() const;
};

#endif
