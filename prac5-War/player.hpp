/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "card.hpp"

struct Card;
//enum Rank;
//enum Suit;

struct Player {
    //Player(std::string n) : name(n) {};
    //std::string name;
    std::vector<Card*> hand;
    int score = 0;

    //pre: takes a Card by intiger and adds it to the players hand
    //post: none
    //adds a Card by intiger representation in the Card enum schema
    void dealCard(int);
    //pre: takes a Card and adds it to the players hand
    //post: none
    //adds a Card by type to the players hand
    void dealCard(StandardCard);
    //pre: none
    //post: returns a Card matching that of the one removed from hand
    //returns a copy of the next Card and removes it from the hand
    Card* playNextCard();
    //pre : none
    //post: none
    //adds 1 point to score
    void addPoint();
};

#endif