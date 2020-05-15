#include "Producer.h"
#include <unistd.h>
#include <iostream>

void Producer::run(){
    while (true){
        if (this->obtainResources()){
            usleep(60000);
            this->generatePoints();
        }
        else{
            return;
        }
    }
}
