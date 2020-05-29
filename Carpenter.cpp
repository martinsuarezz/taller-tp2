#include "Carpenter.h"
#include "Inventory.h"
#include "PointsStorage.h"

bool Carpenter::obtainResources() const{
    return inventory.consumeResources(0, 3, 0, 1);
}

void Carpenter::generatePoints() const{
    points.addPoints(2);
}
