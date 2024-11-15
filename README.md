# Snake Game in C

A classic Snake game implementation in C using the Windows console.

## Description

This is a simple console-based Snake game where players control a snake to eat food (`@`) to grow longer while avoiding walls, the snake's own body, and poison (`#`). The game features score tracking and player name customization.

## Features

- Console-based graphics using Windows API
- Player name input
- Score tracking system
- Food collection system (`@` symbols)
- Poison obstacles (`#` symbols)
- Snake growth mechanics
- Collision detection
- Pause functionality

## Controls

| Key | Action |
|-----|--------|
| W | Move Up |
| S | Move Down |
| A | Move Left |
| D | Move Right |
| B | Pause Game |

## Scoring

- Eating food (`@`): +10 points
- Eating poison (`#`): -10 points and snake shrinks

## Game Over Conditions

- Hitting the walls
- Colliding with the snake's own body
- Snake becomes too short after eating poison

## Technical Implementation

### Built With
- C programming language
- Windows API for console manipulation
- Linked list data structure for snake body management
- Dynamic memory allocation for snake growth

### Key Files
- `main.c`: Game entry point and initialization
- `SNAKE1.h`: Core game logic and functions

## Getting Started

### Prerequisites
- Windows operating system
- GCC compiler or Visual Studio
- Windows.h header support

### Building the Project
The project can be built using either:
- Code::Blocks IDE (using the provided `.cbp` project file)
- Visual Studio (using the provided `.sln` solution file)

## Project Structure

The main game logic is implemented in `SNAKE1.h` which contains:
- Snake movement mechanics
- Food and poison generation
- Collision detection
- Score management
- Console display functions

The game initialization and main loop are handled in `main.c`.

---

**Note:** This is a Windows-specific implementation and won't work on other operating systems due to its dependency on Windows.h and console-specific functions.