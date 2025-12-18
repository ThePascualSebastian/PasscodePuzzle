# Passcode Puzzle

A C++ terminal game where the player tries to guess a 4-digit PIN to "win" a virtual prize. Each attempt gives feedback on how many digits are correct and how many are in the correct position. The game ensures all digits in the PIN are unique and allows up to 15 attempts per round. Players can replay after a game ends.

## Features:

-   4-digit PIN with all unique digits

-   Up to 15 attempts to guess the PIN

-   Feedback after each guess: number of correct digits and number in the correct position

-   Input validation for 4-digit guesses

-   Option to play again after finishing a round

## Demo:

Welcome to Pascual's Passcode Puzzle!\
Do you want $1,000,000,000? Well just guess the correct 4-digit PIN and it is all yours!\
You have 15 attempts and after each unsuccessful attempt two digits will be displayed!\
"2, 0" means 2 digits from that guess are in the PIN, but 0 are in the right place.\
No two digits in the PIN are the same.

Guess #1:\
1234\
1, 0

Guess #2:\
5678\
2, 1

...\
Wow great job, here is your reward. + $1,000,000,000.

Would you like to play again? (y/n)

Getting Started:

### Prerequisites:

-   C++ compiler (e.g., g++, clang++)

-   Terminal or command line access

### Installation:

1.  Clone or download the repository:\
    git clone https://github.com/ThePascualSebastian/PasscodePuzzle.git

2.  Navigate to the project folder:\
    cd PasscodePuzzle

3.  Compile the program:\
    g++ PasscodePuzzle.cpp -o PasscodePuzzle

4.  Run the program:\
    ./PasscodePuzzle

## Usage:

-   Enter a 4-digit guess when prompted.

-   The program will display two numbers: total correct digits and how many are in the correct position.

-   Continue guessing until the PIN is fully guessed or attempts run out.

-   After the game, choose whether to play again.
