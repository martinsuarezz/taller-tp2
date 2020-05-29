#ifndef INVENTORY_H
#define INVENTORY_H
#include "BlockingQueue.h"
#include <mutex>
enum resourceType{WHEAT, WOOD, COAL, IRON};
#define RESOURCE_TYPES 4

class Resource;

// Modela el inventario del juego donde los recolectores depositan
// sus recursos y los productores obtienen los suyos.
// El acceso a consumeResources es atómico.
class Inventory{
    private:
        BlockingQueue resources[RESOURCE_TYPES];
        std::mutex m;
        std::condition_variable cv;

    public:
        // Agrega el recurso al inventario
        void addResource(Resource&& resource);

        // Consume los recursos en las cantidades determinadas.
        // Devuelve true si los recursos están disponibles.
        // Devuelve false si uno o varios recursos no están disponibles
        // y no habrá en el futuro ya que se cerró alguna cola.
        bool consumeResources(int wheat, int wood, int coal, int iron);

        // Cierra las colas de recursos, indicando que no van a 
        // llegar más.
        void closeResources();

        // Imprime los recursos disponibles en el inventario.
        void printFormatedResources();
};

#endif
