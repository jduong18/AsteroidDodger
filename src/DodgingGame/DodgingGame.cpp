//
// Created by Jeffrey Duong on 11/16/19.
//

#include "DodgingGame/DodgingGame.hpp"

DodgingGame::DodgingGame(){
    image_path = "DodgingGame/game_image/asteroid.png";
    info_path = "AsteroidDodgerInfo.txt";
    title = "Asteroid Dodger";
    load_game();
}

//sets position for everything required
void DodgingGame::start(sf::RenderWindow &window) {
    float x = window.getSize().x/2 - rocketShip.getRocketSprite().getGlobalBounds().width/2;
    float y = window.getSize().y/2 - rocketShip.getRocketSprite().getGlobalBounds().height/2;
    rocketShip.setRocketPosition(x,y);
    x = window.getSize().x/2 - menu.getText().getGlobalBounds().width/2;
    y = window.getSize().y/2 - menu.getText().getGlobalBounds().height/2;
    menu.setPosition(x,y);
    x = window.getSize().x/2 - menu.getText2().getGlobalBounds().width/2;
    y = window.getSize().y/2 + menu.getText2().getGlobalBounds().height*2;
    menu.setPosition2(x,y);
    x = window.getSize().x/2 - menu.getText3().getGlobalBounds().width/2;
    y = window.getSize().y/2 - menu.getText3().getGlobalBounds().height;
    menu.setPosition3(x,y);
    gameSounds.playMusic();
    gameStatus.gameState = false;
    gameStatus.gameLoss = false;
    gameStatus.gameWin = false;

}

void DodgingGame::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(background.getBackground(),states);
    if(!gameStatus.gameState) {
        window.draw(menu.getText2());
    }
    if(gameStatus.gameLoss) {
        window.draw(menu.getText());
    }
    if(gameStatus.gameWin){
        window.draw(menu.getText3());
    }
    if(gameStatus.gameState) {
        window.draw(rocketShip.getRocketSprite(), states);
        window.draw(menu.getTimer());
        for(int i = 0; i<10 ;i++){
            window.draw(asteroids.getAsteroidSpriteTop(i),states);
            window.draw(asteroids.getAsteroidSpriteBottom(i),states);
            window.draw(asteroids.getAsteroidSpriteLeft(i),states);
            window.draw(asteroids.getAsteroidSpriteRight(i),states);
        }
    }
}

//Checks for collision from all four sides of asteroids
void DodgingGame::collisionTest(sf::RenderWindow &window) {
    for(int i = 0; i < 10; i++){
        if(Collision::PixelPerfectTest(rocketShip.getRocketSprite(),asteroids.getAsteroidSpriteTop(i))) {
            gameSounds.playGameOver();
            gameStatus.gameState = false;
            gameStatus.gameLoss = true;
            rocketShip.setRocketPosition(window.getSize().x/2 - rocketShip.getRocketSprite().getGlobalBounds().width/2,window.getSize().y/2 - rocketShip.getRocketSprite().getGlobalBounds().height/2);
            clock.restart();
        }
        if(Collision::PixelPerfectTest(rocketShip.getRocketSprite(),asteroids.getAsteroidSpriteBottom(i))) {
            gameSounds.playGameOver();
            gameStatus.gameState = false;
            gameStatus.gameLoss = true;
            rocketShip.setRocketPosition(window.getSize().x/2 - rocketShip.getRocketSprite().getGlobalBounds().width/2,window.getSize().y/2 - rocketShip.getRocketSprite().getGlobalBounds().height/2);
            clock.restart();
        }
        if(Collision::PixelPerfectTest(rocketShip.getRocketSprite(),asteroids.getAsteroidSpriteRight(i))) {
            gameSounds.playGameOver();
            gameStatus.gameState = false;
            gameStatus.gameLoss = true;
            rocketShip.setRocketPosition(window.getSize().x/2 - rocketShip.getRocketSprite().getGlobalBounds().width/2,window.getSize().y/2 - rocketShip.getRocketSprite().getGlobalBounds().height/2);
            clock.restart();
        }
        if(Collision::PixelPerfectTest(rocketShip.getRocketSprite(),asteroids.getAsteroidSpriteLeft(i))) {
            gameSounds.playGameOver();
            gameStatus.gameState = false;
            gameStatus.gameLoss = true;
            rocketShip.setRocketPosition(window.getSize().x/2 - rocketShip.getRocketSprite().getGlobalBounds().width/2,window.getSize().y/2 - rocketShip.getRocketSprite().getGlobalBounds().height/2);
            clock.restart();
        }

    }

}


//overall events depending on what part of the game you are in
void DodgingGame::addEvents(sf::RenderWindow &window) {
    sf::Time timetest;
    timetest = clock.getElapsedTime();
    collisionTest(window);
    if(static_cast<int>(timetest.asSeconds()) > 40 &&gameStatus.gameState){
        gameSounds.playGameWin();
        gameStatus.gameState = false;
        gameStatus.gameLoss = false;
        gameStatus.gameWin = true;
        clock.restart();
    }
    if(!gameStatus.gameState){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            gameSounds.playClick();
            asteroids.setPosition();
            rocketShip.resetRocket(window);
            gameStatus.gameState = true;
            gameStatus.gameLoss = false;
            gameStatus.gameWin = false;
            clock.restart();
        }
    }
    if(gameStatus.gameState){
        rocketEvents(window);
        asteroids.moveAsteroids(static_cast<int>(timetest.asSeconds()));
        menu.setTimerValue(timetest);
    }

    asteroids.resetPosition(window);
}

//All rocket events(movements)
void DodgingGame::rocketEvents(sf::RenderWindow &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (rocketShip.getRocketPosition().y > window.getSize().y - rocketShip.getRocketGlobalBoundsHeight()) {
        } else {
            rocketShip.moveRocket(0, 10);
        }
        if (rocketShip.getRocketRotation() == 180) {
        }
        else {
            if (rocketShip.getRocketRotation() == 90 ) {
                rocketShip.rotateRocket(90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x,
                        rocketShip.getRocketPosition().y + rocketShip.getRocketGlobalBoundsHeight());
            } else if (rocketShip.getRocketRotation() == 0) {
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x + rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y + rocketShip.getRocketGlobalBoundsHeight());
                rocketShip.rotateRocket(180);
            } else {
                rocketShip.rotateRocket(-90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x + rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y);
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (rocketShip.getRocketPosition().y < 50) {
        }
        else {
            rocketShip.moveRocket(0, -10);
        }
        if (rocketShip.getRocketRotation() == 0) {
        }
        else {
            if (rocketShip.getRocketRotation() == 90) {
                rocketShip.rotateRocket(-90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x - rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y);
            }
            else if (rocketShip.getRocketRotation() == 180) {
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x - rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y - rocketShip.getRocketGlobalBoundsHeight());
                rocketShip.rotateRocket(180);
            }
            else {
                rocketShip.rotateRocket(90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x,
                        rocketShip.getRocketPosition().y - rocketShip.getRocketGlobalBoundsHeight());
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (rocketShip.getRocketPosition().x > window.getSize().x - rocketShip.getRocketGlobalBoundsWidth()) {
        }
        else {
            rocketShip.moveRocket(10, 0);
        }
        if (rocketShip.getRocketRotation() == 90) {
        }
        else {
            if (rocketShip.getRocketRotation() == 0) {
                rocketShip.rotateRocket(90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x + rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y);
            }
            else if (rocketShip.getRocketRotation() == 270) {
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x + rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y - rocketShip.getRocketGlobalBoundsHeight());
                rocketShip.rotateRocket(180);
            }
            else {
                rocketShip.rotateRocket(-90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x,
                        rocketShip.getRocketPosition().y - rocketShip.getRocketGlobalBoundsHeight());
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (rocketShip.getRocketPosition().x < 50) {
        }
        else {
            rocketShip.moveRocket(-10, 0);
        }
        if (rocketShip.getRocketRotation() == 270) {
        }
        else {
            if (rocketShip.getRocketRotation() == 0) {
                rocketShip.rotateRocket(-90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x,
                        rocketShip.getRocketPosition().y + rocketShip.getRocketGlobalBoundsHeight());
            }
            else if (rocketShip.getRocketRotation() == 90) {
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x - rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y + rocketShip.getRocketGlobalBoundsHeight());
                rocketShip.rotateRocket(180);
            }
            else {
                rocketShip.rotateRocket(90);
                rocketShip.setRocketPosition(
                        rocketShip.getRocketPosition().x - rocketShip.getRocketGlobalBoundsWidth(),
                        rocketShip.getRocketPosition().y);
            }
        }
    }
}

void DodgingGame::exit(){
    gameSounds.stopMusic();
}