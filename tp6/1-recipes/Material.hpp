#pragma once

#include <ostream>
#include <string.h>
#include <iostream>

class Material
{
    // Affiche le nom d'un materiau.
    friend std::ostream &operator<<(std::ostream &stream, const Material &material) { return stream << material._name; }

public:
    Material(const std::string &name) : _name{name}
    {
        std::cout << _name << " was created" << std::endl;
    }

    ~Material()
    {
        std::cout << _name << " was destroyed" << std::endl;
    }

    const std::string &get_name() const { return _name; }

private:
    std::string _name;
};
