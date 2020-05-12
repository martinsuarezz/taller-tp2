#include "Gatherer.h"
#include <unistd.h>
#include <iostream>

//Gatherer::Gatherer(BlockingQueue& queue, Inventory& inventory): queue(queue), inventory(inventory){}

void Gatherer::run(){
    printf("Servidor!\n");
    
    while (true){
        try{
            Resource resource = queue->pop();
            usleep(50000);
            std::cout << "Processing " << resource.getResourceType() << std::endl;
            inventory.addResource(std::move(resource));
            if (queue->areAvailable(1) == -1)
                this->closeResource();
        }
        catch (const char* msg){
            return;
        }
    }
}

//Gatherer::~Gatherer(){}
