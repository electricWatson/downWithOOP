/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

#include "card.hpp"


std::ostream & operator<<(std::ostream& os, Suit& s){
    switch(s) {
        case Clubs : return os << "Clubs";          break;
        case Diamonds : return os << "Diamonds";    break;
        case Hearts : return os << "Hearts";        break;
        case Spades : return os << "Spades";        break;
    }
}

std::ostream & operator<<(std::ostream& os, Rank& r){
    switch(r) {
        case Ace : return os << "Ace";          break;
        case Two : return os << "Two";          break;
        case Three : return os << "Three";      break;
        case Four : return os << "Four";        break;
        case Five : return os << "Five";        break;
        case Six : return os << "Six";        break;
        case Seven : return os << "Seven";        break;
        case Eight : return os << "Eight";        break;
        case Nine : return os << "Nine";        break;
        case Ten : return os << "Ten";        break;
        case Jack : return os << "Jack";        break;
        case Queen : return os << "Queen";        break;
        case King : return os << "King";        break;
    }
}

std::ostream & operator<<(std::ostream& os, Card& c){
    return os << "Card of kind: " << c.kind;
}
std::ostream & operator<<(std::ostream& os, StandardCard& c){
    return os << c.rank << " of " << c.suit;
}
std::ostream & operator<<(std::ostream& os, JokerCard& c){
    return os << c.color << " Joker";
}



int StandardCard::returnValue(){
    switch(this->rank) {
        case Ace : return 14;          break;
        case Two : return 2;          break;
        case Three : return 3;      break;
        case Four : return 4;        break;
        case Five : return 5;        break;
        case Six : return 6;        break;
        case Seven : return 7;        break;
        case Eight : return 8;        break;
        case Nine : return 9;        break;
        case Ten : return 10;        break;
        case Jack : return 11;        break;
        case Queen : return 12;        break;
        case King : return 13;        break;
    }
}

//StandardCard
bool operator==(StandardCard a, StandardCard b){
    return a.get_rank() == b.get_rank() 
        && a.get_suit() == b.get_suit();
}
bool operator!=(StandardCard a, StandardCard b){
    return !(a==b);
}
bool operator<(StandardCard a, StandardCard b){
    //Lexicographical order of Enum instead of returnValue()
    if(a.get_rank() < b.get_rank())
        return true;
    else if (a.get_rank() > b.get_rank())
        return false;
    return a.get_suit() < b.get_suit(); 
}
bool operator>(StandardCard a, StandardCard b){
    return !(a<b);
}
bool operator<=(StandardCard a, StandardCard b){
    if(a==b || a<b)
        return true;
    else
        return false;
}
bool operator>=(StandardCard a, StandardCard b){
    if(a==b || a>b)
        return true;
    else
        return false;
}
//JokerCard
bool operator==(JokerCard a, JokerCard b){
    return a.kind == b.kind;
}
bool operator!=(JokerCard a, JokerCard b){
    return !(a==b);
}
