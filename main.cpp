#include <iostream>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
#include "Card.h" // creates the card object
#include "Deck.h" // creates the Deck object
#include "Player.h" //creates the player object

/*
int playerHandTurn(int pos, Hand& hand, Deck& deck)
{
    //set the initial score to 0 and initialize the player choice
    int playerScore{ 0 };
    char playerChoice{};
    
    //loop below deals one card at a time. Start with the first card then hit the loop
    //places current card to the back of the players hand
    hand.push_back(deck[pos]);
    //calculate score -> pos-1 as pos starts at 1.
    playerScore += getCardValue(hand[pos-1]);
    ++pos;

    //iterate through the deck and deal the ith card to the player. If player stands return to playBlackJack
    for (pos; pos < deck.size(); ++pos)
    {            
        hand.push_back(deck[pos]);
        playerScore += getCardValue(hand[pos-1]);

        //print the current hand and score and offer the player a choice to hit or stand  
        //if they hit and go bust, return their score         
        std::cout << "Player's hand: ";
        printDeck(hand);
        std::cout << "Player Score: " << playerScore << '\n';
        if (playerScore > g_maximumScore)
        {
            std::cout << "Bust!\n";
            return playerScore;
        }

        //else continue with the hit/stand offer, if stand - return their score
        std::cout << "Hit (H) or Stand (S)? ";
        std::cin >> playerChoice;
        if (playerChoice == 'S')
        {
            return playerScore;
        }
    }

    return playerScore;
}

int dealerHandTurn(int pos, Hand& hand, Deck& deck)
{
    //set the initial score to 0 and initialize the player choice
    int playerScore{ 0 };
    
    //iterate through the deck and deal the ith card to the player. If player stands return to playBlackJack
    for (pos; pos < deck.size(); ++pos)
    {            
        //places current card to the back of the players hand
        hand.push_back(deck[pos]);
        //calculate score -> pos-1 as pos starts at 1.
        playerScore += getCardValue(hand[pos-1]);

        //print the current hand and score and offer the player a choice to hit or stand  
        //if they hit and go bust, return their score         
        std::cout << "Dealer's hand: ";
        printDeck(hand);
        std::cout << "Dealer Score: " << playerScore << '\n';
        if (playerScore >= g_minimumDealerScore)
        {
            return playerScore;
        }
    }

    return playerScore;
}

bool playBlackjack(Deck& deck)
{
    //first card to house, second and third to player
    //integer to track the current dealt card position
    int deckPos{ 0 };
    Hand playerHand{};
    Hand dealerHand{};

    //first card to the dealer
    dealerHand.push_back(deck[deckPos]);
    ++deckPos;
    std::cout << "Dealer's first card: ";
    printDeck(dealerHand);

    //player plays
    int playerScore { playerHandTurn(deckPos, playerHand, deck) };
    
    //dealer plays
    int dealerScore { dealerHandTurn(deckPos, dealerHand, deck) };
    
    if (playerScore > g_maximumScore || ((dealerScore < g_maximumScore) && (dealerScore > playerScore)))
    {
        return false;
    }
    else
        return true;
}

int main()
{
    //create the deck
    auto deck { createDeck() };

    //shuffle the deck
    shuffleDeck(deck);

    bool isPlayerWinner{ playBlackjack(deck) };

    if (isPlayerWinner)
        std::cout << "Player Wins!\n";
    else
        std::cout << "Dealer Wins!\n";

    return 0;
}
*/

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