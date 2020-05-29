#include "Cooker.h"
#include "Inventory.h"
#include "PointsStorage.h"

bool Cooker::obtainResources() const{
    return inventory.consumeResources(2, 0, 1, 0);
}

void Cooker::generatePoints() const{
    points.addPoints(5);
}
