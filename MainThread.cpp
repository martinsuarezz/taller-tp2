#include "MainThread.h"
#include <unistd.h>
#define GATHERER_TYPES 3
#define PRODUCER_TYPES 3

enum producers{COOKER = 3};

MainThread::MainThread(char* workersFile, char* mapFile): workersFile(workersFile), mapFile(mapFile){
    for (int i = 0; i < GATHERER_TYPES; i++){
        BlockingQueue* queue = new BlockingQueue();
        queues.push_back(queue);
    }
}

//MainThread::~MainThread(){}

void MainThread::spawnSingleWorker(int type){
    Thread* worker;
    if (type == FARMER)
        worker = new Farmer(queues[type], this->inventory);
    else if (type == LUMBERJACK)
        worker = new Lumberjack(queues[type], this->inventory);
    else if (type == MINER)
        worker = new Miner(queues[type], this->inventory);
    else if (type == COOKER)
        worker = new Cooker(points, this->inventory);
    workers.push_back(worker);
    worker->start();
}

void MainThread::spawnWorkers(){
    WorkerParser workerParser(this->workersFile);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < workerParser.getAmmountWorker(i); j++){
            spawnSingleWorker(i);
        }
    }
}

void MainThread::addResources(){
    MapParser mapParser(this->mapFile);
    mapParser.addResources(queues);
    for (int i = 0; i < GATHERER_TYPES; i++)
        queues[i]->close();
}

void MainThread::joinAndDeleteWorkers(){
    for (size_t i = 0; i < workers.size(); i++){
        workers[i]->join();
        delete workers[i];
    }
}

void MainThread::run(){
    this->spawnWorkers();
    this->addResources();
    this->joinAndDeleteWorkers();
    inventory.printFormatedResources();
    points.printFormatedPoints();
}

MainThread::~MainThread(){
    for (size_t i = 0; i < queues.size(); i++)
        delete queues[i];
}

int main(int argc, char* argv[]){
    MainThread* main = new MainThread(argv[1], argv[2]);
    main->start();
    main->join();
    delete main;
}
