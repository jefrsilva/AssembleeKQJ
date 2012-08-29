#include "AttackFeedback.h"

AttackFeedback::AttackFeedback() {
    this->result = AttackResult();
    this->totalDamage = 0;
    this->wasCritical = false;
    this->stunnedEnemy = false;
    this->defeatedEnemy = false;
}

AttackFeedback::AttackFeedback(AttackResult result, int totalDamage,
                               bool wasCritical, bool stunnedEnemy,
                               bool defeatedEnemy) {
    this->result = result;
    this->totalDamage = totalDamage;
    this->wasCritical = wasCritical;
    this->stunnedEnemy = stunnedEnemy;
    this->defeatedEnemy = defeatedEnemy;
}

AttackFeedback::~AttackFeedback() {

}
