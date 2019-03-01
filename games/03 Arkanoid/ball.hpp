#ifndef BALL_HPP
#define BALL_HPP

#include "block.hpp"
#include "paddle.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {
    private:
        Texture texture;
        Sprite _sprite;

        //ball start position
        float x = 300, y = 300;
        //ball movement itteration disance
        float dx = 6, dy = 5;
        

    public:
        Ball(std::string s)  
            {
                texture.loadFromFile(s);
                _sprite.setTexture(texture);
            };

        Sprite sprite(){
            return _sprite;
        }

        //think we can overide the setPosition
        void setPos(float xSet,float ySet){
            x = xSet;
            y = ySet;
            _sprite.setPosition(x,y);
        }
        float getXPos(){
            return x;
        }
        float geyYPos(){
            return y;
        }

        void updateMovement(Block&);
        void updateMovement(Paddle&);
        void updatePosition();
};

#endif
