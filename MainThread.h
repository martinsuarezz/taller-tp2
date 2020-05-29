#ifndef MAIN_H
#define MAIN_H
#include "BlockingQueue.h"
#include "Thread.h"
#include "MapParser.h"
#include "Gatherer.h"
#include "Cooker.h"
#include "Carpenter.h"
#include "Armourer.h"
#include "Inventory.h"
#include "WorkerParser.h"
#include <mutex>
#include <vector>

class MainThread: public Thread{
    private:
        const char* workersFile;
        const char* mapFile;
        std::vector<Thread*> gatherers;
        std::vector<Thread*> producers;
        std::vector<BlockingQueue*> queues;
        Inventory inventory;
        PointsStorage points;
        void spawnWorkers();
        int spawnSingleWorker(int type);
        void addResources();
        void joinAndDeleteGatherers();
        void joinAndDeleteProducers();
        void printResults();

    public:
        MainThread(const char* workersFile, const char* mapFile);
        void run();
        ~MainThread();
};

#endif
