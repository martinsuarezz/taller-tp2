#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

class Resource{
    private:
        const std::string type;

    public:
        explicit Resource(const std::string& type): type(type){}

        // Devuelve el nombre del recurso.
        const std::string& getResourceType() const;
};

#endif
