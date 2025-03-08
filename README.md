# MY_HUNTER - DUCK HUNT (CSFML EDITION)

## 🦆 Project Overview

This project is a 2D Duck Hunt-style game built using CSFML (the C binding for SFML).
The goal is to shoot moving targets (Mario/Lakitu) to score points while ensuring
that targets do not reach the other side of the screen, which results in losing a
life. The game features a menu system, score tracking, and sound effects to
enhance the experience.

## 🎮 Controls & Gameplay

### Controls:

    Left Mouse Button – Shoot at the moving targets.
    Mouse Movement – Aim your crosshair.
    Escape (ESC) – Exit the game.

### How It Works:

The game starts on the main menu, where the player can click Play to begin.

Once started, targets (Mario/Lakitu) move across the screen.

The player must click on the targets to score points.

If a target reaches the other side of the screen, a life is lost. The player starts with 3 lives.

When all lives are lost, the game returns to the menu, displaying "You scored X points".

The player can restart the game or quit.

## 🛠️ Installation & Compilation

### Prerequisites

Ensure you have CSFML installed on your system:

    sudo apt-get install libcsfml-dev  # For Debian/Ubuntu
    brew install csfml                 # For macOS (Homebrew)

Running the Game

Run the compiled executable:

./my_hunter

## 📂 Project Structure

    ├── src/            # Game source code
    │   ├── animate.c   # Handles sprite animations
    │   ├── clean.c     # Memory cleanup functions
    │   ├── crosshair.c # Crosshair rendering
    │   ├── display.c   # Rendering elements on screen
    │   ├── event.c     # Handles user input events
    │   ├── game_state.c# Game state management
    │   ├── get_ressources.c # Load textures, sounds, etc.
    │   ├── lifebar.c   # Manages life display
    │   ├── main.c      # Entry point
    │   ├── mouse.c     # Mouse interactions
    │   ├── my_putchar.c# Custom putchar function
    │   ├── my_putstr.c # Custom putstr function
    │   ├── my_strcmp.c # String comparison function
    │   ├── my_strlen.c # String length function
    │   ├── quitbutton.c# Handles quit button behavior
    │   ├── score.c     # Score management
    │   ├── sound.c     # Sound effects management
    │   ├── sprite.c    # Sprite loading and rendering
    │   └── tty.c       # Terminal utilities
    │
    ├── include/        # Header files
    │   ├── duck_hunt.h # Main header
    │
    ├── audios/         # Sound effects & background music
    │
    ├── graphics/       # Sprites and backgrounds
    │
    ├── Makefile        # Build script
    ├── README.md       # Project documentation

## 🖼️ Assets Used

Sprites: Background, characters, UI elements.

Sounds: Shooting effects, background music.

## 👨‍💻 Author

Arthur Vignes – Developed for EPITECH 2024 (B-MUL-100 Project).

## 🏛️ License

This project is completely free to use.
