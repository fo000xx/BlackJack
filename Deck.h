#ifndef DECK_H
#define DECK_H

#include <array>
#include "Card.h"

using FullDeck = std::array<Card, 52>;
using Index = FullDeck::size_type;

class Deck
{
private:
    FullDeck m_deck{};
    int m_cardIndex{ 0 };

public:
    //default constructor to construct full (unshuffled) deck
    Deck()
    {
        Index index{ 0 };

        for (int suit { 0 }; suit < Card::Suit::max_suits; ++suit)
        {
            for (int rank { 0 }; rank < Card::Rank::max_rank; ++rank)
            {
                m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++index;
            }
        }
    }

    //int getCardIndex() { return m_cardIndex; }

    //forward declarations for member functions
    void printDeck() const;
    void shuffleDeck();
    const Card& dealCard();
};

#endif