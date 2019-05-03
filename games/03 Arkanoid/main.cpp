#include <SFML/Graphics.hpp>
//#include <time.h>

#include "block.hpp"
#include "ball.hpp"
#include "paddle.hpp"

using namespace sf;


int main()
{
    //srand(time(0));

    RenderWindow app(VideoMode(520, 450), "Arkanoid!");
    app.setFramerateLimit(60);

    Paddle paddle("images/paddle.png");
    paddle.setPos(300,440);

    Block block(5);

    Ball ball("images/ball.png");
    
    //background
    Texture bg;
    bg.loadFromFile("images/background.jpg");
    Sprite sBackground(bg);

    while (app.isOpen())
    {
       Event e;
       while (app.pollEvent(e))
       {
         if (e.type == Event::Closed)
             app.close();
       }
        
        //Update ball events
        ball.updateMovement(block); //check movement vs block set
        //Collect input events into paddle
        paddle.inputToMove();
        ball.updateMovement(paddle); //check movement vs paddle
        ball.updatePosition(); //update sprite

        app.clear();
        app.draw(sBackground);
        app.draw(ball.sprite());
        app.draw(paddle.sprite());
    /*     
        for (const auto& it : block.sprites)
        {
            app.draw(it);
        }
    */
        for (auto it = block.begin(); it != block.end(); ++it ){
            app.draw(*it);
        }

        app.display();
    }

  return 0;
}
