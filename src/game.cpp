/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include "../headers/game.hpp"
#include <iostream>


Game::Game() : snake(this->startingPoint), food(), grid()
{

//    snake = Snake(startingPoint);
  //  food = Food();
}

void Game::runGame(Direction someDirection)
{

    if(snake.getIsAlive())
    {
        snake.move(someDirection,this->food, this->grid);
    }
    else
    {
        endGame();
    }


}

void Game::drawGame(sf::RenderWindow &window)
{   
    window.clear();
    grid.drawGrid(window);
    food.drawFood(window);
    snake.drawSnake(window);
}

void Game::endGame()
{
    std::cout << "Game Over!\n" << std::endl;
    //TODO: Fix this from spamming in the console log. Maybe move the main.cpp's game loop into this class.
}
