#include "Armourer.h"
#include "Inventory.h"
#include "PointsStorage.h"

bool Armourer::obtainResources() const{
    return inventory.consumeResources(0, 0, 2, 2);
}

void Armourer::generatePoints() const{
    points.addPoints(3);
}
