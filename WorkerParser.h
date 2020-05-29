#include <iostream>
#include <string>
#include <fstream>
#define WORKER_TYPES 6

class WorkerParser{
    private:
        int ammountWorkers[WORKER_TYPES];
        int readWorkerAmmount(std::string& line);

    public:
        explicit WorkerParser(const char* fileName);
        int getAmmountWorker(int workerId);
};
