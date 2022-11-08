//
// Created by Jeffrey Duong on 11/16/19.
//

#ifndef PROJECT_ROCKETSHIP_HPP
#define PROJECT_ROCKETSHIP_HPP
#include <SFML/Graphics.hpp>

class RocketShip {
private:
    sf::Sprite rocketship;
    sf::Texture rocketshipTexture;
public:
    RocketShip();
    void setRocketPosition(float x, float y);
    void resetRocket(sf::RenderWindow &window);
    void moveRocket(float x, float y);
    void rotateRocket(float angle);
    sf::Vector2f getRocketPosition();
    float getRocketRotation();
    float getRocketGlobalBoundsWidth();
    float getRocketGlobalBoundsHeight();
    sf::Sprite getRocketSprite() const;

};


#endif //PROJECT_ROCKETSHIP_HPP
