#include "Cooker.h"

bool Cooker::obtainResources(){
    return inventory.consumeResources(2, 0, 1, 0);
}

void Cooker::generatePoints(){
    points.addPoints(5);
}
