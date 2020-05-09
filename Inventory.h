#ifndef INVENTORY_H
#define INVENTORY_H
#include "BlockingQueue.h"
#include "Resource.h"
#include <mutex>
enum resourceType{WHEAT, WOOD, COAL, IRON};
#define RESOURCE_TYPES 4

class Inventory{
    private:
        BlockingQueue resources[RESOURCE_TYPES];
        std::mutex m;
        std::condition_variable cv;

    public:
        Inventory();
        void addResource(Resource* resource);
        int consumeResources(int wheat, int wood, int coal, int iron);
        void closeWheat();
        void closeWood();
        void closeCoal();
        void closeIron();
        ~Inventory();
};

#endif
