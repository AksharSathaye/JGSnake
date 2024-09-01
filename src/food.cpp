#include "../headers/food.hpp"

Food::Food()
{
    blob = sf::RectangleShape({blockSize,blockSize});
    blob.setFillColor(sf::Color::Red);

    blob.setPosition(3*blockSize/4,blockSize/4);   
    score = 0;
}

void Food::regenerate()
{
    int newFoodX = std::rand();
    int newFoodY = std::rand();
    
    newFoodX = newFoodX % static_cast<int>(screenWidth);
    newFoodY = newFoodY % static_cast<int>(screenHeight);

    newFoodX = newFoodX - (newFoodX % static_cast<int>(blockSize));
    newFoodY = newFoodY - (newFoodY % static_cast<int>(blockSize));

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