#include <iostream>
#include <random>
#include <limits>
#include <algorithm>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

class NumberGuessingGame {
public:
    enum class Difficulty {
        Easy = 50,
        Medium = 100,
        Hard = 1000
    };

private:
    int secretNumber;
    int maxRange;
    int attempts;
    int lives;

    int generateRandomNumber(int range) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, range);

        return dist(gen);
    }

public:
    explicit NumberGuessingGame(Difficulty level)
        : maxRange(static_cast<int>(level)),
          attempts(0),
          lives(10) {

        secretNumber = generateRandomNumber(maxRange);
    }

    void play() {
        int guess;

        std::cout << CYAN;
        std::cout << "\n=====================================\n";
        std::cout << "       NUMBER GUESSING GAME\n";
        std::cout << "=====================================\n";
        std::cout << RESET;

        std::cout << "Guess a number between 1 and "
                  << maxRange << "\n";
        std::cout << "You have "
                  << lives
                  << " lives.\n\n";

        while (lives > 0) {

            std::cout << BLUE
                      << "Enter your guess: "
                      << RESET;

            while (!(std::cin >> guess)) {
                std::cout << RED
                          << "Invalid input! Enter a number: "
                          << RESET;

                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );
            }

            ++attempts;

            if (guess == secretNumber) {

                int score =
                    std::max(100 - (attempts - 1) * 5, 0);

                std::cout << GREEN;
                std::cout << "\n=====================================\n";
                std::cout << "            YOU WON!\n";
                std::cout << "=====================================\n";
                std::cout << RESET;

                std::cout << "Attempts : "
                          << attempts << "\n";

                std::cout << "Score    : "
                          << score << "\n";

                std::cout << "Congratulations!\n";

                return;
            }

            --lives;

            int difference =
                std::abs(secretNumber - guess);

            if (guess < secretNumber)
                std::cout << YELLOW
                          << "Too Low! ";
            else
                std::cout << YELLOW
                          << "Too High! ";

            if (difference <= 5)
                std::cout << "(Very Close)";
            else if (difference <= 15)
                std::cout << "(Getting Warmer)";
            else
                std::cout << "(Far Away)";

            std::cout << RESET << "\n";

            std::cout << "Lives Remaining: "
                      << lives << "\n\n";
                      
        }

        std::cout << RED;
        std::cout << "\n=====================================\n";
        std::cout << "            GAME OVER\n";
        std::cout << "=====================================\n";
        std::cout << RESET;

        std::cout << "The secret number was: "
                  << secretNumber << "\n";
    }
};

int chooseDifficulty() {

    int choice;

    std::cout << "\nChoose Difficulty\n";
    std::cout << "1. Easy   (1 - 50)\n";
    std::cout << "2. Medium (1 - 100)\n";
    std::cout << "3. Hard   (1 - 1000)\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";

    while (!(std::cin >> choice)
           || choice < 1
           || choice > 4) {

        std::cout << "Please enter 1, 2, 3, or 4: ";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }

    return choice;
}

int main() {

    char playAgain;

    std::cout << CYAN;
    std::cout << "=====================================\n";
    std::cout << "      WELCOME TO THE GAME\n";
    std::cout << "=====================================\n";
    std::cout << RESET;

    do {

        int choice = chooseDifficulty();

        if (choice == 4) {
            std::cout << "\nExiting the game...\n";
            break;
        }

        NumberGuessingGame::Difficulty difficulty;

        switch (choice) {
            case 1:
                difficulty = NumberGuessingGame::Difficulty::Easy;
                break;

            case 3:
                difficulty = NumberGuessingGame::Difficulty::Hard;
                break;

            default:
                difficulty = NumberGuessingGame::Difficulty::Medium;
        }

        NumberGuessingGame game(difficulty);
        game.play();

        std::cout << "\nPlay Again? (y/n): ";
        std::cin >> playAgain;


    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << GREEN
              << "\nThank you for playing!\n"
              << RESET;

    return 0;
}