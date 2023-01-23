# pacmanProject

# Student details:
   Shahar Hevrony. 209180967
   Lior Yakobovich. 207258625

# General explanations:
   The project presents the game "Super Pacman". In this game the goal of the player is to collect 
   all the cookies on the board without encountering the ghosts. The player can collect gifts that 
   can give him different powers such as adding life, time and more. The player can collect keys that 
   open doors on the board. 
# Files:
   - values.h: Defines constant values in the program and saves the values at each stage of the game.
   - main.cpp: calls the game controller.
   - staticObject.cpp: inherits from object. Defines the objects that do not move on the screen.
     - cookie.cpp: inherits from a staticObject. Manages the collision with various dynamic objects.
     - door.cpp: inherits from a staticObject. Manages the collision with various dynamic objects.
     - key.cpp: inherits from a staticObject. Manages the collision with various dynamic objects.
     - wall.cpp: inherits from a staticObject. Manages the collision with various dynamic objects.
     - gift.cpp: inherits from a staticObject. Manages the collision with various dynamic objects.
   - state.cpp: Dealing with differences between regular Pacman and Super Pacman.
   - resourcesManager.cpp: Loads the texture, the sprite, the font and the buffers and call them by a
     static object.
   - playGame.cpp: Gets a step and executes the game by the keyboard keys, and keeps the rules of the game.
     Delete objects if necessary and prints the objects on the board.
   - object.cpp: Responsible for all the objects on the game board, both static and dynamic.
   - help.cpp:An in-game page that preserves game information.
   - gameOver.cpp: Responsible for ending the game, either by winning or by losing following the end of life.
   - dynamicObject.cpp: inherits from object. Defines the moving objects on the screen.
     - demon.cpp: Inherits from a dynamicObject, executes an algorithm for finding the pacman on the board and
       moving towards it. Moves on the board and manages collisions with all other objects.
     - pacman.cpp: Inherits from a dynamicObject, receives a displacement direction from the keyboard and 
       moves according to it. Manages a collision with all objects and updates the score and life accordingly. 
       Holds a state variable to hold Pacman and Super Pacman conditions if necessary. In a collision with a 
       gift, an algorithm for choosing the type of gift and fulfilling its conditions accordingly.
   - controller.cpp: Manages the home screen of the game and transfers to playGame department each time a 
     different step as needed.
   - board.cpp: Reads the desired step from the file and produces the panel according to the size given in the file.
   - bar.cpp: Manages the board on the side of the game on which he writes the level, the score, the number
     of lives and the time left for the level.

# Data structures:
   - Vector of "unique_ptr" of a staticObject that contain all static object that have texture, type, size and position.
   - Vector of "unique_ptr" of a dynamicObject that contain all dynamic object that have texture, type, size and position.
   - An array of sf::Text in the bar, contain the side text on the board on the side of the game.

# Algorithms
   - Each demon receives the pacman position and also a rand a direction. According to the location of the Pacman, 
     the demon calculates whether it is to the right, left, above or below the Pacman. If the demon tries to take a step
     towards the Pacman, that he has already moved towards last time - it goes according to the rand direction. 
     This creates a situation where the demon doesn't get stuck in place if he don't have the option to move towards Pacman.

# Design:
The program contains objects used by the player during the game and other objects around.
   - The main screen contains buttons to enter the game, help menu and exit.
   - The board on which the game is in real time, holds objects such as Pacman, a demon,
     and various static objects.
   - The game screen also holds the player's scoreboard and mutes the music and returns to the main screen.
   - The help screen holds information about the game and as a return to the main screen.
   - There are also screens to end the game by winning all stages or by ending life.
# Known bugs: 
none at this point.
# Other remarks: 
none