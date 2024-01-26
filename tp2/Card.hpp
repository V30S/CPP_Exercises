#pragma once

#include <string>
#include <iostream>

enum class Card_enum
{
    sept = 7,
    huit = 8,
    neuf = 9,
    dix = 10,
    valet = 11,
    dame = 12,
    roi = 13,
    as = 14
};

class Card
{

friend std::ostream& operator<<(std::ostream& stream, const Card& c);

public:
    Card(Card_enum value, const std::string &color);

    bool operator==(const Card &c2) const; // On ne modifie pas l'objet (const) et on veut eviter les copies (const Card&)

    bool operator<(const Card &c2) const;

    // const std::string &get_color() const { return _color; }

private:
    Card_enum _value;
    std::string _color;
};
