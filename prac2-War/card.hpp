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
enum Color { 
    Black, 
    Red 
};

enum CardKind {
    Standard,
    Joker
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

class JokerCard {
    public:
        JokerCard(Color C)
            : color(C)
            {};
        Color get_color() const {return color; }

    private:
        Color color;
};

class StandardCard {
    public:
        StandardCard(Rank r, Suit s)
            : rank(r), suit(s)
            {};

        Rank get_rank() const {
            return rank;
            //return static_cast<Rank>(data & 0xf);
        }

        Suit get_suit() const {
            return suit;
            //return static_cast<Suit>(data >> 4);
        }

    private:
        Rank rank;
        Suit suit;
};

struct CardData {       
    StandardCard sc;
    JokerCard jc;
/*
    CardData(Rank r, Suit s)
        : sc(r, s)
        {}

    CardData(Color c)
        : jc(c)
        {}
*/
};

class Card {
private:     
    CardKind tag;  
    CardData cardData;
    unsigned char data;
public:
    Rank rank;
    Suit suit;
    Color color;

    //inits
    Card(Rank r, Suit s)
        : tag(Standard)//, cardData.sc(r, s)
        {};

    Card(Color c)
        : tag(Joker)//, cardData.jc(c)
        {};
    /*
    Card() : Card (Ace, Spades), tag(Standard)
        {};
    Card(Rank r, Suit s) : rank(r), suit(s), tag(Standard),
        data (static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r)) 
        {};
    Card(Color c) : color(c), tag(Joker),
        data (static_cast<unsigned>(s) << 6) 
        {}; 
    */

    //binary representation data control method
    unsigned char get_data() const {
        //return suit;
        return data;
        }
    //dual cards
    bool is_standard() const {
        return tag == Standard;
    }
    bool is_joker() const {
        return tag == Joker;
    }

    Rank get_rank() const {
        assert(is_standard(); // makes sure this is true before running this function
        return cardData.sc.get_rank();
        //return static_cast<Rank>(data & 0xf);
    }
    Suit get_suit() const {
        assert(is_standard();
        return cardData.sc.get_suit();
        //return static_cast<Suit>(data >> 4);
    }
    Color get_color() const {
        assert(is_joker();
        return cardData.jc.get_color();
        //return static_cast<Suit>(data >> 6);
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