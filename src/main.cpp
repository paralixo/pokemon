#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
#include "pokemons/Squirtle.h"
#include "pokemons/Charmander.h"
#include "pokemons/Bulbasaur.h"

int getInput() {
    int choice;
    std::cin >> choice;
    return choice;
}

void displayMainMenu() {
    std::cout << "Make your selection:\n";
    std::cout << "1 - List\n";
    std::cout << "2 - Modify team\n";
    std::cout << "3 - Fight\n";
    std::cout << "4 - Quit\n";
    std::cout << "Selection: ";
}

void changeTeamMember(Trainer &trainer) {
    // TODO: check input
    // TODO: verify list of pokemons
    int teamIndex = 0;
    std::cout << trainer.getTeamList();
    std::cout << "Remove: ";
    teamIndex = getInput();

    int listIndex = 0;
    std::cout << trainer.getPokemonList();
    std::cout << "Add: ";
    listIndex = getInput();

    trainer.modifyPokemonTeam(teamIndex, listIndex);
}

Trainer generateEnemy() {
    // TODO: put pokemons in a file
    std::vector<Pokemon> pokemons{Squirtle(1), Charmander(1), Bulbasaur(1)};
    int randomIndex = std::rand() % pokemons.size();
    Trainer enemy("Savage", pokemons[randomIndex]);
    enemy.addPokemonInTeam(pokemons[randomIndex]);
    std::cout << "Enemy: " + enemy.toString() << std::endl;
    return enemy;
}

void displayFightMenu() {
    std::cout << "What are you doing against your enemy?\n";
    std::cout << "1 - Attack\n";
    std::cout << "2 - Change pokemon\n";
    std::cout << "3 - Catch them all\n";
    std::cout << "4 - Leave\n";
    std::cout << "Selection: ";
}

void catchPokemon(Trainer& trainer, Trainer& enemy) {
    Pokemon catchedPokemon = enemy.getActivePokemon();
    trainer.addPokemon(catchedPokemon);
    std::cout << "You catched " + catchedPokemon.toString() << std::endl;
    std::cout << "You: " + trainer.toString() << std::endl;
}

void handleFight(Trainer& trainer) {
    Trainer enemy = generateEnemy();
    int choice = 0;
    int switchIndex = 0;
    do {
        displayFightMenu();
        choice = getInput();
        switch (choice) {
            case 1:
                std::cout << "TODO: handle different attacks" << std::endl;
                break;
            case 2:
                std::cout << trainer.getTeamList() << std::endl;
                switchIndex = getInput();
                trainer.switchActivePokemon(switchIndex - 1);
                std::cout << trainer.toString() << std::endl;
                break;
            case 3:
                catchPokemon(trainer, enemy);
                break;
            case 4:
                std::cout << "Fleeing the fight." << std::endl;
                break;
            default:
                std::cout << "Make a choice please." << std::endl;
                break;
        }
    } while (choice != 4 && choice != 3);
}

void mainMenu(Trainer &trainer) {
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
                handleFight(trainer);
                break;
            case 4:
                std::cout << "Quit." << std::endl;
                break;
            default:
                std::cout << "Make a choice please." << std::endl;
                break;
        }
    } while (choice != 4);
}

int main() {
    Squirtle carapuce(1);
    Charmander salapute(2);
    Bulbasaur bulbipute(1);
    Trainer florian("Florian", carapuce);
    //florian.addPokemon(carapuce);
    //florian.addPokemon(bulbipute);
    //florian.addPokemon(salapute);
    florian.addPokemonInTeam(carapuce);
    //florian.addPokemonInTeam(bulbipute);
    //florian.addPokemonInTeam(salapute);

    florian.switchActivePokemon(0);

    //std::cout << carapuce.toString() << std::endl;
    std::cout << florian.toString() << std::endl;

    mainMenu(florian);
    return 0;
}
