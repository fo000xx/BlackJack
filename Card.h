#ifndef CARD_H
#define CARD_H

class Card
{
public:
    //two enums to define the card suits and ranks
    enum Suit
    {
        clubs,
        diamonds,
        hearts,
        spades,

        max_suits,
    };

    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

         max_rank,
    };

private:
    Suit m_suit{};
    Rank m_rank{};

public:
    //deftault constructor for a card
    Card() = default;

    Card(Rank rank, Suit suit)
        : m_rank{ rank}, m_suit{ suit }
    {
    }

    //forward statements for member functions defined in Card.cpp    
    int getCardValue() const;
    void printCard() const;
};

#endif