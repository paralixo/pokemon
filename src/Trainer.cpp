#include "Trainer.h"

Trainer::Trainer(const std::string &name, Pokemon &activePokemon) : name(name), activePokemon(activePokemon) {}

const std::string &Trainer::getName() const {
    return name;
}

void Trainer::setName(const std::string &name) {
    Trainer::name = name;
}

const std::vector<Pokemon> &Trainer::getPokemons() const {
    return pokemons;
}

void Trainer::setPokemons(const std::vector<Pokemon> &pokemons) {
    Trainer::pokemons = pokemons;
}

const std::vector<Pokemon> &Trainer::getTeam() const {
    return team;
}

void Trainer::setTeam(const std::vector<Pokemon> &team) {
    Trainer::team = team;
}

Pokemon &Trainer::getActivePokemon() const {
    return activePokemon;
}

void Trainer::setActivePokemon(Pokemon &activePokemon) {
    Trainer::activePokemon = activePokemon;
}

void Trainer::addPokemon(Pokemon pokemon) {
    pokemons.push_back(pokemon);
}

void Trainer::addPokemonInTeam(Pokemon pokemon) {
    if (team.size() >= 6) {
        return;
    }
    team.push_back(pokemon);
}

void Trainer::switchActivePokemon(int index) {
    activePokemon = team[index];
}

std::string Trainer::getPokemonList() {
    std::string list = name + "'s pokemons:\n";
    int index = 1;
    for (Pokemon pokemon : pokemons) {
        list += std::to_string(index) + ") " + pokemon.toString() + "\n";
        index++;
    }
    return list;
}

std::string Trainer::getTeamList() {
    std::string list = name + "'s team:\n";
    int index = 1;
    for (Pokemon pokemon : team) {
        list += std::to_string(index) + ") " + pokemon.toString() + "\n";
        index++;
    }
    return list;
}

std::string Trainer::toString() {
    return name + " " + activePokemon.toString();
}

void Trainer::modifyPokemonTeam(int teamIndex, int listIndex) {
    teamIndex--;
    listIndex--;
    Pokemon removedPokemon = team[teamIndex];
    Pokemon addedPokemon = pokemons[listIndex];
    team[teamIndex] = addedPokemon;
    pokemons[listIndex] = removedPokemon;
}

Trainer::~Trainer() {

}
