//
// Created by Jeffrey Duong on 11/16/19.
//

#ifndef PROJECT_DODGINGGAME_HPP
#define PROJECT_DODGINGGAME_HPP
#include "../Game/Game.h"
#include "RocketShip.hpp"
#include "Asteroid.hpp"
#include "Background.hpp"
#include "Collision/Collision.h"
#include "Sounds.hpp"
#include "Menu.hpp"
#include <iostream>

struct gameBool{
    bool gameState;
    bool gameLoss;
    bool gameWin;
};

class DodgingGame: public Game {
private:
    RocketShip rocketShip;
    Background background;
    Asteroid asteroids;
    Menu menu;
    Sounds gameSounds;
    sf::Clock clock;
    gameBool gameStatus;
public:
    DodgingGame();
    void start(sf::RenderWindow& window);
    void addEvents(sf::RenderWindow& window);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void collisionTest(sf::RenderWindow &window);
    void rocketEvents(sf::RenderWindow &window);
    void exit();

};


#endif //PROJECT_DODGINGGAME_HPP
