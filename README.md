
# Mine Sweeper

A Fun and interactive mine sweeper game.

## Table of Contents
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Setup and Installation](#setup-and-installation)
- [How to Use](#how-to-use)
- [Screenshots](#screenshots)
- [Future Improvements](#future-improvements)

---

## Features
- Interactable game with working wining and losing
- Ability to set flags and questionable

---

## Technologies Used
- **C++**: Core language for application logic.
- **QT6GUI**: For GUI design and interaction.
- **CMAKE**: For building

---

## Setup and Installation

### Prerequisites
Ensure you have the following installed:
- C++17 or Higher
- QT6.22GUI or Higher
- CMake 3.2 or Higher
- GUI: X11 or Wayland (Linux)

### Steps to Run Locally Linux
1. Clone this repository:
   ```bash
   git clone https://github.com/AFamiliarQueasySensation/MineSweeper

2. Navigate to the project directory: (If not created make a new folder)
    ```bash
    cd MineSweeper/build
3. Compile using the location of CMakeLists.txt: 
   ```bash
    cmake ..
5. Build:
   ```bash
    make
6. Run a compatable GUI (X11 or Wayland)
7. Run the newly created executable:
   ```bash
    ./MineSweep

### Steps to Run Locally Windows
1. Clone this repository:
   ```bash
   git clone https://github.com/AFamiliarQueasySensation/MineSweeper

2. Navigate to the project directory: (If not created make a new folder)
    ```bash
    cd MineSweeper/build
3. Compile using the location of CMakeLists.txt: 
   ```bash
    cmake ..
5. Build:
   ```bash
    make
7. Run the newly created executable:
   ```bash
    ./MineSweep

**Main Class**: main.cpp <br>
**Project**: MineSweep<br>

## How To Use
1. Press an initial square, either explode or continue
2. If continue either right click to flag a square or click
3. Right click a flagged square to set questionable

## Screenshots
_Main Window_ <br>
<img src="https://cdn.discordapp.com/attachments/561769547745722379/1333921653796769853/image.png?ex=679aa6d9&is=67995559&hm=2df77aa5ea71f184e468efec681ac86d47ef612f204b4636dab9a40baf614563" alt="Main Window" width="300">


## Future Improvements
- Score System
- In game Timer
- Menu to set amount of mines and amount of squares
- Leaderboard

---

_**MineSweeper created by:** Grant Von Hagen_
