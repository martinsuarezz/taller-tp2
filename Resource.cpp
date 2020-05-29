#include "Resource.h"
#include <string>

const std::string& Resource::getResourceType() const{
    return this->type;
}
