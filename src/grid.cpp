/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include "../headers/grid.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>


const sf::Color Grid::BORDER_COLOR = sf::Color(0x69,0x69,0x69);

Grid::Grid()
{
    //Push the corners in
  /* wall.push_back(sf::RectangleShape({blockSize,blockSize}));
    wall.back().setPosition({0,0});
    wall.push_back(sf::RectangleShape({blockSize,blockSize}));
    wall.back().setPosition({0,screenWidth});
    wall.push_back(sf::RectangleShape({blockSize,blockSize}));
    wall.back().setPosition({screenHeight,0});
    wall.push_back(sf::RectangleShape({blockSize,blockSize}));
    wall.back().setPosition({screenWidth,screenHeight});
*/

    for(int i = 1; i < screenWidth; i = i + blockSize)
    {
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({(float)i,0});
        wall.back().setFillColor(BORDER_COLOR);
       
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({(float)i,screenHeight-blockSize});
        wall.back().setFillColor(BORDER_COLOR);
    }

    for(int j = 1; j < screenHeight; j=j+blockSize)
    { 
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({0,(float)j});
        wall.back().setFillColor(BORDER_COLOR);

        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({screenWidth-blockSize,(float)j});
        wall.back().setFillColor(BORDER_COLOR);
    }
}

void Grid::drawGrid(sf::RenderWindow &window)
{
    for(auto &square : wall)
    {
        window.draw(square);
    }
}

