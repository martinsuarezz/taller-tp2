#include "Inventory.h"

Inventory::Inventory(){}

void Inventory::addResource(Resource* resource){
    std::string resourceType = resource->getResourceType();
    if (resourceType == "wheat")
        resources[WHEAT].push(resource);
    else if (resourceType == "wood")
        resources[WOOD].push(resource);
    else if (resourceType == "coal")
        resources[COAL].push(resource);
    else if (resourceType == "iron")
        resources[IRON].push(resource);
}

int Inventory::consumeResources(int wheat, int wood, int coal, int iron){
    std::unique_lock<std::mutex> lock(m);
    int needed_resources[RESOURCE_TYPES] = {wheat, wood, coal, iron};
    int error = 0;
    int count = 0;
    while (count != RESOURCE_TYPES){
        for (int i = 0; i < RESOURCE_TYPES; i++){
            error = resources[i].areAvailable(needed_resources[i]);
            if (error == -1)
                return 0;
            count += error;
        }
        cv.wait(lock);
    }
        
    for (int i = 0; i < RESOURCE_TYPES; i++){
        resources[i].remove(needed_resources[i]);
    }
    return 1;
}

void Inventory::closeWheat(){
    resources[WHEAT].close();
}

void Inventory::closeWood(){
    resources[WOOD].close();
}

void Inventory::closeCoal(){
    resources[COAL].close();
}

void Inventory::closeIron(){
    resources[IRON].close();
}

Inventory::~Inventory(){}