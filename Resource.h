#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

class Resource{
    private:
        const std::string type;

    public:
        Resource(std::string type): type(type){};
        std::string getResourceType() const;
        ~Resource();
};

#endif
