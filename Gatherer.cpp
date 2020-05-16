#include "Gatherer.h"
#include <unistd.h>
#include <iostream>
#include <utility>

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
