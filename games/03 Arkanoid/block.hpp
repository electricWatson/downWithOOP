#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <iterator>

class Block {
    private:
        Texture texture;
        //typedef Sprite SpriteList[];
        //SpriteList sprites;
        Sprite sprites[];
        size_t count;

    public:
        Block(std::string s, int n) : texture.loadFromFile(s); count{n}; sprites[n]; instantiate();
            {}
        Block(Texture t, int n) : texture(t); sprites[n]; instantiate();
            {}
        Block(int n) : sprites[n];
            {}

        typedef Block::iterator iterator;
        typedef Block::const_iterator const_iterator;

        iterator begin() { return std::begin(sprites); }
        iterator end() { return std::end(sprites); }
        const_iterator begin() const { return std::begin(sprites); }
        const_iterator end() const { return std::end(sprites); }

        void instantiate() { bloackLayout(); };
        void blockLayout();
        bool collisionCheck(float, float);
/*
        typedef Sprite * iterator;
        typedef const Sprite * const_iterator;
        iterator begin() { return &sprites[0]; }
        iterator end() { return &sprites[count]; }

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