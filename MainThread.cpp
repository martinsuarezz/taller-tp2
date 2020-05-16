#include "MainThread.h"
#include <unistd.h>
#include <array>
#define GATHERER_TYPES 3
#define PRODUCER_TYPES 3

static bool isGatherer(int type){
    return type <= 2;
}

MainThread::MainThread(char* workersFile, char* mapFile): 
                                workersFile(workersFile), mapFile(mapFile){
    for (int i = 0; i < GATHERER_TYPES; i++){
        BlockingQueue* queue = new BlockingQueue();
        queues.push_back(queue);
    }
}

void MainThread::spawnSingleWorker(int type){
    Thread* worker;
    if (type == FARMER)
        worker = new Gatherer(queues[type], this->inventory);
    else if (type == LUMBERJACK)
        worker = new Gatherer(queues[type], this->inventory);
    else if (type == MINER)
        worker = new Gatherer(queues[type], this->inventory);
    else if (type == COOKER)
        worker = new Cooker(points, this->inventory);
    else if (type == CARPENTER)
        worker = new Carpenter(points, this->inventory);
    else if (type == ARMORER)
        worker = new Armourer(points, this->inventory);
    worker->start();

    if (isGatherer(type))
        gatherers.push_back(worker);
    else 
        producers.push_back(worker);
}

void MainThread::spawnWorkers(){
    WorkerParser workerParser(this->workersFile);
    for (int i = 0; i < 6; i++){
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

void MainThread::joinAndDeleteGatherers(){
    for (size_t i = 0; i < gatherers.size(); i++){
        gatherers[i]->join();
        delete gatherers[i];
    }
}

void MainThread::joinAndDeleteProducers(){
    for (size_t i = 0; i < producers.size(); i++){
        producers[i]->join();
        delete producers[i];
    }
}

void MainThread::run(){
    this->spawnWorkers();
    this->addResources();
    this->joinAndDeleteGatherers();
    inventory.closeResources();
    this->joinAndDeleteProducers();
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
