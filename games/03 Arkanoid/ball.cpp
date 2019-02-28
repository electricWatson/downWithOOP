#include "ball.hpp"
#include <time.h>

void Ball::updateMovement(Block& block){
        x += dx; //move 6 pixels in the dx direction on X every loop
    if(block->collisionCheck(x, y)) dx=-dx; //check block collision and flip xdirection
    y += dy;
    if(block->collisionCheck(x, y)) dy=-dy; //check block collision and flip ydirection

    //keep ball on screen
    if (x<0 || x>520)  dx =- dx;
    if (y<0 || y>450)  dy =- dy;
}
void Ball::updateMovement(Paddle& paddle){
    if (paddle->collisionCheck(x,y)) dy=-(rand()%5+2); //check paddle collision send ball on rand y velociy
}
void Ball::updatePosition(){
    sprite.setPosition(x,y);
}