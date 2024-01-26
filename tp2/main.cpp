#include <iomanip>
#include <iostream>

#include "Card.hpp"

int main(int argc, char const *argv[])
{
    const Card c1{Card_enum::huit, "Pique"};
    std::cout << c1;
    const Card c2{Card_enum::huit, "Carreau"};
    std::cout << (c2 == c1) << std::endl; // -> 1
    const Card c3{Card_enum::dix, "Carreau"};
    std::cout << (c2 == c3) << std::endl; // -> 0
    std::cout << (c1 < c2) << std::endl; // -> 0
    std::cout << (c1 < c3) << std::endl; // -> 1
    std::cout << (c3 < c1) << std::endl; // -> 0
    return 0;
}
