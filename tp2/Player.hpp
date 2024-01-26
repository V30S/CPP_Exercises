#pragma once

#include <string>
#include <vector>

#include "Card.hpp"

class Player
{
public:
    Player(const std::string &name);

    static void deal_all_cards(Player &p1, Player &p2);

    Card operator[](int index) const;

    static bool play(Player &p1, Player &p2);

    int get_score() const;

private:
    std::string _name;
    std::vector<Card> _cards; // initialisé à un vecteur vide
    unsigned int _score = 0;  // si je ne mets rien initialisé avec résidu de mémoire

    static unsigned int turn_number;
};