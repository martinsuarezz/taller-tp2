#include "Gatherer.h"

void Gatherer::run(){
    while (true){
        Resource* resource = queue.pop();
        if (!resource)
            this->closeResource();
        inventory.addResource(resource);
    }
}