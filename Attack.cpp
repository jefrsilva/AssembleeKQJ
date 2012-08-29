#include "Attack.h"
#include "AttackResult.h"

#include "Engine.h"

#include <sstream>

Attack::Attack() {
    this->name = "";
    this->pattern = "";
    this->damage = 0;
    this->damageBonus = 0;
}

Attack::Attack(std::string name, std::string pattern) {
    this->name = name;
    this->pattern = pattern;
    this->damage = 0;
    this->damageBonus = 0;
}

Attack::Attack(std::string name, std::string pattern, int damage) {
    this->name = name;
    this->pattern = pattern;
    this->damage = damage;
    this->damageBonus = 0;
}

Attack::Attack(std::string pattern, int damage, int damageBonus) {
    this->name = "";
    this->pattern = pattern;
    this->damage = damage;
    this->damageBonus = damageBonus;
}

Attack::~Attack() {

}

std::string Attack::getTooltipString() {
    std::stringstream tooltipStr;
    unsigned char c[] = {16, 17, 18, 19, 20, 21};

    for (unsigned int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'x') {
            tooltipStr << "|888|" << c[0] << "|fff|";
        } else if (pattern[i] == 'W') {
            tooltipStr << c[1];
        } else if (pattern[i] == 'G') {
            tooltipStr << c[2];
        } else if (pattern[i] == 'R') {
            tooltipStr << c[3];
        } else if (pattern[i] == 'B') {
            tooltipStr << c[4];
        } else if (pattern[i] == 'Y') {
            tooltipStr << c[5];
        }
    }

    if (!(pattern.size() == 1 && pattern[0] == 'x')) {
        tooltipStr << " " << damage;

        if (damageBonus) {
            tooltipStr << "(+" << damageBonus << ")";
        }
    }

    return tooltipStr.str();
}

AttackResult Attack::getAttackResult() {
    AttackResult result = AttackResult(name, 'x', 'x', 0, 0);
    
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    unsigned char attackType = pattern[0];
    if (pattern.size() > 1) {
        int randomType = rng->randomInt(0, pattern.size() - 1);
        
        attackType = pattern[randomType];
    }
    
    if (attackType != 'x') {
        result = AttackResult(name, attackType, 'x', damage, damageBonus);
    }
    result.missType = pattern[0];
    
    if (pattern.size() == 1 && pattern[0] == 'x') {
        result.noDamageAttack = true;
    }
    
    return result;
}
