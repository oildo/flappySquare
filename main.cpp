#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.hpp"
#include "Pipe.hpp"
int main()
{
    int windowDim[] = {650, 800};
    sf::RenderWindow window(sf::VideoMode(windowDim[0], windowDim[1]), "flappy square", sf::Style::Titlebar | sf::Style::Close);
    sf::Clock clock;
    float deltaTime;

    //----init----
    //background
    sf::RectangleShape background(sf::Vector2f(windowDim[0], windowDim[1]));
    background.setFillColor(sf::Color(0, 63, 147));

    //----------------------------
    //Bird init
    float BirdStartingPoint(300.0f);
    Bird bird(100.0f, BirdStartingPoint, 50.0f, 40.0f, 1000.0f, 400.0f, 400.0f, windowDim[1]);//x,y,w,h,g,max,jump, maxY
    sf::RectangleShape birdShape(bird.getDim());
    birdShape.setFillColor(sf::Color::Yellow);
    birdShape.setPosition(bird.getPos());
    bool col = false;
    //----------------------------
    //Pipe init
    float range(100);
    float startingPoints[] = {650, 975};
    Pipe pipes[] = {
      Pipe(690, 0, 80, 300, 150, 200, windowDim[1], range),//x,y,w,h,offset,speed,ymax
      Pipe(690, 0, 80, 300, 150, 200, windowDim[1], range)
    };
    for(int i = 0; i < 2; i++)
      pipes[i].setPos(startingPoints[i], pipes[i].getPos().y);
    sf::RectangleShape pipeShape(sf::Vector2f(10.0f, 10.0f));

    //----------------------------
    //Game data init
    bool isPlaying = false;


    //----------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
          switch (event.type) {
            case sf::Event::Closed:
              window.close();
            break;

            case sf::Event::KeyPressed:
              switch (event.key.code) {
                case sf::Keyboard::Escape:
                  window.close();
                break;

                case sf::Keyboard::Space:
                  isPlaying = true;
                  bird.jump();
                break;

                default:
                break;
              }
            break;
            //events here

            default:
            break;
          }
        }

        //----update----
        //delta time
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        //update code here
        if(isPlaying){
          bird.update(deltaTime);
          col = false;
          for(int i = 0; i< 2; i++){
            pipes[i].update(deltaTime);
            if (bird.isColliding(pipes[i].getPos(), pipes[i].getDim()) || bird.isColliding(pipes[i].getPosBis(), pipes[i].getDimBis()) )
              col = true;
          }

          if(col){
            isPlaying = false;
            bird.setPos(bird.getPos().x, BirdStartingPoint);
            for(int i = 0; i < 2; i++){
              pipes[i].setPos(startingPoints[i], 0);
              pipes[i].reset();
            }

          }

        }

        //----draw----
        window.clear();

        window.draw(background);

        //Bird drawing
        birdShape.setPosition(bird.getPos());
        window.draw(birdShape);

        //pipes drawing
        for(int i = 0; i< 2; i++)
        {
          pipeShape = sf::RectangleShape(pipes[i].getDim());
          pipeShape.setFillColor(sf::Color::Green);
          pipeShape.setPosition(pipes[i].getPos());
          window.draw(pipeShape);

          pipeShape = sf::RectangleShape(pipes[i].getDimBis());
          pipeShape.setFillColor(sf::Color::Green);
          pipeShape.setPosition(pipes[i].getPosBis());
          window.draw(pipeShape);
        }
        //std::cout<< pipe.getPos().x << " , " <<  pipe.getPos().y << " , " <<  pipe.getDim().x << " , " <<  pipe.getDim().y<< "\n";

        window.display();
    }

    return 0;
}
