#include <iostream>
#include "Pokemon.h"

int getInput() {
    int choice;
    std::cin >> choice;
    return choice;
}

void displayMainMenu() {
    std::cout << "Make your selection:\n";
    std::cout << "1 - List\n";
    std::cout << "2 - My team\n";
    std::cout << "3 - Fight\n";
    std::cout << "4 - Quitter\n";
    std::cout << "Selection: ";
}

void mainMenu() {
    int choice = 0;
    do {
        displayMainMenu();
        choice = getInput();
        switch (choice) {
            case 1:
                std::cout << "Show List of pokemons" << std::endl;
                break;
            case 2:
                std::cout << "Show my team" << std::endl;
                break;
            case 3:
                std::cout << "Start a fight" << std::endl;
                break;
            case 4:
                std::cout << "Quit" << std::endl;
                break;
            default:
                std::cout << "Make a choice please" << std::endl;
                break;
        }
    } while (choice!=4);
}

int main() {
    Pokemon carapuce("Carapute", Type::Water, 1);
    std::cout << carapuce.toString() << std::endl;
    mainMenu();
    return 0;
}
