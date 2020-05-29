#include "Gatherer.h"
#include <unistd.h>
#include <utility>
#include "Resource.h"
#include "BlockingQueue.h"
#include "Inventory.h"
#define GATHERER_SLEEP 50000

void Gatherer::run(){
    while (true){
        try{
            Resource resource = queue->pop();
            usleep(GATHERER_SLEEP);
            inventory.addResource(std::move(resource));
        }
        catch (ClosedQueueException& e){
            return;
        }
    }
}
