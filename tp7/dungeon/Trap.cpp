#include "Trap.hpp"

Trap::Trap(int width, int height)
    : Item { width, height }
{}

char Trap::get_representation() const
{
    return 'X';
}

void Trap::interact_with(Entity& other)
{
    const auto* character = dynamic_cast<Character*>(&other);
    if (character != nullptr)
    {
        // entity est bien une instance de Character
        _triggered = true;
    }
}

bool Trap::should_destroy() const
{
    return _triggered;
}