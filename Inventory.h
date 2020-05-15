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
        //Inventory();

        // Agrega el recurso al inventario
        void addResource(Resource&& resource);

        // Consume los recursos en las cantidades determinadas.
        // Devuelve 1 si los recursos están disponibles.
        // Devuelve 0 si uno o varios recursos no están disponibles
        // y no habrá en el futuro ya que se cerró alguna cola.
        int consumeResources(int wheat, int wood, int coal, int iron);

        // Cierra las colas de recursos, indicando que no van a 
        // llegar más.
        void closeResources();

        // Imprime los recursos disponibles en el inventario.
        void printFormatedResources();
        //~Inventory();
};

#endif
