#include "Game.h"
#include "Utils.h"
#include <iostream>

int main() {
    Utils::clearScreen();
    Utils::printHeader();

    std::string name1, name2;
    int rounds;

    std::cout << "Введите имя первого игрока: ";
    std::getline(std::cin, name1);

    std::cout << "Введите имя второго игрока: ";
    std::getline(std::cin, name2);

    std::cout << "Введите количество побед для победы в игре (по умолчанию 3): ";
    std::string roundsInput;
    std::getline(std::cin, roundsInput);

    if (roundsInput.empty()) {
        rounds = 3;
    } else {
        rounds = std::stoi(roundsInput);
    }

    Game game(name1, name2, rounds);
    game.start();

    std::cout << "\nСпасибо за игру!\n";
    std::cout << "Нажмите Enter для выхода...";
    std::cin.get();

    return 0;
}