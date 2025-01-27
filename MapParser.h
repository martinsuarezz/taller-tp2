#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <string>
#include <vector>
#include "BlockingQueue.h"

enum workers_id{FARMER, LUMBERJACK, MINER, COOKER, CARPENTER, ARMORER};

// Esta clase se encarga de recibir un archivo del mapa del juego, leerlo
// y depositar los recursos encontrados en las colas correspondientes.
class MapParser{
    private:
        const char* filename;
        const std::string wheat;
        const std::string wood;
        const std::string coal;
        const std::string iron;

    public:
        explicit MapParser(const char* filename): filename(filename),
                                                    wheat("wheat"),
                                                    wood("wood"),
                                                    coal("coal"),
                                                    iron("iron") {}
        void addResources(std::vector<BlockingQueue*>& resourceQueues);
};

#endif
