#include <string>
#define WORKER_TYPES 6

// Esta clase se encarga de leer el archivo de distribución
// de trabajadores.
class WorkerParser{
    private:
        int ammountWorkers[WORKER_TYPES];
        int readWorkerAmmount(std::string& line);

    public:
        explicit WorkerParser(const char* fileName);

        // Devuelve la cantidad de cierto tipo de trabajador
        int getAmmountWorker(int workerId) const;
};
