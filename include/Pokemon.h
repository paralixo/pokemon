#ifndef POKEMON_POKEMON_H
#define POKEMON_POKEMON_H

#include <iostream>
#include <vector>
#include "PokemonType.h"

class Pokemon {
private:
    std::string name;
    Type type;
    int level;
    int healthPoints;
    int maxHealthPoints;
    bool isKO;
    std::vector<std::string> attackNames;

public:
    Pokemon(const std::string &name, Type type, int level);
    virtual ~Pokemon();

    const std::string &getName() const;
    void setName(const std::string &name);
    std::string getTypeStr() const;
    Type getType() const;
    void setType(Type type);
    int getLevel() const;
    void setLevel(int level);
    int getMaxHealthPoints() const;
    void setMaxHealthPoints(int maxHealthPoints);
    int getHealthPoints() const;
    void setHealthPoints(int healthPoints);
    bool isKo() const;
    void setIsKo(bool isKo);
    const std::vector<std::string> &getAttackNames() const;
    void setAttackNames(const std::vector<std::string> &attackNames);
    void addAttackName(const std::string &attackName);

    std::string toString();
};


#endif //POKEMON_POKEMON_H
