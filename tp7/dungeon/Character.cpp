#include "Character.hpp"

#include "Logger.hpp"

Character::Character(int x, int y)
    : Entity { x, y }
{}

Character::~Character()
{
    logger << "A character died at position (" << get_x() << ", " << get_y() << ")";
}

char Character::get_representation() const
{
    if (_lives == 2)
        return 'O';
    else if (_lives == 1)
        return 'o';
    else
        return ' ';
}

void Character::interact_with(Entity& other)
{
    const auto* trap = dynamic_cast<Trap*>(&other);
    if (trap != nullptr)
    {
        // entity est bien une instance de Trap
        _lives == 0 ? _lives = 0 : _lives--;
    }
    const auto* potion = dynamic_cast<Potion*>(&other);
    if (potion != nullptr)
    {
        // entity est bien une instance de Potion
        _lives == 2 ? _lives = 2 : _lives++;
    }
}

bool Character::should_destroy() const
{
    return _lives == 0;
}

int Character::get_lives() const
{
    return _lives;
}