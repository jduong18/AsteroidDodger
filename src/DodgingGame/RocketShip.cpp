//
// Created by Jeffrey Duong on 11/16/19.
//

#include <DodgingGame/RocketShip.hpp>

RocketShip::RocketShip(){
    sf::Image image;
    image.loadFromFile("DodgingGame/game_image/ship.png");
    image.createMaskFromColor(sf::Color::White);
    rocketshipTexture.loadFromImage(image);
    rocketship.setTexture(rocketshipTexture);
    rocketship.setScale(.06,.06);
};
void RocketShip::setRocketPosition(float x, float y){
    sf::Vector2f positionVector(x,y);
    rocketship.setPosition(positionVector);
}
void RocketShip::resetRocket(sf::RenderWindow &window){
    float x = window.getSize().x/2 - rocketship.getGlobalBounds().width/2;
    float y = window.getSize().y/2 - rocketship.getGlobalBounds().height/2;
    rocketship.setPosition(x,y);
    rocketship.setRotation(0);
}
void RocketShip::moveRocket(float x, float y){
    rocketship.move(x,y);
}


void RocketShip::rotateRocket(float angle){
    rocketship.rotate(angle);
}

sf::Vector2f RocketShip::getRocketPosition() {
    return rocketship.getPosition();
}

sf::Sprite RocketShip::getRocketSprite() const{
    return rocketship;
}
float RocketShip::getRocketRotation() {
    return rocketship.getRotation();
}
float RocketShip::getRocketGlobalBoundsWidth(){
    return rocketship.getGlobalBounds().width;
}
float RocketShip::getRocketGlobalBoundsHeight(){
    return rocketship.getGlobalBounds().height;
}

