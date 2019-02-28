#ifndef BALL_HPP
#define BALL_HPP

class Ball {
    private:
        Texture texture;
        Sprite sprite;

        //ball start position
        float x = 300, y = 300;
        //ball movement itteration disance
        float dx = 6, dy = 5;
        

    public:
        Ball(std::string s) : texture.loadFromFile(s); instantiate();
            {}
        Ball(Texture t) : texture(t); instantiate();
            {}

        void instantiate() {
            sprite(texture);
        }

        Sprite sprite(){
            return sprite;
        }

        //think we can overide the setPosition
        void setPos(float xSet,float ySet){
            x = xSet;
            y = ySet;
            sprite.setPosition(x,y);
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
