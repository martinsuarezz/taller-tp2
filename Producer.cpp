#include "Producer.h"
#include <unistd.h>
#include <iostream>
#define PRODUCER_SLEEP 60000

void Producer::run(){
    while (true){
        if (this->obtainResources()){
            usleep(PRODUCER_SLEEP);
            this->generatePoints();
        } else{
            return;
        }
    }
}
