#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "snake.hpp"
#include "direction.hpp"

#include <cmath>

sf::Vector2f scaleToMagnitude(const sf::Vector2f &vec, double magnitude)
{
    double modulus = std::sqrt(vec.x*vec.x + vec.y*vec.y);
    sf::Vector2f modifiedVec(vec.x*magnitude/modulus, vec.y*magnitude/modulus);
    return modifiedVec;
}

int main()
{
   // const sf::Vector2i blockSize = {10,10};
    std::cout << "hello world" << std::endl;

    sf::RenderWindow myWindow(sf::VideoMode(800,600), "Snake Game");
    Snake mySnake({300,300});
    sf::RectangleShape food({10,10});
    food.setFillColor(sf::Color::Red);
    food.setPosition(200,200);

    sf::Clock myClock;
    
    sf::Time deltaTime = myClock.restart(); 

    while(myWindow.isOpen())
    {
        //if(deltaTime.asSeconds() >0.2)
        //deltaTime = myClock.restart();
        sf::sleep(sf::seconds(0.04f));
        //float deltaTimeInSeconds = deltaTime.asSeconds();

        sf::Event myEvent;

        while(myWindow.pollEvent(myEvent))
        {
            if(myEvent.type == sf::Event::Closed)
            {
                myWindow.close();
              //break;
            }
        }
        //enemyCircle.move((scaleToMagnitude(myCircle.getPosition() - enemyCircle.getPosition(), enemySpeed))*deltaTimeInSeconds);
        
        Direction someDirection;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            someDirection = Direction::LEFT;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            someDirection = Direction::RIGHT;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            someDirection = Direction::DOWN;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            someDirection = Direction::UP;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            myWindow.close();
        }
        
        mySnake.move(someDirection,food);
        
        
        myWindow.clear();

        myWindow.draw(food);
        mySnake.drawSnake(myWindow);
        myWindow.display();

    }
    mySnake.printBody();

    return 0;
}