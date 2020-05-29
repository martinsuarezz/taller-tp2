#include "Inventory.h"
#include <iostream>
#include <string>
#include <utility>

void Inventory::addResource(Resource&& resource){
    std::string resourceType = resource.getResourceType();
    if (resourceType == "wheat")
        resources[WHEAT].push(std::move(resource));
    else if (resourceType == "wood")
        resources[WOOD].push(std::move(resource));
    else if (resourceType == "coal")
        resources[COAL].push(std::move(resource));
    else if (resourceType == "iron")
        resources[IRON].push(std::move(resource));
    cv.notify_all();
}

bool Inventory::consumeResources(int wheat, int wood, int coal, int iron){
    std::unique_lock<std::mutex> lock(m);
    int needed_resources[RESOURCE_TYPES] = {wheat, wood, coal, iron};
    int status = 0;
    int count;
    while (true){
        count = 0;
        for (int i = 0; i < RESOURCE_TYPES; i++){
            try{
                status = resources[i].areAvailable(needed_resources[i]);
            }
            catch (ClosedQueueException& e){
                return false;
            }
            
            count += status;
        }
        if (count == RESOURCE_TYPES)
            break;
        cv.wait(lock);
    }
        
    for (int i = 0; i < RESOURCE_TYPES; i++){
        resources[i].remove(needed_resources[i]);
    }
    return true;
}

void Inventory::closeResources(){
    for (int i = 0; i < RESOURCE_TYPES; i++){
        resources[i].close();
    }
    cv.notify_all();
}

void Inventory::printFormatedResources(){
    printf("Recursos restantes:\n");
    printf("  - Trigo: %zu\n", resources[WHEAT].size());
    printf("  - Madera: %zu\n", resources[WOOD].size());
    printf("  - Carbon: %zu\n", resources[COAL].size());
    printf("  - Hierro: %zu\n", resources[IRON].size());
}
