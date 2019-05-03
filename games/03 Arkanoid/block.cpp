#include "block.hpp"


//void Block::instantiate(){
    
//    blockLayout();
//}

void Block::blockLayout(){
    std::cout << "NEW LAYOUT\n";
    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
    {
        Sprite newS;
        newS.setTexture(textures[j % 5]);
        newS.setPosition(i*43,j*20);
        sprites.push_back(newS);
        //sprites[n].setTexture(t1);
        //sprites[n].setPosition(i*43,j*20);
        ++n;
    }
}
void Block::blockLayout(int n){
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
    {
        BlockHead newBlock;
            if(j == 1)
                newBlock = new BlockShrink;
            else if(j == 2)
                newBlock = new BlockCreep;
        newBlock.type = j % 5;
        newBlock.sprite.setTexture(textures[j % 5]);
        newBlock.sprite.setPosition(i*43,j*20);
        blocks.push_back(newBlock);

    }
}
bool Block::collisionCheck(float x, float y){
    bool collision = false;
    for (auto b : sprites){
        if ( FloatRect(x+3,y+3,6,6).intersects(b.getGlobalBounds()) ) {
            std::cout << "BLOCK_start_" << b.getPosition().x;
            b.setPosition(-500,0); 
            std::cout << "  BLOCK_end_" << b.getPosition().x << std::endl;;
            collision=true;
        }
    }
    return collision;
}
int Block::collisionCheck(float x, float y, float size){
    int collision = 0;
    for (auto b : blocks){
        if ( FloatRect(x+3*(size/2), y+3*(size/2), 6*size, 6*size).intersects(b.sprite.getGlobalBounds()) ) {
            b.hit();
            collision = b.type;
        }
    }
    return collision;
}