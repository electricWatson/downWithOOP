#include "block.hpp"

//void Block::instantiate(){
    
//    blockLayout();
//}

void Block::blockLayout(){
    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
    {
        Sprite newS;
        newS.setTexture(texture);
        newS.setPosition(i*43,j*20);
        sprites.push_back(newS);
        //sprites[n].setTexture(t1);
        //sprites[n].setPosition(i*43,j*20);
        ++n;
    }
}
bool Block::collisionCheck(float x, float y){
    bool collision = false;
    for (auto block : sprites){
        if ( FloatRect(x+3,y+3,6,6).intersects(block.getGlobalBounds()) ) {
            block.setPosition(-100,0); 
            collision=-collision;
        }
    }
    return collision;
}