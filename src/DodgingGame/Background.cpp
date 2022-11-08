//
// Created by Jeffrey Duong on 11/26/19.
//

#include <DodgingGame/Background.hpp>

Background::Background() {
    BackgroundTexture.loadFromFile("DodgingGame/game_image/background.png");
    BackgroundSprite.setTexture(BackgroundTexture);
}

sf::Sprite Background::getBackground() const{
    return BackgroundSprite;
}