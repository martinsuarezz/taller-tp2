#ifndef BLOCKINGQUEUE
#define BLOCKINGQUEUE
#include "Gatherer.h"

class Farmer: public Gatherer{
    public:
        void closeResource();
};

#endif
