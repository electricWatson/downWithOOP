/*
COPYRIGHT (C) 2019 Sean Watson (sw182) All rights reserved.
Practice 2 - War
Author: Sean Watson
    sw182@zips.uakron.edu
    Version. 1.01 2/1/2019
Purpose: Establish the game of war with the machines
*/

The game starts by assuming that a deck of 52 cards can be represented by integers 1-52 and builds a vector of those ints to be shuffled.
The dealing is done by removing the last element of the "deck" and giving it to the Player through the dealCard() method and then removed from the deck vector.

The Player is a class that has a vector of Cards called "hand" cards are delt to the hand through the dealCard() method.
Player has an int "score" counting its wins in the game of War.

After all the cards in the "deck" have been dealt the game of War begins.

War takes the last card each players hand and comapres them, the winner gets a point added to thier Player.
The winner is determined and we recognise War played this way is one of the worsts games you can play with a deck of cards.
It is the candy land of the wild west.