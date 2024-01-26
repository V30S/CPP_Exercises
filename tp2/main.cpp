#include <iomanip>
#include <iostream>
#include <thread>

#include "Player.hpp"

int main(int argc, char const *argv[])
{
    Player p1{"Gerald"};
    Player p2{"Julien"};
    Player::deal_all_cards(p1, p2);

    while (!Player::play(p1, p2))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Player 1 score : " << p1.get_score() << std::endl;
        std::cout << "Player 2 score : " << p2.get_score() << std::endl;
    }

    return 0;
}
