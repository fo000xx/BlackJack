#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <cassert>

#include "Deck.h"
#include "Card.h"

//print the deck
void Deck::printDeck() const
{
    for (const auto& card : m_deck)
    {
        card.printCard();
        std::cout << ' ';
    }

    std::cout << '\n';
}

//shuffle the deck randomly
void Deck::shuffleDeck()
{
    //static so it's only seeded once - moved from main into here to tidy up.
    //static std::mt19937 mt{ std::random_device{}() };  // was generating the same shuffle each time.
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);

    m_cardIndex = 0;
};

//deal a Card to the player
const Card& Deck::dealCard()
{
    assert(m_cardIndex < m_deck.size());

    return m_deck[m_cardIndex++];
}