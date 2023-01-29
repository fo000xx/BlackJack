#include <iostream>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
#include "Card.h" // creates the card object
#include "Deck.h" // creates the Deck object
#include "Player.h" //creates the player object

bool playerHits()
{
    char x;
    std::cout << "Would you like to hit (h) or stand (s)?\n";
    std::cin >> x;

    if (x == 's') 
        return false;
    return true;
}

bool playerTurn(Deck& deck, Player& player)
{
    //start the game - draw two cards
    int cardOne{ player.drawCard(deck) };
    int cardTwo{ player.drawCard(deck) };
    std::cout << "The player has drawn two cards with values " << cardOne << " and " << cardTwo 
        << " their current score is " << player.score() << '\n';
    
    while (true)
    {   
        //check for bust at the start - as they can be bust from the first two cards.
        if (player.isBust()) 
        {
            std::cout << "You're bust!\n";
            return true; //return true if bust, false if not
        }    
        
        if (!playerHits())
            return false;
        
        int playerCard{ player.drawCard(deck) };   
        std::cout << "The player drew a card with value " << playerCard << " and now has score " << player.score() << '\n';
    }
}

bool dealerTurn(Deck& deck, Player& dealer)
{
    //dealer shows hidden hole card
    std::cout << "The dealer starts with a score of: " << dealer.score() << '\n';

    //dealer play loop
    do
    {
        int dealerCard{ dealer.drawCard(deck) };
        std::cout << "The dealer drew a card with value " << dealerCard << " and now has score " << dealer.score() << '\n';        
    } while (dealer.score() < g_constants::g_minimumDealerScore);

    if (dealer.isBust())
    {
        std::cout << "The dealer is bust!\n";
        return true;
    }
    return false;
}

bool playBlackjack(Deck& deck, Player& player, Player& dealer)
{
    //initiate game - dealer draws two (first face down) 
    dealer.drawCard(deck);
    int dealerCard { dealer.drawCard(deck) };
    std::cout << "The dealer drew a facedown card and a card with value " << dealerCard << '\n';

    //players turn - if a true is returned, they're bust
    if (playerTurn(deck, player))
        return true;

    //dealers turn - true if they're bust
    if (dealerTurn(deck, dealer))
        return false;

    //win conditions - return, function has exited if there's a bust. Therefore only compare
    //player to dealer score. Return false if player wins.
    if (player.score() > dealer.score())
        return false;
    return true;;
}

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    //deck.printDeck();

    Player player{};
    Player dealer{};

    if(!playBlackjack(deck, player, dealer))
        std::cout << "The player wins!\n";
    else
        std::cout << "The house wins!\n";

    return 0;
}