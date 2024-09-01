#include "../headers/game.hpp"
#include <iostream>


Game::Game() : snake(this->startingPoint), food()
{

//    snake = Snake(startingPoint);
  //  food = Food();
}

void Game::runGame(Direction someDirection)
{

    if(snake.getIsAlive())
    {
        snake.move(someDirection,this->food);
    }
    else
    {
        std::cout << "Game Over." <<std::endl;
    }


}

void Game::drawGame(sf::RenderWindow &window)
{   
    window.clear();
    food.drawFood(window);
    snake.drawSnake(window);
}
