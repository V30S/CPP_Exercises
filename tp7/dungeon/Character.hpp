#pragma once

#include "Entity.hpp"

class Character : public Entity
{
public:
    Character(int x, int y)
        : _x { x }
        , _y { y }
    {}

    char get_representation() const override { return 'O'; }

private:
    int _x;
    int _y;
};
