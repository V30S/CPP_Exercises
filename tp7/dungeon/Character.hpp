#pragma once

#include "Entity.hpp"
#include "Potion.hpp"
#include "Trap.hpp"

class Character : public Entity
{
public:
    Character(int x, int y);

    char get_representation() const override;

    void interact_with(Entity& other) override;

    bool should_destroy() const override;

    int get_lives() const;

private:
    int _lives = 2;
};
