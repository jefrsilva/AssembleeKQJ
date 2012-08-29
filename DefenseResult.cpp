#include "DefenseResult.h"

DefenseResult::DefenseResult() {
    this->defenseType = 'x';
    this->absorption = 0;
}

DefenseResult::DefenseResult(unsigned char defenseType, int absorption) {
    this->defenseType = defenseType;
    this->absorption = absorption;
}

DefenseResult::~DefenseResult() {
    
}
