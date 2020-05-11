#include "Farmer.h"

//Farmer::Farmer(BlockingQueue& queue, Inventory& inventory): Gatherer(queue, inventory){}

void Farmer::closeResource(){
    inventory.closeWheat();
}

//Farmer::~Farmer(){}