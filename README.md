
# Dungeons and Dragons Game

# Table of Contents

* [About Project](#about-project)
* [Video Showcase](#video-showcase)
* [Getting Started](#getting-started)

## About Project

This project is a Dungeons and Dragons-style game implemented in C++, featuring a procedurally generated dungeon that offers a unique experience on each playthrough. Players can choose from three difficulty levels: Easy, Medium, and Hard, each influencing the number of rooms, monsters, and other elements within the dungeon.

This game showcases object-oriented programming principles such as polymorphism, inheritance, and the use of design patterns (State, Singleton). 

The game contains the following features: 
* **Character Creation**
    - User is able to set their own name and description for their monk. 
* **Unique Monsters**
    - Each monster will have their own unique name, description and stats.
    - Some monsters are able to defend while some can't.
    - Some monsters are able to perform a special ability that is unique. 
* **Difficulty**
    - Easy:
        - 3 Monsters
        - Minimum of 1 empty room but a chance to have a max of 2
        - No upgrade rooms
    - Medium:
        - 4 Monsters.
        - Minimum of 1 empty room but a chance to have a max of 2
        - Chance to have 1 upgrade room
    - Hard
        - 6 Monsters
        - Minimum of 2 empty rooms but a chance top have a max of 3
        - Minimum of 1 upgrade room but a chance to have a mx of 2
* **Unique Rooms**
    - Monster Room: Battle with a unique monster with attack or defend options (50% chance of being successful). 
    - Empty Room: Pray and restore their health to the max.
    - Upgrade Room: Upgrade either their health or attack points.
    - Treasure Room: Final room upon beating all the monsters. 
* **Game Summary**
    - Keeps track of all stats within the game.
    - At the end, the user is presented with their game summary which is also saved in a text file.

## Video Showcase
Click the image below to view a video showcasing the entire app and how to use each feature:
[![App Showcase](https://img.youtube.com/vi/T55vrH6DmOk/0.jpg)](https://youtu.be/T55vrH6DmOk)

## Getting Started
This section will cover how to setup the project and get it running within your system

1. Download the repo.
2. Install an IDE such as [Visual Studio](https://visualstudio.microsoft.com/downloads/) or a C++ Complier.
3. Open the project within IDE 
    - If you are using a terminal instead of an IDE, please ensure you [download Git](https://git-scm.com/)
    - Open your terminal and run the following command to clone the project from GitHub: `git clone https://github.com/yourusername/dnd-game.git`
    - Navigate into the project directory: `cd "Monk Game"`
    - Build the project with the `make` command
4. Run the project using the Run or Execute button.
