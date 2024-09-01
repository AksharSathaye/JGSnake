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