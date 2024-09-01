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