/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../headers/snake.hpp"
#include "../headers/direction.hpp"
#include "../headers/gamescreen.hpp"
#include "../headers/game.hpp"
#include "../headers/helperfunctions.hpp"

#include <cmath>



int main()
{

    sf::RenderWindow myWindow(sf::VideoMode(GameScreen::screenWidth,GameScreen::screenHeight), "Snake Game");
    Game game;
    
    sf::Clock myClock;
    
    sf::Time deltaTime = myClock.restart(); 

    while(myWindow.isOpen())
    {
        sf::sleep(sf::seconds(0.04f));

        sf::Event myEvent;

        while(myWindow.pollEvent(myEvent))
        {
            if(myEvent.type == sf::Event::Closed)
            {
                myWindow.close();
                //break;
            }
        }
        
        game.getKeyboardInputs(myWindow);

        myWindow.display();

    }
    
  //  game.getSnake().printBody();
    return 0;
}