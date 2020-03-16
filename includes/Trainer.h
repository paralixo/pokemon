#ifndef POKEMON_TRAINER_H
#define POKEMON_TRAINER_H

#include <iostream>
#include <vector>
#include "Pokemon.h"

class Trainer {
private:
    std::string name;
    std::vector<Pokemon> pokemons;
    std::vector<Pokemon> team;
    Pokemon& activePokemon;

public:
    Trainer(const std::string &name, Pokemon &activePokemon);
    virtual ~Trainer();

    const std::string &getName() const;
    void setName(const std::string &name);
    const std::vector<Pokemon> &getPokemons() const;
    void setPokemons(const std::vector<Pokemon> &pokemons);
    const std::vector<Pokemon> &getTeam() const;
    void setTeam(const std::vector<Pokemon> &team);
    Pokemon& getActivePokemon() const;
    void setActivePokemon(Pokemon &activePokemon);

    void addPokemon(Pokemon pokemon);
    void addPokemonInTeam(Pokemon pokemon);
    void switchActivePokemon(int index);
    std::string getPokemonList();
    std::string getTeamList();
    std::string toString();
    void modifyPokemonTeam(int teamIndex, int listIndex);
};

#endif //POKEMON_TRAINER_H
