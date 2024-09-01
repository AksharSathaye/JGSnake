#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

#include "../headers/snake.hpp"
#include "../headers/direction.hpp"
#include "../headers/gamescreen.hpp"
#include "../headers/game.hpp"

#include <cmath>

sf::Vector2f scaleToMagnitude(const sf::Vector2f &vec, double magnitude)
{
    double modulus = std::sqrt(vec.x*vec.x + vec.y*vec.y);
    sf::Vector2f modifiedVec(vec.x*magnitude/modulus, vec.y*magnitude/modulus);
    return modifiedVec;
}

int main()
{

    sf::RenderWindow myWindow(sf::VideoMode(GameScreen::screenWidth,GameScreen::screenHeight), "Snake Game");
    Game game;
    
    sf::Clock myClock;
    
    sf::Time deltaTime = myClock.restart(); 

    while(myWindow.isOpen())
    {
        sf::sleep(sf::seconds(0.05f));
        
        sf::Event myEvent;

        while(myWindow.pollEvent(myEvent))
        {
            if(myEvent.type == sf::Event::Closed)
            {
                myWindow.close();
              //break;
            }
        }
        
        Direction someDirection;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            std::cout << "Paused. Press Space again to resume." << std::endl;
            sf::sleep(sf::seconds(0.2f));
            while(! sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
               //wait
            }
            sf::sleep(sf::seconds(0.2f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            someDirection = Direction::LEFT;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
         || sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            someDirection = Direction::RIGHT;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
         || sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            someDirection = Direction::DOWN;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
         || sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            someDirection = Direction::UP;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            myWindow.close();
        }
        
        game.runGame(someDirection);
        
        game.drawGame(myWindow);
        
        
        myWindow.display();

    }
    
    game.getSnake().printBody();
    return 0;
}