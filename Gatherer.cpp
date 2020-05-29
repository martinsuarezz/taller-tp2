#include "Gatherer.h"
#include <unistd.h>
#include <utility>
#include "Resource.h"
#include "BlockingQueue.h"
#include "Inventory.h"

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
