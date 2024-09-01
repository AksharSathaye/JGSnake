#pragma once

#include "gamescreen.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>

class Food : public GameScreen 
{
    private:
        sf::RectangleShape blob;
        int score;

    public:
        Food();
        
        void regenerate();
        sf::RectangleShape getBlob() {return blob;}
        int getScore() {return score;}
        void drawFood(sf::RenderWindow &window);
};