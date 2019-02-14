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
    return os << c.rank << " of " << c.suit;
}

/*
std::ostream & operator<<(std::ostream& os, Deck const& c){
    return os << c.rank << " of " << c.suit;
}

Card::Card() : rank(Ace), suit(Spades){
    //rank = Ace;
    //suit = Spades;
}

Card::Card (Rank r, Suit s) : rank(r), suit(s){
    //rank = r;
    //suit = s;
}
*/

void Card::printCard(){
    std::cout << this->rank << " of " << this->suit;
}

int Card::returnValue(){
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


bool operator==(Card a, Card b){
    return a.get_rank() == b.get_rank() 
        && a.get_suit() == b.get_suit();
}
bool operator!=(Card a, Card b){
    return !(a==b);
}
bool operator<(Card a, Card b){
    //Product order, (does not give total order)
    //return a.get_rank() < b.get_rank() 
    //    && a.get_suit() < b.get_suit();

    //Lexicographical order
    if(a.get_suit() < b.get_suit())
        return true;
    else if (a.get_suit() > b.get_suit())
        return false;
    return a.get_rank() < b.get_rank();
}
bool operator>(Card a, Card b){
    
}
bool operator<=(Card a, Card b){
    
}
bool operator>=(Card a, Card b){
    
}