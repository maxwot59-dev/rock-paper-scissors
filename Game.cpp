#include "Game.h"
#include "Utils.h"
#include <iostream>

Game::Game(const std::string& name1, const std::string& name2, int rounds)
        : player1(name1), player2(name2), roundsToWin(rounds) {}

int Game::determineWinner(int choice1, int choice2) {
    if (choice1 == choice2) return 0; // Ничья

    // Правила: 0-камень, 1-бумага, 2-ножницы
    if ((choice1 == 0 && choice2 == 2) || // Камень > Ножницы
        (choice1 == 1 && choice2 == 0) || // Бумага > Камень
        (choice1 == 2 && choice2 == 1))   // Ножницы > Бумага
        return 1; // Победа первого игрока

    return 2; // Победа второго игрока
}

void Game::printResult(int choice1, int choice2, int winner) {
    std::cout << "\n--- Результат раунда ---\n";
    std::cout << player1.getName() << ": " << Utils::choiceToString(choice1) << "\n";
    std::cout << player2.getName() << ": " << Utils::choiceToString(choice2) << "\n\n";

    if (winner == 0) {
        std::cout << "НИЧЬЯ!\n";
    } else if (winner == 1) {
        std::cout << player1.getName() << " побеждает!\n";
        player1.incrementScore();
    } else {
        std::cout << player2.getName() << " побеждает!\n";
        player2.incrementScore();
    }

    std::cout << "Счет: " << player1.getName() << " " << player1.getScore()
              << " - " << player2.getScore() << " " << player2.getName() << "\n";
}

void Game::start() {
    Utils::clearScreen();
    Utils::printHeader();

    std::cout << "Игра до " << roundsToWin << " побед!\n\n";

    while (player1.getScore() < roundsToWin && player2.getScore() < roundsToWin) {
        std::cout << "\n=== Новый раунд ===\n";

        int choice1 = player1.makeChoice();
        int choice2 = player2.makeChoice();

        int winner = determineWinner(choice1, choice2);
        printResult(choice1, choice2, winner);

        std::cout << "\nНажмите Enter для продолжения...";
        std::cin.ignore();
        std::cin.get();
        Utils::clearScreen();
        Utils::printHeader();
    }

    std::cout << "\n=== ИГРА ОКОНЧЕНА ===\n";
    std::cout << "ФИНАЛЬНЫЙ СЧЕТ:\n";
    std::cout << player1.getName() << " " << player1.getScore()
              << " - " << player2.getScore() << " " << player2.getName() << "\n\n";

    if (player1.getScore() > player2.getScore()) {
        std::cout << "🎉 ПОБЕДИТЕЛЬ: " << player1.getName() << "! 🎉\n";
    } else {
        std::cout << "🎉 ПОБЕДИТЕЛЬ: " << player2.getName() << "! 🎉\n";
    }
}