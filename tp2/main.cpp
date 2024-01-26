#include <iomanip>
#include <iostream>

#include "Card.hpp"

int main(int argc, char const *argv[])
{
    const Card c1{Card_enum::huit, "Pique"};
    c1.print();
    Card c2{Card_enum::huit, "Carreau"};
    std::cout << (c2 == c1) << std::endl; // -> 1
    Card c3{Card_enum::dix, "Carreau"};
    std::cout << (c2 == c3) << std::endl; // -> 0
    return 0;
}
