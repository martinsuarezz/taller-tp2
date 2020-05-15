#include "Gatherer.h"
#include <unistd.h>
#include <iostream>

void Gatherer::run(){
    while (true){
        try{
            Resource resource = queue->pop();
            usleep(50000);
            inventory.addResource(std::move(resource));
        }
        catch (ClosedQueueException& e){
            return;
        }
    }
}
