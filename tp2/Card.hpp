#pragma once

#include <string>

enum class Card_enum
{
    sept = 7,
    huit = 8,
    neuf = 9,
    dix = 10,
    valet = 11,
    dame = 12,
    roix = 13,
    as = 14
};

class Card
{
public:
    Card(Card_enum value, const std::string &color);

    void print() const;

    bool operator==(const Card &c2) const; // On ne modifie pas l'objet (const) et on veut eviter les copies (const Card&)

    bool operator<(const Card &c2) const;

    // const std::string &get_color() const { return _color; }

private:
    Card_enum _value;
    std::string _color;
};
