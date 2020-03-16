#include "Pokemon.h"

Pokemon::Pokemon(const std::string &name, Type type, int level) :
        name(name),
        type(type),
        level(level),
        isKO(false),
        attackNames({}) {
    int maxHealth = 30 + level * 10;
    Pokemon::maxHealthPoints = maxHealth;
    Pokemon::healthPoints = maxHealth;
}

const std::string &Pokemon::getName() const {
    return name;
}

void Pokemon::setName(const std::string &name) {
    Pokemon::name = name;
}

std::string Pokemon::getTypeStr() const {
    return TypeStr[(int) type];
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

std::string Pokemon::toString() {
    return Pokemon::name + " " + Pokemon::getTypeStr() + " lvl." + std::to_string(Pokemon::level) + " " +
           std::to_string(Pokemon::healthPoints) + "/" +
           std::to_string(Pokemon::maxHealthPoints);
}

Pokemon::~Pokemon() {

}
