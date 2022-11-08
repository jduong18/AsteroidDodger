//
// Created by Jeffrey Duong on 12/6/19.
//

#ifndef PROJECT_SOUNDS_HPP
#define PROJECT_SOUNDS_HPP
#include <SFML/Audio.hpp>


class Sounds {
private:
    sf::Music backgroundmusic;
    sf::SoundBuffer clickBuffer;
    sf::Sound clickSound;
    sf::SoundBuffer gameOverBuffer;
    sf::Sound gameOverSound;
    sf::SoundBuffer gameWinBuffer;
    sf::Sound gameWinSound;
public:
    Sounds();
    void playMusic();
    void stopMusic();
    void playClick();
    void playGameOver();
    void playGameWin();

};


#endif //PROJECT_SOUNDS_HPP
