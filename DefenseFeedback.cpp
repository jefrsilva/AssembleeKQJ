#include "DefenseFeedback.h"

DefenseFeedback::DefenseFeedback() {
    this->result = DefenseResult();
    this->totalDamage = 0;
}

DefenseFeedback::DefenseFeedback(DefenseResult result, int totalDamage) {
    this->result = result;
    this->totalDamage = totalDamage;
}

DefenseFeedback::~DefenseFeedback() {
    
}
