#pragma once
#include <SFML/Graphics.hpp> //for the RenderWindow class. Sorry for inputting everything!
//need to find the exact header file for this.
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <deque>
#include "direction.hpp"

class Snake
{
    private:
    
       // std::deque<sf::Vector2f> snakeVecs;
        std::deque<sf::RectangleShape> body;
        int length;
        static constexpr float blockSize = 10.0;// i would have liked to create a vector2f
        float speedInBlocks;
        bool isAlive;
        Direction state;

    
    public:
        Snake(const sf::Vector2f &startingPoint);

        /*
        *   TODO: figure out how to move the snake.
        *
        */
        void move(Direction someDirection, sf::RectangleShape &food); //using deltaTime for now.

        void die();

        bool isFoodHere(const sf::Vector2f &space) const;

        void update();// might implement this but for now, i'll just change the SnakeRecs wherever SnakeVecs changes.
        void drawSnake(sf::RenderWindow &myWindow);
        //THIS FUNCTION JUST DRAWS, it does NOT display! That will be done in main
        int snakeLength();
        bool isSelfCollision(const sf::Vector2f & );
        bool touchedAWall(const sf::Vector2f &offset);
        void printBody();

};