#include <iostream>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
#include "Card.h" // creates the card object
#include "Deck.h" // creates the Deck object
#include "Player.h" //creates the player object

void playerTurn(Deck& deck, Player& player)
{
    //start the game - draw two cards
    int cardOne{ player.drawCard(deck) };
    int cardTwo{ player.drawCard(deck) };
    std::cout << "The player has drawn two cards with values " << cardOne << " and " << cardTwo 
        << " their current score is " << player.score() << '\n';
    if (player.isBust(player.score())) return ;

    //ask if they'd like to hit/stand, if stand return, if hit continue - if final card makes them bust, return
    while (true)
    {   
        char x;
        std::cout << "Would you like to hit (h) or stand (s)?\n";
        std::cin >> x;

        if (x == 's') return;

        int playerCard{ player.drawCard(deck) };
        std::cout << "The player drew a card with value " << playerCard << " and now has score " << player.score() << '\n';

        if (player.isBust(player.score())) return ;
    }
}

void dealerTurn(Deck& deck, Player& dealer)
{
    do
    {
        int dealerCard{ dealer.drawCard(deck) };
        std::cout << "The dealer drew a card with value " << dealerCard << " and now has score " << dealer.score() << '\n';        
    } while (dealer.score() < g_constants::g_minimumDealerScore);
}

bool playBlackjack(Deck& deck, Player& player, Player& dealer)
{
    //initiate game - dealer draws two (first face down) 
    dealer.drawCard(deck);
    int dealerCard { dealer.drawCard(deck) };
    std::cout << "The dealer drew a facedown card and a card with value " << dealerCard << '\n';

    //players turn - if the score is over 21 they go bust.
    playerTurn(deck, player);
    if (player.isBust(player.score()))
    {
            std::cout << "You're bust!\n";
            return false;
    }

    //dealers turn
    dealerTurn(deck, dealer);

    //win conditions - return false if a loss
    if (player.score() > g_constants::g_maximumscore || ((dealer.score() <= g_constants::g_maximumscore) && (dealer.score() > player.score())))
    {
            return false;
    }
    else
    {
        return true;;
    }
}

int main()
{
    Deck deck{};

    deck.shuffleDeck();
    //deck.printDeck();

    Player player{};
    Player dealer{};

    if(playBlackjack(deck, player, dealer))
    {
        std::cout << "The player wins!\n";
    }
    else
    {
        std::cout << "The house wins!\n";
    }

    return 0;
}