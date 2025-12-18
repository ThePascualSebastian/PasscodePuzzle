#include <iostream>
#include <cstdlib> //For rand() and srand()
#include <ctime> //For time()

using namespace std;

//Constant variables
const int PASSCODE_SIZE = 4;
const int ATTEMPTS = 15;

//Method prototypes
void printGame();
void generatePasscode();
void playerAttempts(int[]);
void runGame();
bool checkAttempt(int[], int[]);

int main() {
    runGame();
}

void printGame() {
    cout << "\nWelcome to Pascual's Passcode Puzzle!" << endl;
    cout << "Do you want $1,000,000,000? Well just guess the correct " << PASSCODE_SIZE << " digit PIN and it is all yours!" << endl;
    cout << "You have " << ATTEMPTS << " attempts and after each unsuccessful attempt two digits will be displayed!" << endl;
    cout << "\"2, 0\" means 2 digits from that guess are in the PIN, but 0 are in the right place." << endl;
    cout << "No two digits in the PIN are the same." << endl;
}

void generatePasscode() {
    int passCode[PASSCODE_SIZE], randomNumber = 0;

    srand(time(0)); //Makes it truly random everytime the program is ran.

    //For loop the random numbers to the array and makes sure no two digits are the same.
    for (int i = 0; i < PASSCODE_SIZE; i++) {
        randomNumber = rand() % 10;
         for (int j = 0; j < PASSCODE_SIZE; j++) {
            if (randomNumber == passCode[j]) {
                randomNumber = rand() % 10;
                j = -1; //Resets it back 0 so it checks all the numbers once again
            }
        }
        passCode[i] = randomNumber;
    }

    playerAttempts(passCode);
}

void playerAttempts(int passCode[]) {
    int playerGuess[PASSCODE_SIZE], attemptNumber = 0;
    bool endGame = false, validInput = false;
    string playAgain, playerNumber;

    while (attemptNumber < ATTEMPTS && !endGame) {
        attemptNumber++;
        cout << "\nGuess #" << attemptNumber << ":" << endl;

        cin >> playerNumber;

        //Checks if the user enter the correct amount of digits
        if (playerNumber.length() != PASSCODE_SIZE) {
            cout << "\nPlease enter " << PASSCODE_SIZE <<" digits!" << endl;
            attemptNumber--;
            continue;
        }
        
        for (int i = 0; i < PASSCODE_SIZE; i++) {
            playerGuess[i] = playerNumber[i] - '0'; //Converts char to int
        }

        endGame = checkAttempt(passCode, playerGuess);
    }

    if (endGame && attemptNumber <= ATTEMPTS) {
    cout << "\nWow great job, here is your reward. + $1,000,000,000." << endl;
    }
    else {
        cout <<"\nYou just lost your chance at $1,000,000,000! Better luck next time!\n" << endl;
        cout <<"Here was the correct "<< PASSCODE_SIZE <<" digit PIN: " << endl;
        for (int i = 0; i < PASSCODE_SIZE; i++) {
            cout << passCode[i];
        }
        printf("\n");
    }
    cout << "\nWould you like to play again? (y/n)" << endl;
    while (!validInput) {
        cin >> playAgain;
        playAgain = tolower(playAgain[0]);
        if (playAgain != "y" && playAgain != "n") {
            cout << "Invalid Input! Please try again." << endl;
        }
        else if (playAgain == "y") {
            cout << "\nWelcome back bozo" << endl;
            generatePasscode();
        }
        else {
            cout << "\nGoodbye! Thanks for playing!" << endl;
            exit(0); //Closes the program.
        }
    }
}

bool checkAttempt(int passCode[], int playerGuess[]) {
    int containsDigit = 0,correctPlace = 0;

    for (int i = 0; i < PASSCODE_SIZE; i++) {
        if (passCode[i] == playerGuess[i]) {
            correctPlace += 1;
        }
       for (int j = 0; j < PASSCODE_SIZE; j++) {
        if (passCode[i] == playerGuess[j]) {
            containsDigit += 1;
        }
       }
    }

    cout << containsDigit << ", " << correctPlace << endl;

    return correctPlace == PASSCODE_SIZE;
}

void runGame() {
    printGame();
    generatePasscode();
}

