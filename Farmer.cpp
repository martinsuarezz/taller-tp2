#include "Farmer.h"

//Farmer::Farmer(BlockingQueue& queue, Inventory& inventory): Gatherer(queue, inventory){}

void Farmer::closeResource(){
    inventory.closeWheat();
    printf("No hay mas trigo\n");
}

//Farmer::~Farmer(){}