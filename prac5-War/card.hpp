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
#include <cassert>

enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum Color { 
    Black, 
    Red 
};

enum CardKind {
    Standard,
    Joker
};

enum  Rank {
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
    King,
    Ace
};


struct Card {   
    enum Kind {
        Standard,
        Joker,
    }; 
    //CardKind tag;  
    //CardData cardData;
    unsigned char data;
    Kind kind;

    Card (Kind k) 
        : kind(k)
    {}


    //binary representation data control method
    unsigned char get_data() const {
        //return suit;
        return data;
        }
    //pre: none
    //post: none
    //prints card to console out
    virtual void  printCard(std::ostream& os) const = 0;
    //pre: none
    //post: returns int value of rank
    virtual int returnValue();

};

struct JokerCard : Card {
        Color color;
        
        JokerCard(Color c)
            : Card(Joker), color(c)//, kind(Joker) //Card(Joker) //, , cardData(c)
            {  }
        
        Color get_color() const { 
            return color; 
        }

        virtual void  printCard(std::ostream& os) const override{
            std::cout << this->color << " Joker";
        }

        virtual int returnValue() override {
            return 13;
        }


};

struct StandardCard : Card {
        Rank rank;
        Suit suit;

        StandardCard(Rank r, Suit s)
            : Card(Standard), rank(r), suit(s)//, kind(Standard)//, cardData(r, s)
            {};

        Rank get_rank() const {
            return rank;
            //return static_cast<Rank>(data & 0xf);
        }

        Suit get_suit() const {
            return suit;
            //return static_cast<Suit>(data >> 4);
        }
        
        virtual void  printCard(std::ostream& os) const override{
            std::cout << this->rank << " of " << this->suit;
        }
        
        virtual int returnValue() override;
};



std::ostream & operator<<(std::ostream& os, Suit& s);
std::ostream & operator<<(std::ostream& os, Rank& r);
std::ostream & operator<<(std::ostream& os, Card& c);

bool operator==(StandardCard a, StandardCard b);
bool operator!=(StandardCard a, StandardCard b);
bool operator<(StandardCard a, StandardCard b);
bool operator>(StandardCard a, StandardCard b);
bool operator<=(StandardCard a, StandardCard b);
bool operator>=(StandardCard a, StandardCard b);





#endif