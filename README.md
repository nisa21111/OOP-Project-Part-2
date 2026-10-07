# Robot Battle Arena

The second part of my project. A turn-based, console robot combat game written in **C++** as the second part of my OOP project.
Pick a robot, equip a weapon, and defeat the enemy robot.

## Features

- 3 robot classes, with stats and special ability
- 3 weapons with different damage / energy cost / special effects
- Random enemy robot and random enemy weapon every battle
- Save / load a battle from a text file (`date.txt`)
- In-game **Info** menu explaining the rules
- Exception handling for invalid equips, bad files and unknown types

## How to play

The goal is simple: **kill the enemy robot.**

### Main menu

| Option | What it does |
|--------|--------------|
| 1. Choose your Robot | Pick Tank, Assasin or Sniper |
| 2. Equip a Weapon | Pick Laser Gun, Crossbow or Rocket Launcher |
| 3. Start the Battle | Fight a randomly generated enemy |
| 4. Info | Shows the rules in-game |
| 5. Exit | Quit the game |
| 6. Load Game | Resume a battle saved in `date.txt` |

### Robots

| Robot | Style | Special ability |
|-------|-------|-----------------|
| **Tank** | Lots of HP, low damage, slow | Activates a **shield** – takes less damage the next time it's attacked |
| **Assasin** | Very fast, slightly more damage than a Tank, low HP | Gets an **extra round** |
| **Sniper** | High damage, faster than a Tank, low HP | Activates **crit** – next attack deals more damage |

### Weapons

| Weapon | Description |
|--------|-------------|
| **Laser Gun** | Fast and energy-efficient, but low damage. Small chance to give back 5 energy when used |
| **Crossbow** | More damage than the Laser Gun, costs more energy. Small chance of extra damage |
| **Rocket Launcher** | Huge damage and huge energy cost. **One-time use** |

## Project structure

```
.
├── main.cpp            # menu, game loop, factory functions (random + from file)
├── Arena.h / .cpp      # battle logic between two robots
├── Robot.h / .cpp      # abstract base class for all robots
├── Tank.h / .cpp       # Tank robot
├── Assasin.h / .cpp    # Assasin robot
├── Sniper.h / .cpp     # Sniper robot
├── Weapon.h / .cpp     # base Weapon + LaserGun, Crossbow, RocketLauncher
├── date.txt            # example save file for "Load Game"
├── structure.txt       # quick overview of the files
└── .gitignore
```
