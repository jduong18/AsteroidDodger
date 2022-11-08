//
// Created by Jeffrey Duong on 12/3/19.
//

#include <DodgingGame/Menu.hpp>

Menu::Menu(){
    font.loadFromFile("DodgingGame/PressStart2p.ttf");
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(80);
    text2.setFont(font);
    text2.setString("Press Space to Start");
    text2.setCharacterSize(30);
    text3.setFont(font);
    text3.setString("You Win!");
    text3.setCharacterSize(100);
}

sf::Text Menu::getText() const{
    return text;
}

sf::Text Menu::getText2() const{
    return text2;
}

sf::Text Menu::getText3() const{
    return text3;
}

sf::Text Menu::getTimer() const{
    return timer;
}
void Menu::setPosition(float x, float y) {
    text.setPosition(x,y);
}

void Menu::setPosition2(float x, float y){
    text2.setPosition(x,y);
}

void Menu::setPosition3(float x, float y){
    text3.setPosition(x,y);
}

//Takes time as time type and casts to int then set to string
void Menu::setTimerValue(sf::Time time){
    timer.setFont(font);
    std::string temp = std::to_string(static_cast<int>(time.asSeconds()));
    timer.setString(temp);
}