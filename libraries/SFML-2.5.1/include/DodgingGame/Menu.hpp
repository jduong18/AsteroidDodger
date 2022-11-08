//
// Created by Jeffrey Duong on 12/3/19.
//

#ifndef PROJECT_MENU_HPP
#define PROJECT_MENU_HPP
#include <SFML/Graphics.hpp>
#include <string>

class Menu {
private:
    sf::Font font;
    sf::Text text; // "GameOver"
    sf::Text text2;// "Space to Start"
    sf::Text text3;// "You Win"
    sf::Text timer;
public:
    Menu();
    sf::Text getText() const;
    sf::Text getText2() const;
    sf::Text getText3() const;
    sf::Text getTimer() const;
    void setPosition(float x, float y);
    void setPosition2(float x, float y);
    void setPosition3(float x, float y);
    void setTimerValue(sf::Time time);


};

#endif //PROJECT_MENU_HPP