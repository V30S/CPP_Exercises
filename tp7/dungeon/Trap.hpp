#pragma once

#include "Character.hpp"
#include "Item.hpp"

class Trap : public Item
{
public:
    Trap(int width, int height);

    char get_representation() const override;

    void interact_with(Entity& other) override;

private:
};
