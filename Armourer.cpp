#include "Armourer.h"

bool Armourer::obtainResources(){
    return inventory.consumeResources(0, 0, 2, 2);
}

void Armourer::generatePoints(){
    points.addPoints(3);
}
