#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed the random number generator with the current time
    int targetNumber = rand() % 100 + 1; // Generates a random number between 1 and 100
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!" << std::endl;

    while (true) {
        std::cout << "Guess the number: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << targetNumber << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}

