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
    blob.setPosition
    (
        static_cast<float>(newFoodX % static_cast<int>(screenWidth))
    ,   static_cast<float>(newFoodY %  static_cast<int>(screenHeight))
    );       
    
    score++;
}

void Food::drawFood(sf::RenderWindow &window)
{
    window.draw(blob);
}