//
// Created by Jeffrey Duong on 12/6/19.
//

#include <DodgingGame/Sounds.hpp>

Sounds::Sounds(){
    backgroundmusic.openFromFile("DodgingGame/game_sounds/BackGroundMusic.wav");
    clickBuffer.loadFromFile("DodgingGame/game_sounds/Click.wav");
    clickSound.setBuffer(clickBuffer);
    gameOverBuffer.loadFromFile("DodgingGame/game_sounds/GameOver.wav");
    gameOverSound.setBuffer(gameOverBuffer);
    gameWinBuffer.loadFromFile("DodgingGame/game_sounds/GameWin.wav");
    gameWinSound.setBuffer(gameWinBuffer);
}

void Sounds::playMusic() {
    backgroundmusic.play();
}

void Sounds::stopMusic() {
    backgroundmusic.stop();
}

void Sounds::playClick() {
    clickSound.play();
}

void Sounds::playGameOver() {
    gameOverSound.play();
}

void Sounds::playGameWin() {
    gameWinSound.play();
}