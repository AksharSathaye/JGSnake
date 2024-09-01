/*
    Copyright 2024 Akshar Sathaye
    This file is part of JGSnake.
    JGSnake is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    JGSnake is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with JGSnake. If not, see <https://www.gnu.org/licenses/>. 
*/
#include "../headers/food.hpp"


Food::Food()
{
    blob = sf::RectangleShape({blockSize,blockSize});
    blob.setFillColor(sf::Color::Red);

    blob.setPosition(3*screenWidth/4,screenHeight/4);   
    score = 0;
}

void Food::regenerate()
{
    int newFoodX = std::rand();
    int newFoodY = std::rand();
    
    newFoodX = newFoodX % static_cast<int>(screenWidth-blockSize-blockSize);
    newFoodY = newFoodY % static_cast<int>(screenHeight-blockSize-blockSize);
    newFoodX += blockSize;
    newFoodY += blockSize;
    newFoodX = newFoodX - (newFoodX % static_cast<int>(blockSize));
    newFoodY = newFoodY - (newFoodY % static_cast<int>(blockSize));

    //TODO: all the modulus and adding bs I did for newFoodX and Y is to try and get their coordinates between
    // (blockSize,blockSize) to (screenWidth-blockSize, screenHeight-blockHeight). Seems to work but may need to test later.

    blob.setPosition
    (
        static_cast<float>(newFoodX),
        static_cast<float>(newFoodY)
    );       
    
    score++;
}

void Food::drawFood(sf::RenderWindow &window)
{
    window.draw(blob);
}