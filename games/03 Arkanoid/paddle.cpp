#include "paddle.hpp"

void Paddle::inputToMove(){
    if (Keyboard::isKeyPressed(Keyboard::Right)) 
        _sprite.move(6,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) 
        _sprite.move(-6,0);
}


bool Paddle::collisionCheck(float x, float y){
    bool collision = false;
        if ( FloatRect(x,y,12,12).intersects(_sprite.getGlobalBounds()) )
    return collision;
}
