#pragma once
#include "gamescreen.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>

class Grid : public GameScreen
{
    private:
        std::vector<sf::RectangleShape> wall;

    public:
        Grid();
        bool isTouchingWall(sf::Vector2f coordinates);
        void drawGrid(sf::RenderWindow &window);


};
