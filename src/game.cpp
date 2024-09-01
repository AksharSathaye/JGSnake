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
