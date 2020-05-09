#include "BlockingQueue.h"

void BlockingQueue::push(Resource* resource){
    std::unique_lock<std::mutex> lock(m);
    queue.push(resource);
    cv.notify_all();
}

Resource* BlockingQueue::pop(){
    std::unique_lock<std::mutex> lock(m);
    
    while (queue.empty()){
        if (isClosed){
            return NULL;
        }
        cv.wait(lock);
    }

    Resource* resource = queue.front();
    queue.pop();

    if (queue.empty())
        cv.notify_all();

    return resource;
}

int BlockingQueue::areAvailable(int ammount){
    std::unique_lock<std::mutex> lock(m);
    if ((int) queue.size() < ammount){
        if (isClosed)
            return -1;
        return 0;
    }

    return 1;
}

void BlockingQueue::remove(int ammount){
    std::unique_lock<std::mutex> lock(m);
    for (int i = 0; i < ammount; i++)
        queue.pop();
}

void BlockingQueue::close(){
    std::unique_lock<std::mutex> lock(m);
    isClosed = true;
    cv.notify_all();
}