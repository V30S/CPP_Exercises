#include <iostream>
#include "Card.hpp"

Card::Card(Card_enum value, const std::string &color) : _value{value}, _color{color} {}

void Card::print() const
{
    switch (_value) {
        case Card_enum::valet : 
            std::cout << "Valet";
            break;
        case Card_enum::dame : 
            std::cout << "Dame";
            break;
        case Card_enum::roi : 
            std::cout << "Roi";
            break;
        case Card_enum::as : 
            std::cout << "As";
            break;
        default:
            std::cout << static_cast<int>(_value);
    }
    std::cout << " de " << _color << std::endl;
}

bool Card::operator==(const Card &c2) const
{
    return c2._value == _value;
}

bool Card::operator<(const Card &c2) const
{
    return _value < c2._value;
}
