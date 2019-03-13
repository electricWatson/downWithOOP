/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

#include "card.hpp"
#include "player.hpp"
#include "game.hpp"



#include <cstdlib>
#include <sstream>




int main() {
    Game war;
    war.newGame();
    std::cout << "WAR by Sean" << std::endl;

    return 0;
}

/*
void mainMenu() // Main Menu
{
        cout << "_____________________________________________________________________" << endl;
        cout << "|-------------------------------------------------------------------|" << endl;
        cout << "|                               WAR                                 |" << endl;
        cout << "|___________________________________________________________________|" << endl;
}
int enterNames() // Enter menu choice
{
    int choice = 0;
    for(int i = 1; i < 3; ++i)
    {
        string msg("Enter Player "  and 6."); // invalid message
        do
        {
            cout << "\nYour choice: ";
            cin >> choice;
        }while (validateInput(choice, 1, 6, msg));
    }
 
    return choice;
}
*/