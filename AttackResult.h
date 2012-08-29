#ifndef __attackresult__
#define __attackresult__

#include <string>

/**
 * \class AttackResult
 * \author Jeferson Rodrigues da Silva
 * \date 12/16/2009
 * \file AttackResult.h
 * \brief 
 */
class AttackResult {

public:
    AttackResult();
    AttackResult(std::string attackName,
                 unsigned char attackType,
                 unsigned char missType,
                 int damage,
                 int damageBonus);
    ~AttackResult();

    std::string attackName;
    unsigned char attackType;
    unsigned char missType;
    int damage;
    int damageBonus;
    bool noDamageAttack;    

};

#endif // __attackresult__
