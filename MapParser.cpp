#include "MapParser.h"
#include "Inventory.h"
#include <string>
#include <vector>

void MapParser::addResources(std::vector<BlockingQueue*>& resourceQueues){
    std::ifstream file(this->filename);
    std::string line;

    while (std::getline(file, line)){
        for (size_t i = 0; i < line.size(); i++){
            const char character = line[i];
            if (character == 'T')
                resourceQueues[FARMER]->push(Resource("wheat"));
            else if (character == 'M')
                resourceQueues[LUMBERJACK]->push(Resource("wood"));
            else if (character == 'C')
                resourceQueues[MINER]->push(Resource("coal"));
            else if (character == 'H')
                resourceQueues[MINER]->push(Resource("iron"));
        }
    }
}
