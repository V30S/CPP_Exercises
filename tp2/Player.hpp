#pragma once

#include <string>
#include <vector>

#include "Card.hpp"

class Player
{
public:
    Player(const std::string &name);
    static void deal_all_cards(Player &p1, Player &p2);

private:
    std::string _name;
    std::vector<Card> _cards; // initialisé à un vecteur vide
    unsigned int _score = 0;  // si je ne mets rien initialisé avec résidu de memoire
};