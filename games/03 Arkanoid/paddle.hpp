#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle {
    private:
        Texture texture;
        Sprite sprite;

    public:
        Paddle(std::string s) : texture.loadFromFile(s); instantiate();
            {}
        Paddle(Texture t) : texture(t); instantiate();
            {}
        

        void instantiate() {
            sprite(texture);
        }
        void setPos(float x, float y){
            sprite.setPosition(x,y);
        }
        Sprite sprite(){
            return sprite;
        }

        void inputToMove();
        bool collisionCheck(float, float);
        
        
};



#endif