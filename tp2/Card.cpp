#include <iostream>
#include "Card.hpp"

Card::Card(Card_enum value, const std::string &color) : _value{value}, _color{color} {}

std::ostream& operator<<(std::ostream& stream, const Card& c)
{
    switch (c._value) {
        case Card_enum::valet : 
            stream << "Valet";
            break;
        case Card_enum::dame : 
            stream << "Dame";
            break;
        case Card_enum::roi : 
            stream << "Roi";
            break;
        case Card_enum::as : 
            stream << "As";
            break;
        default:
            stream << static_cast<int>(c._value);
    }
    stream << " de " << c._color << std::endl;
    return stream;
}

bool Card::operator==(const Card &c2) const
{
    return c2._value == _value;
}

bool Card::operator<(const Card &c2) const
{
    return _value < c2._value;
}
