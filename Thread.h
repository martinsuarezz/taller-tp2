#ifndef THREAD_H
#define THREAD_H
#include <thread>

class Thread{
    private:
        std::thread thread;

    public:
        Thread();
        void start();
        void join();
        virtual void run() = 0;
        virtual ~Thread();
};

#endif
