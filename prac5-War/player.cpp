/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

#include "player.hpp"


void Player::dealCard(int card){
    Suit ms = Suit(card / 13);
    Rank mr = Rank(card % 13);
    StandardCard newCard(mr, ms);
    //hand.push_back(newCard);
    //this->dealCard(newCard);
    hand.push_back(new StandardCard(mr, ms));
}

void Player::dealCard(StandardCard card){
    hand.push_back(new StandardCard(card.rank, card.suit));
}

Card* Player::playNextCard(){
    Card* topCard(this->hand.back());
    this->hand.pop_back();
    return topCard;
}

void Player::addPoint(){
    ++score;
}