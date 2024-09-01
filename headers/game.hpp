/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#pragma once
#include "food.hpp"
#include "gamescreen.hpp"
#include "snake.hpp"
#include "grid.hpp"
#include <SFML/System/Vector2.hpp>

class Game : public GameScreen
{
    private:
     //   static constexpr unsigned int screenHeight = 600, screenWidth = 600 ;
        Snake snake;
        Food food;
        Grid grid;
        int score;
        const sf::Vector2f startingPoint = sf::Vector2f({static_cast<float>(screenHeight/2),static_cast<float>(screenWidth/2)});


    public:
        Game();
        
        void startGame();

        void runGame(Direction someDirection);

        void endGame();

        void drawGame(sf::RenderWindow &window);

        Snake& getSnake() {return snake;}

};