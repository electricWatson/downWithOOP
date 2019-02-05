#include "player.hpp"
#include "card.hpp"

void Player::dealCard(int card){
    Suit ms = Suit(card / 13);
    Rank mr = Rank(card % 13);
    Card newCard(mr, ms);
    this->dealCard(newCard);
}

void Player::dealCard(Card card){
    hand.push_back(card);
}

Card Player::playNextCard(){
    Card topCard;
    topCard = this->hand.back();
    this->hand.pop_back();
    return topCard;
}

void Player::addPoint(){
    ++score;
}