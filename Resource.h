#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

class Resource{
    private:
        const std::string type;

    public:
        Resource(std::string type): type(type){};

        // Devuelve el nombre del recurso.
        std::string getResourceType() const;
};

#endif
