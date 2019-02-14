/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

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

class Card {
private:     

public:
    unsigned char data;
    Rank rank;
    Suit suit;

    //inits
    Card() : Card (Ace, Spades)
        {};
    Card(Rank r, Suit s) : rank(r), suit(s), 
        data (static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r)) 
        {}; 

    //Class notes: Accessors return the value of a private data member.
    //Aka getter, observers, queries."const" guarantees 
    //that the member of function wont modify an members of a class
    Rank get_rank() const {
        //return rank;
        return static_cast<Rank>(data & 0xf);
        }
    Suit get_suit() const {
        //return suit;
        return static_cast<Suit>(data >> 4);
        }
    
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

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);



#endif