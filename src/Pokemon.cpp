//
// Created by flori on 16/03/2020.
//

#include "../include/Pokemon.h"

Pokemon::Pokemon(const std::string &name, Type type, int level) :
        name(name),
        type(type),
        level(level),
        maxHealthPoints(30 + level * 10),
        healthPoints(maxHealthPoints),
        isKO(false),
        attackNames({}) {}

const std::string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const std::string &name) {
    Pokemon::name = name;
}

Type Pokemon::getType() const {
    return type;
}

void Pokemon::setType(Type type) {
    Pokemon::type = type;
}

int Pokemon::getLevel() const {
    return level;
}

void Pokemon::setLevel(int level) {
    Pokemon::level = level;
    Pokemon::maxHealthPoints = Pokemon::maxHealthPoints + (level * 10);
    // TODO: upgrade attacks
}

int Pokemon::getHealthPoints() const {
    return healthPoints;
}

void Pokemon::setHealthPoints(int healthPoints) {
    if (healthPoints <= 0) {
        Pokemon::isKO = true;
    } else {
        Pokemon::isKO = false;
        Pokemon::healthPoints = healthPoints;
    }
}

bool Pokemon::isKo() const {
    return isKO;
}

void Pokemon::setIsKo(bool isKo) {
    isKO = isKo;
}

const std::vector<std::string> &Pokemon::getAttackNames() const {
    return attackNames;
}

void Pokemon::setAttackNames(const std::vector<std::string> &attackNames) {
    Pokemon::attackNames = attackNames;
}

void Pokemon::addAttackName(const std::string &attackName) {
    Pokemon::attackNames.push_back(attackName);
}

int Pokemon::getMaxHealthPoints() const {
    return maxHealthPoints;
}

void Pokemon::setMaxHealthPoints(int maxHealthPoints) {
    Pokemon::maxHealthPoints = maxHealthPoints;
}
