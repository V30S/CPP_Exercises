#pragma once

#include "Entity.hpp"
#include "Random.hpp"

class Item : public Entity
{
public:
    Item(int width, int height)
        : Entity { random_value(0, width - 1), random_value(0, height - 1) } {};

    void update() override
    { /* Do nothing */
    }

    void consume() { is_consumed = true; }

    bool should_destroy() const override { return is_consumed; }

private:
    bool is_consumed = false;
};
