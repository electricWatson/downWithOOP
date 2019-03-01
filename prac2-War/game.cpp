#include "game.hpp"

#include <ctime>
#include <algorithm>

/*
void newGame(std::string, std:::string){
    
    newGame();
}
*/

void Game::newGame() {
        buildDeck();
        //printDeck();
        shuffleDeck();
        //printDeck();
        dealCards();
        //play WAR
        while (!players[0].hand.empty() && !players[1].hand.empty()){
            playRound(players[0], players[1]);   
        }
        //END GAME
    //show score
    std::cout << "Player 1 score: " << players[0].score << std::endl
        << "Player 2 score: " << players[1].score << std::endl;     
    //show winner
    if(players[0].score > players[1].score)
    {
        std::cout << "Player 1 Wins GAME" << std::endl;   
    }
    else if(players[0].score == players[1].score){
        std::cout << "Tie game, kill yourself" << std::endl;
    }
    else {
        std::cout << "player 2 Wins GAME" << std::endl;
    }
}

void Game::playRound(Player& p1, Player& p2){
    //play first cards
    Card play1 = p1.playNextCard();
    std::cout << "Player 1 plays: " << play1 << std::endl;
    Card play2 = p2.playNextCard();
    std::cout << "Player 2 plays: " << play2 << std::endl;
    //determine value
    //didn't know i could just access the enum value till I tried on the suits
    int pv1 = play1.returnValue(); 
    int pv2 = play2.returnValue();
    //determine winner    
    if(pv1 > pv2){
        std::cout << "Player 1 Wins" << std::endl;
        p1.addPoint();
    }
    else if(pv1 == pv2){
        if(play1.suit > play2.suit){
            std::cout << "Player 1 Wins" << std::endl;
            p1.addPoint();
        }
        else
        {
            std::cout << "Player 2 Wins" << std::endl;
            p2.addPoint();
        }

    }
    else {
        std::cout << "Player 2 Wins" << std::endl;
        p2.addPoint();
    }
    std::cout << "--------------------------------------" << std::endl;
}


void Game::buildDeck(){
    deck.clear();
    //could have uses a link list or double ended queue
    //could have generated each card atthis point and do no conversion
    for (int i = 0; i < 52; ++i) {
        deck.push_back(Card( Rank(i%13), Suit(i/13)));    
    }
    //add jokers
    //deck.push_back(Card(Black));
    //deck.push_back(Card(Red));
}
void Game::printDeck(){
//print deck
    for(auto &c : deck){
        //Suit ms = Suit(c / 13);
        //Rank mr = Rank(c % 13);
        std::cout << c.rank << " of " << c.suit << std::endl
            << c.get_rank() << " of " << c.get_suit() << static_cast<Rank>(0)
            << " name: " << c 
            << " data: " << static_cast<unsigned>(c.get_data()) << std::endl;
    }
}

void Game::shuffleDeck(){
    std::srand ( unsigned ( std::time(0)));
    //shuffle deck
    std::random_shuffle(deck.begin(), deck.end());
}

void Game::dealCards(){
    //deal cards off deck to their hands
    //if(!players.empty()){
        int p = 0;
        for(auto intIt = deck.begin(); intIt != deck.end();){
            players[p].dealCard(*intIt);
            intIt = deck.erase(intIt);
            p = 1 - p;
        }    
 //   }
}

