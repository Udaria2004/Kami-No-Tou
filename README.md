# Members

Udayveer Singh | Arnav Varshney

# Kami No Tou

## Main Character – Akira

“Kami no Tou” is a text based medieval fantasy role playing game. Akira is a poor orphan who’s just turned 18. Eager to
start a new life as an adventurer, you guide his choices as he struggles to find his way to fame, fortune or love. You
must brave dangers, traps and monsters as you ascend the tower. Whether he survives to reach the top or if he should
sucuumbs to the darkness, all depends on you and the choices you make.
To win the game you must beat the final boss at the top of the tower.

## Features

- Engaging fantasy story, where your choices matter
- Text-based RPG with multiple choices
- Meet and interact with NPCs
- Fight horde of monsters
- Go on missions, practice skills and fight deadly battles
- 3 main classes to choose from - Assassin | Archer | Mage

How each feature will satisfy the requirements:

- Generation of random game events - Random fights and traps as you travel up the tower. Random drop items after
  defeating an enemy.
- Data Structures for storing game status - The player status will be stored in data structures (Class player & Struct
  player_stat) such as hp, atk, def etc.
- Dynamic Memory Management - Through lists of possible options in-game.
- File Input/Output - Loading ASCII text art, as well as storylines from txt files.
- Program codes in multiple files - Coded in multiple files for more modular and OOP.

## Rules

For numbered options you must press you must press numbers
For Yes or No questions, please press Y or N (not case-sensitive)

There are mainly 4 locations in the game which you can visit

- House
- Woods
- Guild
- Tower

You start by visiting the guild and obtaining your certificate. After that, you may visit the woods to fight goblins.
Ultimately, you are required to visit the tower to fight the boss and finish the game.
At any point, you may visit your home to replenish your health.

## Special Library

- Unistd.h - Provides the usleep function to implement typewriter effect in utility.cpp.

## How to run

Simply use,

    make main
    ./main

Even though the code resizes the terminal window accordingly, it is recommended to run the game in full-screen mode to
have the best experience possible.

## Sample input/output

Our game is an interactive game and therefore doesn't operate on pre-defined input/output files.

Test 1 Answer = 141 | Test 2 Answer = 24