#include "AttackResult.h"

AttackResult::AttackResult() {
    this->attackName = "";
    this->attackType = 'x';
    this->missType = 'x';
    this->damage = 0;
    this->damageBonus = 0;
    this->noDamageAttack = false;
}

AttackResult::AttackResult(std::string attackName,
                           unsigned char attackType,
                           unsigned char missType,
                           int damage,
                           int damageBonus) {
    this->attackName = attackName;
    this->attackType = attackType;
    this->missType = missType;
    this->damage = damage;
    this->damageBonus = damageBonus;
    this->noDamageAttack = false;    
}

AttackResult::~AttackResult() {

}
