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

<p align="left">
  <img src="https://github.com/WZhengJie99/MagnoliaRPG/assets/147889572/db54ee48-bdc8-409e-b612-f85222e0499c" alt="RPG Menu" width="20%" height="20%">
</p>

* View Stats: Displays the player's and enemy's stats.
* Start Battle: Initiates a battle between the player and the enemy.
* Exit: Exits the game.

<!-- 
Compile the project with the 'g++ -Iinclude src/*.cpp -o MagnoliaRPG' command to ensure the compiler can find the header files.
Run: Execute the compiled program with './MagnoliaRPG'.
-->