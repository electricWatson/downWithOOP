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

    Block block("images/block01.png", 1000);
    block.blockLayout();

    Ball ball("images/ball.png");
    
    //background
    Texture bg;
    bg.loadFromFile("images/background.jpg");
    Sprite sBackground(bg);

/*
//load textures
    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");
//create apply textures to game objects as Sprite
    Sprite sBackground(t2);
    //set paddle position


    sPaddle.setPosition(300,440);

//create bloack of bricks

    Sprite block[1000];
    //place each brick, set texture and position
    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
      {
         block[n].setTexture(t1);
         block[n].setPosition(i*43,j*20);
         n++;
      }

     //ball start position
      float dx = 6, dy = 5;
	float x = 300, y = 300;
*/
    while (app.isOpen())
    {
       Event e;
       while (app.pollEvent(e))
       {
         if (e.type == Event::Closed)
             app.close();
       }

    //Ball collision checks and direction changes
        
        ball.updateMovement(block); //check movement vs block set
        ball.updateMovement(paddle); //check movement vs paddle
        ball.updatePosition(); //update sprite
/*
        x += dx; //move 6 pixels in the dx direction on X every loop
        if(block.collisionCheck(x, y)) dx=-dx; //check block collision and flip xdirection
        y += dy;
        if(block.collisionCheck(x, y)) dy=-dy; //check block collision and flip ydirection

        //keep ball on screen
        if (x<0 || x>520)  dx =- dx;
        if (y<0 || y>450)  dy =- dy;

        paddle.inputToMove();
        if (paddle.collisionCheck(x,y)) dy=-(rand()%5+2); //check paddle collision send ball on rand y velociy

        ball.setPos(x,y);

      for (int i=0;i<n;i++)
      if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ) 
          {block[i].setPosition(-100,0); dx=-dx;}
    
      for (int i=0;i<n;i++)
      if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ) 
          {block[i].setPosition(-100,0); dy=-dy;}

      //keep ball on screen
      if (x<0 || x>520)  dx =- dx;
      if (y<0 || y>450)  dy =- dy;


      if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(6,0);
      if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-6,0);

      if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);

      sBall.setPosition(x,y);
*/
        
      
      app.clear();
      app.draw(sBackground);
      app.draw(ball.sprite());
      app.draw(paddle.sprite());
/*
      app.draw(sBackground);
      app.draw(sBall);
      app.draw(sPaddle);

      for (int i=0;i<n;i++)
      app.draw(block[i]);
*/
       for ( auto it = block.begin(); it != block.end(); ++it ){
            app.draw(*it);
       }
           


      app.display();
    }

  return 0;
}
