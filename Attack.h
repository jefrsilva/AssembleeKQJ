#ifndef __attack__
#define __attack__

#include "AttackResult.h"

#include <string>

/**
 * \class Attack
 * \author Jeferson Rodrigues da Silva
 * \date 12/12/2009
 * \file Attack.h
 * \brief 
 */
class Attack { // tolua_export
    
private:
    std::string name;
    std::string pattern;
    int damage;
    int damageBonus;

public:
    Attack();
    Attack(std::string name, std::string pattern);
    Attack(std::string name, std::string pattern, int damage); // tolua_export
    Attack(std::string pattern, int damage, int damageBonus); // tolua_export
    ~Attack();
    
    std::string getTooltipString();
    
    AttackResult getAttackResult();

}; // tolua_export

#endif // __attack__
