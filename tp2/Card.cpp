#include <iostream>
#include "Card.hpp"

Card::Card(Card_enum value, const std::string &color) : _value{value}, _color{color} {}

void Card::print() const
{
    std::cout << static_cast<int>(_value) << " de " << _color << std::endl;
}

bool Card::operator==(const Card &c2) const
{
    return c2._value == _value;
}
