//
// Created by Jeffrey Duong on 11/26/19.
//

#ifndef PROJECT_ASTEROID_HPP
#define PROJECT_ASTEROID_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <random>

struct AsteroidStruct{
    sf::Sprite AsteroidSprite[10];
    sf::Texture AsteroidTexture[10];
};

class Asteroid {
private:
    AsteroidStruct Top;
    AsteroidStruct Bottom;
    AsteroidStruct Left;
    AsteroidStruct Right;
    int speed;
    std::vector<int> arr;
    std::vector<int> arr2;
    std::vector<int> arr3;
    std::vector<int> arr4;
public:
    Asteroid();
    sf::Sprite getAsteroidSpriteTop(int i) const;
    sf::Sprite getAsteroidSpriteBottom(int i) const;
    sf::Sprite getAsteroidSpriteLeft(int i) const;
    sf::Sprite getAsteroidSpriteRight(int i) const;
    void resetPosition(sf::RenderWindow &window);
    void setPosition();
    void moveAsteroids(int time);

};


#endif //PROJECT_ASTEROID_HPP
