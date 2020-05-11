#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Resource.h"

class BlockingQueue{
    private:
        std::queue<Resource> queue;
        bool isClosed;
        std::mutex m;
        std::condition_variable cv;

    public:
        BlockingQueue(): isClosed(false){};

        // Obtiene el primer recurso de la cola. 
        // Pasaje por movimiento.
        Resource pop();

        // Se añade un recurso a la cola.
        void push(Resource&& resource);

        // Pregunta si la cola tiene como minimo la
        // cantidad 'ammount' de elementos.
        // Devuelve 1 si tiene más o igual cantidad de elementos
        // que ammount.
        // Devuelve 0 si tiene menos elementos que ammount.
        // Devuelve -1 si tiene menos elementos que ammount
        // y la cola está cerrada.
        int areAvailable(int ammount);

        // Remueve la cantidad determinada de elementos de la cola.
        void remove(int ammount);

        // Devuelve la cantidad de elementos de la cola.
        size_t size();

        // Cierra la cola indicando que no se le añadirán más elementos.
        void close();
        
        //~BlockingQueue();
};

#endif
