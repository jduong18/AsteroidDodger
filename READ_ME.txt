In order to compile and link properly, must be using MinGW-32 version 7.3.0  





Path to include -> PATH\TO\libraries\SFML-2.5.1\include   

Path to lib -> PATH\TO\libraries\SFML-2.5.1\lib




*All header files will be inside the "include" subfolder shown above, 
this includes SFML header files as well as the program specific header files, 
a common point of error is not being able to find these header files, if such 
errors do occur, please first ensure that the include path is correct. 
In VSCode this can be accessed through the "c_cpp_properties.json"




Command to compile:
g++ -c main.cpp Game\Game_Interface.cpp Game\Game.cpp Game\GameText.cpp Game\Thumbnail.cpp 
DodgingGame\Asteroid.cpp DodgingGame\Background.cpp DodgingGame\DodgingGame.cpp DodgingGame\Menu.cpp 
DodgingGame\RocketShip.cpp DodgingGame\Sounds.cpp DodgingGame\Collision\Collision.cpp -I<PATH\TO\include>





Command to link:
g++ Asteroid.o Background.o Collision.o Game_Interface.o GameText.o Menu.o RocketShip.o 
Thumbnail.o DodgingGame.o Sounds.o Game.o main.o -o dodging-game 
-L<Path\To\Lib> -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system 