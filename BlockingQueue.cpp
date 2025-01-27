#include "BlockingQueue.h"
#include <utility>

void BlockingQueue::push(Resource&& resource){
    std::unique_lock<std::mutex> lock(m);
    queue.push(resource);
    cv.notify_all();
}

Resource BlockingQueue::pop(){
    std::unique_lock<std::mutex> lock(m);
    
    while (queue.empty()){
        if (isClosed){
            throw ClosedQueueException();
        }
        cv.wait(lock);
    }

    Resource& resource = queue.front();
    queue.pop();

    return std::move(resource);
}

int BlockingQueue::areAvailable(int ammount){
    std::unique_lock<std::mutex> lock(m);
    if ((int) queue.size() < ammount){
        if (isClosed)
            throw ClosedQueueException();
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

size_t BlockingQueue::size(){
    std::unique_lock<std::mutex> lock(m);
    return queue.size();
}
