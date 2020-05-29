#ifndef MAIN_H
#define MAIN_H

#include "Thread.h"
#include "Inventory.h"
#include "PointsStorage.h"
#include <mutex>
#include <vector>

class BlockingQueue;

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
