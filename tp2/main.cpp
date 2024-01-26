#include <iomanip>
#include <iostream>

#include "Player.hpp"

int main(int argc, char const *argv[])
{
    Player p1{"Gerald"};
    Player p2{"Julien"};
    Player::deal_all_cards(p1, p2);

    for (auto i = 0; i < 16; ++i)
    {
        std::cout << p1[i] << std::endl;
        std::cout << p2[i] << std::endl;
    }
    return 0;
}
