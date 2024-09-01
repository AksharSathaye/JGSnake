#include "../headers/grid.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

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

    for(int i = 1; i < screenWidth; i++)
    {
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({(float)i,0});
        wall.back().setFillColor(sf::Color::White);
       
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({(float)i,screenHeight-blockSize});
        wall.back().setFillColor(sf::Color::White);
    }

    for(int j = 1; j < screenHeight; j++)
    { 
        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({0,(float)j});
        wall.back().setFillColor(sf::Color::White);

        wall.push_back(sf::RectangleShape({blockSize,blockSize}));
        wall.back().setPosition({screenWidth-blockSize,(float)j});
        wall.back().setFillColor(sf::Color::White);
    }
}

void Grid::drawGrid(sf::RenderWindow &window)
{
    for(auto &square : wall)
    {
        window.draw(square);
    }
}

