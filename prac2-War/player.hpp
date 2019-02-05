#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
struct Card;
//enum Rank;
//enum Suit;

struct Player {
    std::vector<Card> hand;
    int score = 0;

    //pre: takes a Card by intiger and adds it to the players hand
    //post: none
    //adds a Card by intiger representation in the Card enum schema
    void dealCard(int);
    //pre: takes a Card and adds it to the players hand
    //post: none
    //adds a Card by type to the players hand
    void dealCard(Card);
    //pre: none
    //post: returns a Card matching that of the one removed from hand
    //returns a copy of the next Card and removes it from the hand
    Card playNextCard();
    //pre : none
    //post: none
    //adds 1 point to score
    void addPoint();
};

#endif