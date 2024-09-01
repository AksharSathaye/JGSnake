/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#pragma once
#include "gamescreen.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>

class Grid : public GameScreen
{
    private:
        static const sf::Color BORDER_COLOR;
        std::vector<sf::RectangleShape> wall;

    public:
        Grid();
        bool isTouchingWall(sf::Vector2f coordinates);
        void drawGrid(sf::RenderWindow &window);


};
