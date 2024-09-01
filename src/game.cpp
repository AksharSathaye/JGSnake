/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include "../headers/game.hpp"
#include <iostream>

const sf::Color Game::BACKGROUND_COLOR = sf::Color::White;

Game::Game() : snake(this->startingPoint), food(), grid()
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
    //isGameOver = true;

   std::cout << "Game Over!\n";
   std::cout << "Final Score: " << food.getScore() << '\n';
   std::cout << "Press q to exit." << std::endl;
    //TODO: Fix this from spamming in the console log. Maybe move the main.cpp's game loop into this class.
}

bool Game::getIsGameOver()
{
    return isGameOver;
}