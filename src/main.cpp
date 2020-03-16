#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"

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

void changeTeamMember(Trainer& trainer) {
    // TODO: check input
    // TODO: verify list of pokemons
    int teamIndex = 0;
    std::cout << trainer.getTeamList() << std::endl;
    teamIndex = getInput();

    int listIndex = 0;
    std::cout << trainer.getPokemonList() << std::endl;
    listIndex = getInput();

    trainer.modifyPokemonTeam(teamIndex, listIndex);
}

void mainMenu(Trainer& trainer) {
    int choice = 0;
    do {
        displayMainMenu();
        choice = getInput();
        switch (choice) {
            case 1:
                std::cout << trainer.getPokemonList() << std::endl;
                break;
            case 2:
                changeTeamMember(trainer);
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
    Pokemon salapute("Salapute", Type::Fire, 1);
    Pokemon bulbipute("Bulbipute", Type::Grass, 1);
    Trainer florian("Florian", carapuce);
    florian.addPokemon(carapuce);
    florian.addPokemon(bulbipute);
    florian.addPokemon(salapute);
    //florian.addPokemonInTeam(carapuce);
    florian.addPokemonInTeam(bulbipute);
    florian.addPokemonInTeam(salapute);

    florian.switchActivePokemon(0);

    //std::cout << carapuce.toString() << std::endl;
    std::cout << florian.toString() << std::endl;

    mainMenu(florian);
    return 0;
}
