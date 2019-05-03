#include "ball.hpp"
#include <time.h>
#include <iostream>

void Ball::updateMovement(Block& block){
    x += dx; //move ball dx=6 pixels in the x direction every call
    if(block.collisionCheck(x, y)) {
        std::cout << "xblock hit";
        dx=-dx; //check block collision and flip xdirection
    }
    y += dy; //move ball dy=5 pixels in the y direction every call
    if(block.collisionCheck(x, y)) {
        std::cout << "yblock hit";
        dy=-dy; //check block collision and flip ydirection
    }

    //keep ball on screen
    if (x<0 || x>520)  dx =- dx;
    if (y<0 || y>450)  dy =- dy;
}
void Ball::updateMovement(Paddle& paddle){
    if (paddle.collisionCheck(x,y)){
        std::cout << "paddle hit";
        dy=-(rand()%5+2); //check paddle collision send ball on rand y velociy
    }
}
void Ball::updatePosition(){
    _sprite.setPosition(x,y);
}