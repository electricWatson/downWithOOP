#include "player.hpp"
#include "card.hpp"

class Game {
    public:
        //Game() : players { "Player 1", "Player 2""};
        //Game()  {newGame();};
        
        void newGame();
        void playRound(Player&, Player&);


    private:
    //create players
    Player players[2];
    //create deck, int representation
    std::vector<Card*> deck;
    
    void buildDeck();
    void printDeck();
    void shuffleDeck();
    void dealCards();

};

