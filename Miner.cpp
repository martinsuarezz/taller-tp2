#include "Miner.h"

void Miner::closeResource(){
    inventory.closeIron();
    inventory.closeCoal();
    printf("No hay mas hierro ni carbon\n");
}