//member functons for the Card class defined here
#include <iostream>
#include <cassert>

#include "Card.h"

int Card::getCardValue() const
{
    switch (m_rank)
    {
        case Card::Rank::rank_2:        return 2;
        case Card::Rank::rank_3:        return 3;
        case Card::Rank::rank_4:        return 4;
        case Card::Rank::rank_5:        return 5;
        case Card::Rank::rank_6:        return 6;
        case Card::Rank::rank_7:        return 7;
        case Card::Rank::rank_8:        return 8;
        case Card::Rank::rank_9:        return 9;
        case Card::Rank::rank_10:       return 10;
        case Card::Rank::rank_jack:     return 10;
        case Card::Rank::rank_queen:    return 10;
        case Card::Rank::rank_king:     return 10;
        case Card::Rank::rank_ace:      return 11;
        default:
            assert(false && "shouldn't happen - getCardValue");
            return 0;
    } 
}

void Card::printCard() const
{
    switch (m_rank)
    {
        case Card::Rank::rank_2:        std::cout << "2"; break;
        case Card::Rank::rank_3:        std::cout << "3"; break;
        case Card::Rank::rank_4:        std::cout << "4"; break;
        case Card::Rank::rank_5:        std::cout << "5"; break;
        case Card::Rank::rank_6:        std::cout << "6"; break;
        case Card::Rank::rank_7:        std::cout << "7"; break;
        case Card::Rank::rank_8:        std::cout << "8"; break;
        case Card::Rank::rank_9:        std::cout << "9"; break;
        case Card::Rank::rank_10:       std::cout << "10"; break;
        case Card::Rank::rank_jack:     std::cout << "J"; break;
        case Card::Rank::rank_queen:    std::cout << "Q"; break;
        case Card::Rank::rank_king:     std::cout << "K"; break;
        case Card::Rank::rank_ace:      std::cout << "A"; break;
        default:
            std::cout << "?"; 
            break;
    }

    switch (m_suit)
    {
        case Card::Suit::clubs:         std::cout << "C"; break;
        case Card::Suit::spades:        std::cout << "S"; break;
        case Card::Suit::diamonds:      std::cout << "D"; break;
        case Card::Suit::hearts:        std::cout << "H"; break;
        default:                 
            std::cout << "?"; 
            break;
    }
}
