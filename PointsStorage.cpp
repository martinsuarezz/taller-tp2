#include "PointsStorage.h"
#include <iostream>

void PointsStorage::addPoints(int ammount){
    std::unique_lock<std::mutex> lock(m);
    points += ammount;
}

int PointsStorage::getPoints() const{
    return points;
}

void PointsStorage::printFormatedPoints() const{
    printf("Puntos de Beneficio acumulados: %i\n", points);
}
