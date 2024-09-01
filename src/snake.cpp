#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <deque>
#include "../headers/snake.hpp"
//#include <algorithm>
//#include <random>
#include <iostream>

Snake::Snake(const sf::Vector2f &startingPoint)
{
    body.push_front(sf::RectangleShape({blockSize,blockSize}));
    body.front().setPosition({screenWidth/2,screenHeight/2});
    body.front().setFillColor(sf::Color::Green);

    speedInBlocks = 1.0f;
    isAlive = true;
    state = Direction::RIGHT;
}

/*
*   TODO: figure out how to move the snake.
*
*/
void Snake::move(Direction someDirection, Food &food, const Grid &grid)
{
    if
    (
        (someDirection == Direction::DOWN && state == Direction::UP)
        || (someDirection == Direction::UP && state == Direction::DOWN)
        || (someDirection == Direction::LEFT && state == Direction::RIGHT)
        || (someDirection == Direction::RIGHT && state == Direction::LEFT)
    )
    {
        someDirection = state;
    }
    else
    {
        state = someDirection;
    }

    sf::Vector2f offset;
    
    //The following switch case is supposed to set the value of the new offset.
    
    switch(someDirection) 
    {
        case Direction::UP:
            offset = {0,-speedInBlocks*blockSize};
            break;
        case Direction::DOWN:
            offset = {0,speedInBlocks*blockSize};
            break;
        case Direction::LEFT:
            offset = {-speedInBlocks*blockSize,0};
            break;
        case Direction::RIGHT:
            offset = {speedInBlocks*blockSize,0};
            break;
        default:
            offset = {0,0};
            break;
    }


    if(isSelfCollision(offset) || touchedAWall(offset, grid))
    {
        die(); //since snake touched itself.
    }
    else if((  body.front().getGlobalBounds().intersects(food.getBlob().getGlobalBounds()) ) )
    {
        food.regenerate();
        sf::RectangleShape head = body.front();
        body.push_front(sf::RectangleShape({blockSize,blockSize}));
        //offset.x = blockSize*offset.x/(speedInBlocks*deltaTimeInSeconds);
        //offset.y = blockSize*offset.y/(speedInBlocks*deltaTimeInSeconds);
        body.front().setFillColor(sf::Color::Green);
        body.front().setPosition(head.getPosition()+offset);

    }
    else
    {
        
        body.pop_back();   
        sf::RectangleShape head = body.front();
        body.push_front(sf::RectangleShape({blockSize,blockSize}));
        body.front().setPosition(head.getPosition()+offset);
        body.front().setFillColor(sf::Color::Green);

    }



    //if hitting a wall
    //Okay, so I want it to be smooth on edges.
    // If I'm hitting both right and down, and i'm on the top right.
    // It should move diagonally BUT when it hits the wall it should just
    // start moving down (or right). If neither are then pressed, then the snake can die no problem.
}



void Snake::die()
{
    isAlive = false;
    std::cout << "Died!" << std::endl;
}

//keeping this false until i implement food.
bool Snake::isFoodHere(const sf::Vector2f & space) const
{
    return false;
}


void Snake::drawSnake(sf::RenderWindow &window)
{
    for(auto square : body)
    {
        window.draw(square);
    }
}

int Snake::snakeLength()
{
    return body.size();
}

bool Snake::isSelfCollision(const sf::Vector2f & offset)
{
    for(auto square : body)
    {
        if(square.getPosition() == body.front().getPosition() + offset)
        {
            return true;
        }
    }
    return false;
}

bool Snake::touchedAWall(const sf::Vector2f &offset, const Grid& grid)
{
    if
    (
        body.front().getPosition().x  >= screenWidth-blockSize
        ||  body.front().getPosition().x  <= 0
        ||  body.front().getPosition().y >= screenHeight-blockSize
        ||  body.front().getPosition().y <= 0
        //TODO: These -1s here should not be there. It should be a strict x,y >= screenWidth - blockSize.
    )
    {
        return true;
    }
    else return false;
}

void Snake::printBody()
{
    for(auto &square : body)
    {
        std::cout << square.getPosition().x << ", " << square.getPosition().y << '\n';
    }
}