//
// Created by Jeffrey Duong on 11/26/19.
//

#include <DodgingGame/Asteroid.hpp>

Asteroid::Asteroid(){
    for(int i = 0; i<10; i++){
        Top.AsteroidTexture[i].loadFromFile("DodgingGame/game_image/asteroid.png");
        Bottom.AsteroidTexture[i].loadFromFile("DodgingGame/game_image/asteroid.png");
        Left.AsteroidTexture[i].loadFromFile("DodgingGame/game_image/asteroid.png");
        Right.AsteroidTexture[i].loadFromFile("DodgingGame/game_image/asteroid.png");
        Top.AsteroidSprite[i].setTexture(Top.AsteroidTexture[i]);
        Bottom.AsteroidSprite[i].setTexture(Bottom.AsteroidTexture[i]);
        Right.AsteroidSprite[i].setTexture(Right.AsteroidTexture[i]);
        Left.AsteroidSprite[i].setTexture(Left.AsteroidTexture[i]);
        Top.AsteroidSprite[i].setScale(.6,.6);
        Bottom.AsteroidSprite[i].setScale(.6,.6);
        Left.AsteroidSprite[i].setScale(.6,.6);
        Right.AsteroidSprite[i].setScale(.6,.6);
    }
    for(int i = 0; i < 10; i+=2) {
        Top.AsteroidSprite[i].setScale(.5, .5);
        Bottom.AsteroidSprite[i].setScale(.5, .5);
        Left.AsteroidSprite[i].setScale(.5, .5);
        Right.AsteroidSprite[i].setScale(.5, .5);
    }
    setPosition();

    //shuffles order in which asteroids will be sent out on each side
    for(int i = 0; i<10; i++){
        arr.push_back(i);
    }
    for(int i = 0; i<10; i++){
        arr2.push_back(i);
    }
    for(int i = 0; i<10; i++){
        arr3.push_back(i);
    }
    for(int i = 0; i<10; i++){
        arr4.push_back(i);
    }

    
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(arr.begin(), arr.end(),g);
    std::shuffle(arr2.begin(), arr2.end(),g);
    std::shuffle(arr3.begin(), arr3.end(),g);
    std::shuffle(arr4.begin(), arr4.end(),g);

}

sf::Sprite Asteroid::getAsteroidSpriteTop(int i) const{
    return Top.AsteroidSprite[i];
}
sf::Sprite Asteroid::getAsteroidSpriteBottom(int i) const{
    return Bottom.AsteroidSprite[i];
}
sf::Sprite Asteroid::getAsteroidSpriteLeft(int i) const{
    return Left.AsteroidSprite[i];
}
sf::Sprite Asteroid::getAsteroidSpriteRight(int i) const{
    return Right.AsteroidSprite[i];
}

//Start of game, randomizes asteroid position
void Asteroid::setPosition(){
    for(int i = 0; i < 10; i++){
        int temp = rand()%10+1;
        Top.AsteroidSprite[i].setPosition(temp*192,-100);
        Bottom.AsteroidSprite[i].setPosition(temp*192,2000);
        Left.AsteroidSprite[i].setPosition(-100,temp*90);
        Right.AsteroidSprite[i].setPosition(2000,temp*90);
    }
}

//sets asteroids position during game
void Asteroid::resetPosition(sf::RenderWindow &window) {
    for(int i = 0; i < 10; i++){
        int temp = i;
        if(Top.AsteroidSprite[i].getPosition().y > window.getSize().y){
            Top.AsteroidSprite[i].setPosition(temp*210,-100);
        }
        if(Bottom.AsteroidSprite[i].getPosition().y < 0){
            Bottom.AsteroidSprite[i].setPosition(temp*210,1200);
        }
        if(Left.AsteroidSprite[i].getPosition().x > window.getSize().x){
            Left.AsteroidSprite[i].setPosition(-100,temp*120);
        }
        if(Right.AsteroidSprite[i].getPosition().x < 0){
            Right.AsteroidSprite[i].setPosition(2000,temp*120);
        }
    }




}

void Asteroid::moveAsteroids(int time) {
    speed = 5;
    if(time > 10){
        speed = 6;
    }
    if(time > 20){
        speed = 7;
    }
    if(time > 10){
        if(time > 30){
            speed = 8;
        }
        time = 10;
    }

    for(int i = 0; i < time; i++){
        Top.AsteroidSprite[arr[i]].move(0,speed);
        Bottom.AsteroidSprite[arr2[i]].move(0,speed*-1);
        Left.AsteroidSprite[arr3[i]].move(speed,0);
        Right.AsteroidSprite[arr4[i]].move(speed*-1,0);
    }

}
