#include "Inventory.h"
#include <iostream>

//Inventory::Inventory(){}

void Inventory::addResource(Resource&& resource){
    std::string resourceType = resource.getResourceType();
    std::cout << "Storing " << resourceType << std::endl;
    if (resourceType == "wheat")
        resources[WHEAT].push(std::move(resource));
    else if (resourceType == "wood")
        resources[WOOD].push(std::move(resource));
    else if (resourceType == "coal")
        resources[COAL].push(std::move(resource));
    else if (resourceType == "iron")
        resources[IRON].push(std::move(resource));
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

void Inventory::printFormatedResources(){
    printf("Recursos restantes:\n");
    printf("   - Trigo: %lu\n", resources[WHEAT].size());
    printf("   - Madera: %lu\n", resources[WOOD].size());
    printf("   - Carbon: %lu\n", resources[COAL].size());
    printf("   - Hierro: %lu\n", resources[IRON].size());
}

//Inventory::~Inventory(){}
