#include "Carpenter.h"

int Carpenter::obtainResources(){
    return inventory.consumeResources(0, 3, 0, 1);
}

void Carpenter::generatePoints(){
    points.addPoints(2);
}
