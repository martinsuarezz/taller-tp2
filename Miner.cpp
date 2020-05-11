#include "Miner.h"

void Miner::closeResource(){
    inventory.closeIron();
    inventory.closeCoal();
}