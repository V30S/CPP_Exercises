#include "Card.hpp"

int main(int argc, char const *argv[])
{
    const Card c1{Card_enum::huit, "Pique"};
    c1.print();
    return 0;
}
