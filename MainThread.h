#ifndef MAIN_H
#define MAIN_H
#include "BlockingQueue.h"
#include "Thread.h"
#include "Farmer.h"
#include "MapParser.h"
#include "Lumberjack.h"
#include "Miner.h"
#include "Inventory.h"
#include "WorkerParser.h"
#include <mutex>

class MainThread: public Thread{
    private:
        const char* workersFile;
        const char* mapFile;
        std::vector<Thread*> workers;
        std::vector<BlockingQueue*> queues;
        Inventory inventory;
        void spawnWorkers();
        void spawnSingleWorker(int type);
        void addResources();
        void joinThreads();
        void deleteWorkers();

    public:
        MainThread(char* workersFile, char* mapFile);
        void run();
        //~MainThread();
};

#endif
