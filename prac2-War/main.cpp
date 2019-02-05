/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

#include "card.hpp"
#include "player.hpp"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>


int main() {
    std::srand ( unsigned ( std::time(0)));
    
    //create deck, int representation
    std::vector<int> deck;
    for (size_t i = 0; i < 52; ++i) {
        deck.push_back(i);
    }

    //shuffle deck
    std::random_shuffle(deck.begin(), deck.end());

    //create players
    Player players[2];
    //deal cards off deck to their hands
    int p = 0;
    for(auto intIt = deck.begin(); intIt != deck.end();){
        players[p].dealCard(*intIt);
        intIt = deck.erase(intIt);
        p = 1 - p;
    }

    //play WAR
    while (!players[0].hand.empty() && !players[0].hand.empty()){
        //play first cards
        Card play1 = players[0].playNextCard();
        std::cout << "Player 1 plays: " << play1 << std::endl;
        Card play2 = players[1].playNextCard();
        std::cout << "Player 2 plays: " << play2 << std::endl;
        //determine value
        //didn't know i could just access the enum value till I tried on the suits
        int pv1 = play1.returnValue(); 
        int pv2 = play2.returnValue();
        //determine winner    
        if(pv1 > pv2){
            std::cout << "Player 1 Wins" << std::endl;
            players[0].addPoint();
        }
        else if(pv1 == pv2){
            if(play1.suit > play2.suit){
                std::cout << "Player 1 Wins" << std::endl;
                players[0].addPoint();
            }
            else
            {
                std::cout << "Player 2 Wins" << std::endl;
                players[1].addPoint();
            }

        }
        else {
            std::cout << "Player 2 Wins" << std::endl;
            players[1].addPoint();
        }
        std::cout << "--------------------------------------" << std::endl;
    }
    //show score
    std::cout << "Player 1 score: " << players[0].score << std::endl
        << "Player 2 score: " << players[1].score << std::endl;     
    //show winner
    if(players[0].score > players[1].score)
    {
        std::cout << "Player 1 Wins GAME" << std::endl;   
    }
    else if(players[0].score == players[1].score){
        std::cout << "Tie game, kill yourself" << std::endl;
    }
    else {
        std::cout << "player 2 Wins GAME" << std::endl;
    }
    



/*
    //print hands
    for(auto &pl : players[0].hand){
        Suit ms = Suit(pl / 13);
        Rank mr = Rank(pl % 13);
        std::cout << mr << " of " << ms << " NAM " << pl << std::endl;
    }

    /*
    //print deck
    for(auto &c : deck){
        Suit ms = Suit(c / 13);
        Rank mr = Rank(c % 13);
        std::cout << mr << " of " << ms << " NAM " << c << std::endl;
    }
    */


    std::cout << "WAR by Sean" << std::endl;
    Card newCard(Two, Spades);

    return 0;
}