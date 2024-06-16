# MagnoliaRPG

MagnoliaRPG is a simple text-based RPG game written in C++. The game features a player character and an enemy character, with a menu system allowing the player to view stats and start battles.

## Table of Contents

* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installing `make` on Windows](#installing-make-on-windows)
* [Building the Project](#building-the-project)
* [Gameplay](#gameplay)

## Getting Started

### Prerequisites

To build and run MagnoliaRPG, you need:

- A C++ compiler (`g++` recommended)
- `make` utility

### Installing `make` on Windows

If you're using Windows, you can install `make` via Chocolatey:

1. Install Chocolatey by following the instructions at [chocolatey.org](https://chocolatey.org/install).
2. Open an elevated (administrator) PowerShell or Command Prompt and run:
   ```sh
   choco install make

## Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/WZhengJie99/MagnoliaRPG
    cd MagnoliaRPG/

3. Compile the project using make:
    ```sh
    make

4. After building the project, run the executable:
    ```sh
    ./MagnoliaRPG

6. Note - To remove the compiled files and the executable, run:
    ```sh
    make clean

## Gameplay

Upon running the game, you will be presented with a menu:

<p align="center">
  <img src="https://github.com/WZhengJie99/MagnoliaRPG/assets/147889572/f28ad8e4-fab4-4d1a-9c4b-3cbe7a6d1335" alt="RPG Menu" width="80%" height="80%">
</p>



1. View Stats: Displays the player's stats.
2. View Inventory: Displays the player's Inventory.
3. Start Battle: Initiates a battle between the player and the enemy.
4. Use Item: Use an item in the player's Inventory.
5. Travel to location: travel to a different place.
6. Exit: Exits the game.

<!-- 
Compile the project with the 'g++ -Iinclude src/*.cpp -o MagnoliaRPG' command to ensure the compiler can find the header files.
Run: Execute the compiled program with './MagnoliaRPG'.
-->
