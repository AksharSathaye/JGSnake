/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#pragma once
#include <SFML/Graphics.hpp> //for the RenderWindow class. Sorry for inputting everything!
//need to find the exact header file for this.
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <deque>
#include "direction.hpp"
#include "food.hpp"
#include "gamescreen.hpp"
#include "grid.hpp"

class Snake : public GameScreen
{
 //   friend void Game::startGame();

    private: 
        //fields
        std::deque<sf::RectangleShape> body;
        int length;
      //  static constexpr float blockSize = 10.0;// i would have liked to create a vector2f
        float speedInBlocks;
        bool isAlive;
        Direction state;

        //functions
        bool isFoodHere(const sf::Vector2f &space) const;
        bool isSelfCollision(const sf::Vector2f & );
        bool touchedAWall(const sf::Vector2f &offset, const Grid &grid);
        void die();

    
    public: 

        //functions
        Snake(const sf::Vector2f &startingPoint);
        Snake();
        static const sf::Color SNAKE_COLOR;

        void move(Direction someDirection, Food &food,const Grid& grid); //using deltaTime for now.



        void update();// might implement this but for now, i'll just change the SnakeRecs wherever SnakeVecs changes.
      
        void drawSnake(sf::RenderWindow &myWindow);
        
        int snakeLength();
        
        
        void printBody();
        bool getIsAlive() {return isAlive;}

};