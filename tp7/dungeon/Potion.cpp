#include "Potion.hpp"

Potion::Potion(int width, int height)
    : Item { width, height }
{}

char Potion::get_representation() const
{
    return '$';
}

void Potion::interact_with(Entity& other)
{
    const auto* character = dynamic_cast<Character*>(&other);
    if (character != nullptr)
    {
        // entity est bien une instance de Character
        if (character->get_lives() < 2)
        {
            _used = true;
        }
    }
}

bool Potion::should_destroy() const
{
    return _used;
}