#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Resource.h"

class BlockingQueue{
    private:
        std::queue<Resource*> queue;
        bool isClosed;
        std::mutex m;
        std::condition_variable cv;

    public:
        BlockingQueue(): isClosed(false){};
        Resource* pop();
        void push(Resource* resource);
        int areAvailable(int ammount);
        void remove(int ammount);
        void close();
        ~BlockingQueue();
};

#endif
