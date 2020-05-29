#include "WorkerParser.h"
#include <string>
#include <fstream>

WorkerParser::WorkerParser(const char* fileName){
    const std::string workerNames[WORKER_TYPES] = {
                                            "Agricultores", "Leniadores",
                                            "Mineros", "Cocineros"
                                            "Carpinteros", "Armeros"};
    
    std::ifstream file(fileName);
    std::string line;
    for (int i = 0; i < WORKER_TYPES; i++){
        std::getline(file, line);
        for (int j = 0; j < WORKER_TYPES; j++){
            if (line.find(workerNames[j]) == std::string::npos)
                continue;
            
            ammountWorkers[i] = this->readWorkerAmmount(line);
        }
    }
}

int WorkerParser::getAmmountWorker(int workerId){
    return ammountWorkers[workerId];
}

int WorkerParser::readWorkerAmmount(std::string& line){
    int index = line.find("=");
    std::string number = line.substr(index + 1);
    return std::stoi(number);
}
