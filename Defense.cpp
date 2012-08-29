#include "Defense.h"

#include "Engine.h"

#include <sstream>

Defense::Defense() {
    this->pattern = "";
    this->absorption = 0;
}

Defense::Defense(std::string pattern) {
    this->pattern = pattern;
    this->absorption = 0;
}

Defense::Defense(std::string pattern, int absorption) {
    this->pattern = pattern;
    this->absorption = absorption;
}

Defense::~Defense() {

}

std::string Defense::getTooltipString() {
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
    
    if (absorption > 0) {
        tooltipStr << " " << absorption;
    }
    
    return tooltipStr.str();
}

std::string Defense::getPattern() {
    return pattern;
}

DefenseResult Defense::getDefenseResult() {
    DefenseResult result = DefenseResult('x', 0);
    
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    unsigned char defenseType = pattern[0];
    if (pattern.size() > 1) {
        int randomType = rng->randomInt(0, pattern.size() - 1);
        
        defenseType = pattern[randomType];
    }
    
    if (defenseType != 'x') {
        result = DefenseResult(defenseType, absorption);
    }
    
    return result;
}
