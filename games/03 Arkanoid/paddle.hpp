#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Paddle {
    private:
        Texture texture;
        Sprite _sprite;

    public:
        Paddle(std::string s){
            texture.loadFromFile(s);
            _sprite.setTexture(texture);
        };

        void setPos(float x, float y){
            _sprite.setPosition(x,y);
        }
        Sprite sprite(){
            return _sprite;
        }

        void inputToMove();
        bool collisionCheck(float, float);
        
        
};

#endif