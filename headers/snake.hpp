#pragma once
#include <SFML/Graphics.hpp> //for the RenderWindow class. Sorry for inputting everything!
//need to find the exact header file for this.
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <deque>
#include "direction.hpp"
#include "food.hpp"
#include "gamescreen.hpp"
#include "grid.hpp"

class Snake : public GameScreen
{
 //   friend void Game::startGame();

    private: 
        //fields
    
        std::deque<sf::RectangleShape> body;
        int length;
      //  static constexpr float blockSize = 10.0;// i would have liked to create a vector2f
        float speedInBlocks;
        bool isAlive;
        Direction state;

        //functions
        bool isFoodHere(const sf::Vector2f &space) const;
        bool isSelfCollision(const sf::Vector2f & );
        bool touchedAWall(const sf::Vector2f &offset, const Grid &grid);
        void die();

    
    public: 

        //functions
        Snake(const sf::Vector2f &startingPoint);
        Snake();

        void move(Direction someDirection, Food &food,const Grid& grid); //using deltaTime for now.



        void update();// might implement this but for now, i'll just change the SnakeRecs wherever SnakeVecs changes.
      
        void drawSnake(sf::RenderWindow &myWindow);
        
        int snakeLength();
        
        
        void printBody();
        bool getIsAlive() {return isAlive;}

};