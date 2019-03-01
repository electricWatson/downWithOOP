#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iterator>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Block {
    private:
        Texture texture;
        int count;

        typedef std::vector<Sprite> SpriteList;
        SpriteList sprites;


        //typedef Sprite SpriteList[];
        //SpriteList sprites;
        //Sprite sprites[];
        

    public:
        Block(std::string s, int n) :  count(n) //sprites[n], 
            {
                texture.loadFromFile(s);
                instantiate();
            }
        Block(Texture t, int n) : texture(t) //sprites[n], instantiate(),
            {}
        //Block(int n) : sprites[n]
        //    {};

        typedef SpriteList::iterator iterator;
        typedef SpriteList::const_iterator const_iterator;
        iterator begin() { return sprites.begin(); }
        iterator end() { return sprites.end(); }

        void setTexture(std::string s){
            texture.loadFromFile(s);
        }

        void instantiate() { blockLayout(); };
        void blockLayout();
        bool collisionCheck(float, float);
        
/*
        //typedef Block::iterator iterator;
        //typedef Block::const_iterator const_iterator;
        typedef Sprite::iterator iterator;
        typedef Sprite::const_iterator const_iterator;

        typedef Sprite * iterator;
        typedef const Sprite * const_iterator;
        iterator begin() { return &sprites[0]; }
        iterator end() { return &sprites[count]; }

        iterator begin() { return std::begin(sprites); }
        iterator end() { return std::end(sprites); }
        const_iterator begin() const { return std::begin(sprites); }
        const_iterator end() const { return std::end(sprites); }
*/
        



/*
        iterator begin() { return sprites.begin(); }
        iterator end() { return sprites.end(); }
        const_iterator begin() const { return sprites.begin(); }
        const_iterator end() const { return sprites.end(); }
        const_iterator cbegin() const { return sprites.cbegin(); }
        const_iterator cend() const { return sprites.cend(); }
*/


};

#endif