/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include "../headers/game.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <string>
#include <fstream>

const sf::Color Game::BACKGROUND_COLOR = sf::Color::Black;
const sf::Vector2f Game::startingPoint = sf::Vector2f({static_cast<float>(GameScreen::screenHeight/2),static_cast<float>(GameScreen::screenWidth/2)});

Game::Game() : snake(Game::startingPoint), food(), grid()
{
    isGameOver = false;
}

void Game::runGame(Direction someDirection)
{

    if(snake.getIsAlive())
    {
        snake.move(someDirection,this->food, this->grid);
    }
    else
    {
        isGameOver = true;
    }

}

void Game::drawGame(sf::RenderWindow &window)
{   
    window.clear(BACKGROUND_COLOR);
    grid.drawGrid(window);
    food.drawFood(window);
    snake.drawSnake(window);
}

void Game::endGame()
{
   std::cout << "Game Over!\n";
   std::cout << "Final Score: " << food.getScore() << '\n'; 
   std::cout << "Press s to record score, press q to exit." << std::endl;
}

bool Game::getIsGameOver()
{
    return isGameOver;
}

void Game::getKeyboardInputs(sf::RenderWindow &window)
{
    Direction someDirection = Direction::NULL_DIRECTION;

    if(getIsGameOver())
    {
        endGame();
        sf::sleep(sf::seconds(0.2f));
        bool hasSaved = false;
        while(true)
        {
            sf::sleep(sf::seconds(0.2f));
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
                return;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !hasSaved)
            {

                std::string name;
                std::cout << "Enter your name: ";
                std::getline(std::cin, name);
                std::ifstream recordsFileIn("records.log");
                bool fileExists = recordsFileIn.good();
                std::ofstream recordsFileOut("records.log", std::ios::app);

                if(recordsFileOut.is_open())
                {
                    if(!fileExists)
                    {
                        std::cout << "Created records.log" << std::endl;
                        recordsFileOut << "Snake Leaderboard\n\n" << std::endl;
                    }
                    recordsFileOut << name << ": " << food.getScore() << std::endl;
                    std::cout << "Record has been written to records.log\nYou may now close the game (press q or Ctrl+C)." << std::endl ; 
                }
                

            }
        }
        window.close();
        return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        std::cout << "Paused. Press Space again to resume." << std::endl;
        sf::sleep(sf::seconds(0.2f));
        while(! sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sf::sleep(sf::seconds(0.2f));
        }
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
        window.close();
    }
    
    runGame(someDirection);
    
    drawGame(window);

}