#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "Card.h"
#include "Deck.h"
#include "g_constants.h"

using PlayerHand = std::array<Card, g_constants::g_maximumHand>;

class Player
{
private:
    int m_score{};
    PlayerHand m_hand{};
    
public:
    Player() = default;

    int score() { return m_score; }
    bool isBust() { return m_score > g_constants::g_maximumscore; }

    //forward declarations for member functions
    int drawCard(Deck& deck);
};

#endif