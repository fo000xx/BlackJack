#include <array>
#include <iostream>

#include "Deck.h"
#include "Player.h"

int Player::drawCard(Deck& deck)
{
    //draw a card
    Card drawncard{ deck.dealCard() };

    //get value - add to m_score
    m_score += drawncard.getCardValue();
    
    return drawncard.getCardValue();
}