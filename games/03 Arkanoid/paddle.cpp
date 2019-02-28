#include "paddle.hpp"

void Paddle::inputToMove(){
    if (Keyboard::isKeyPressed(Keyboard::Right)) 
        sprite.move(6,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) 
        sprite.move(-6,0);
}


bool Paddle::collisionCheck(float x, float y){
    bool collision = false;
        if ( FloatRect(x,y,12,12).intersects(sprite.getGlobalBounds()) )
    return collision;
}
