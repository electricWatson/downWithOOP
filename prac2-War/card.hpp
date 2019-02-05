#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum  Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

struct Card {
    Rank rank;
    Suit suit;

    //inits
    Card();
    Card(Rank, Suit); 
    
    //pre: none
    //post: none
    //prints card to console out
    void  printCard();
    //pre: none
    //post: returns int value of rank
    int returnValue();
};

std::ostream & operator<<(std::ostream& os, Suit& s);
std::ostream & operator<<(std::ostream& os, Rank& r);
std::ostream & operator<<(std::ostream& os, Card& c);



#endif