#ifndef MAPPARSER_H
#define MAPPARSER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BlockingQueue.h"

enum gatherers{FARMER, LUMBERJACK, MINER};

class MapParser{
    private:
        const char* filename;

    public:
        MapParser(const char* filename): filename(filename) {};
        void addResources(std::vector<BlockingQueue*>& resourceQueues);
};

#endif
