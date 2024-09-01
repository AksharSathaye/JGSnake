#include "../headers/helperfunctions.hpp"
 
sf::Vector2f scaleToMagnitude(const sf::Vector2f &vec, double magnitude)
{
    double modulus = std::sqrt(vec.x*vec.x + vec.y*vec.y);
    sf::Vector2f modifiedVec(vec.x*magnitude/modulus, vec.y*magnitude/modulus);
    return modifiedVec;
}