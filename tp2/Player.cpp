#include <algorithm>
#include <random>

#include "Player.hpp"

Player::Player(const std::string &name) : _name{name} {}

void Player::deal_all_cards(Player &p1, Player &p2)
{
    std::vector<Card> all_cards;
    std::vector<std::string> colors{"pique", "carreaux", "coeurs", "trefle"};
    std::vector<Card_enum> card_values{Card_enum::sept, Card_enum::huit, Card_enum::neuf, Card_enum::dix, Card_enum::valet, Card_enum::dame, Card_enum::roi, Card_enum::as};
    for (auto card_value : card_values)
    {
        for (auto current_color : colors)
        {
            all_cards.emplace_back(Card(card_value, current_color));
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    int i = 0;
    for (; i < all_cards.size() / 2; i++)
    {
        p1._cards.emplace_back(all_cards[i]);
    }
    for (; i < all_cards.size(); i++)
    {
        p2._cards.emplace_back(all_cards[i]);
    }
}

Card Player::operator[](int index) const
{
    return _cards[index];
}

unsigned int Player::turn_number = 0;

bool Player::play(Player &p1, Player &p2)
{
    if (turn_number >= p1._cards.size())
    {
        return true;
    }

    std::cout << "Tour : " << turn_number << std::endl;
    std::cout << "Player 1 carte : " << p1._cards[turn_number] << std::endl;
    std::cout << "Player 2 carte : " << p2._cards[turn_number] << std::endl;

    if (p2._cards[turn_number] < p1._cards[turn_number])
    {
        p1._score++;
    }
    else if (p1._cards[turn_number] < p2._cards[turn_number])
    {
        p2._score++;
    }

    turn_number++;

    return false;
}

int Player::get_score() const
{
    return _score;
}