#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iterator>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Block {
    private:
        Texture texture;
        std::vector<Texture> textures;
        int count;

        typedef std::vector<Sprite> SpriteList;
        SpriteList sprites;
        

        
        
        
        


        //typedef Sprite SpriteList[];
        //SpriteList sprites;
        //Sprite sprites[];
        

    public:
        


        struct BlockHead {
            BlockHead() : type(0) {}
            Sprite sprite;
            int type = 0;
            int counter = 0;
            virtual void hit () 
                { 
                    std::cout << "BLOCK_hit_(" 
                        << sprite.getPosition().x << "," 
                        << sprite.getPosition().y << ")\n";
                    sprite.setPosition(-500,0);
                    
                }
        };
        struct BlockShrink : BlockHead {
            BlockShrink() {}
            void hit () 
                { 
                    std::cout << "BLOCK01_hit_(" 
                        << sprite.getPosition().x << "," 
                        << sprite.getPosition().y << ")\n";
                    if (counter < 1){
                        sprite.setScale(.5,.5);
                        counter++;
                    }
                    else
                        sprite.setPosition(-500,0);
                }
        };
        struct BlockCreep : BlockHead {
            BlockCreep() {}
            void hit () 
                { 
                    std::cout << "BLOCK01_hit_(" 
                        << sprite.getPosition().x << "," 
                        << sprite.getPosition().y << ")\n";
                    if (counter < 3){
                        sprite.move(Vector2f(0.0, -6.0));
                        counter++;
                    }
                    else
                        sprite.setPosition(-500,0);
                }
        };
        typedef std::vector<BlockHead> BlockList;
        BlockList blocks;

        Block(std::string s, int n) :  count(n) //sprites[n], 
            {
                texture.loadFromFile(s);
                instantiate();
            }
        Block(int n) 
            {
                Texture newT;
                switch (n) {
                    case 5 :
                        newT.loadFromFile("images/block05.png");
                        textures.push_back(newT);
                    case 4 :
                        newT.loadFromFile("images/block04.png");
                        textures.push_back(newT);
                    case 3 :
                        newT.loadFromFile("images/block03.png");
                        textures.push_back(newT);
                    case 2 : 
                        newT.loadFromFile("images/block02.png");
                        textures.push_back(newT);
                    case 1 :
                        newT.loadFromFile("images/block01.png");
                        textures.push_back(newT);
                        break;
                    default :
                        newT.loadFromFile("images/block01.png");
                        textures.push_back(newT);
                }
                instantiate();
            }
        Block(std::string (&s)[5], int n) :  count(n) //sprites[n], 
            {
                for(std::   string ts : s){
                    Texture newT;
                    newT.loadFromFile(ts);
                    textures.push_back(newT);
                }
                instantiate();
            }

        typedef SpriteList::iterator iterator;
        typedef SpriteList::const_iterator const_iterator;
        iterator begin() { return sprites.begin(); }
        iterator end() { return sprites.end(); }
        //iterator begin() const { return sprites.begin(); }
        //iterator end() const { return sprites.end(); }
        const_iterator begin() const { return sprites.begin(); }
        const_iterator end() const { return sprites.end(); }
        

        void setTexture(std::string s){
            texture.loadFromFile(s);
        }

        void instantiate() { blockLayout(); };
        void blockLayout();
        void blockLayout(int);
        bool collisionCheck(float, float);
        int collisionCheck(float, float, float);
        
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