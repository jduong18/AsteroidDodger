//
// Created by Jeffrey Duong on 11/26/19.
//

#ifndef PROJECT_BACKGROUND_HPP
#define PROJECT_BACKGROUND_HPP
#include<SFML/Graphics.hpp>


class Background {
private:
    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;
public:
    Background();
    sf::Sprite getBackground() const;
};


#endif //PROJECT_BACKGROUND_HPP
