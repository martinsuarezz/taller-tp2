#include "Producer.h"
#include <unistd.h>
#include <iostream>

void Producer::run(){
    printf("Productor!\n");
    
    while (true){
        if (this->obtainResources()){
            usleep(60000);
            std::cout << "Cooking" << std::endl;
            this->generatePoints();
        }
        else{
            return;
        }
    }
}
