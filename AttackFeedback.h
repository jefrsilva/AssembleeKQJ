#ifndef __attackfeedback__
#define __attackfeedback__

#include "AttackResult.h"

/**
 * \class AttackFeedback
 * \author Jeferson Rodrigues da Silva
 * \date 12/16/2009
 * \file AttackFeedback.h
 * \brief 
 */
class AttackFeedback {

public:
    AttackFeedback();
    AttackFeedback(AttackResult result, int totalDamage,
                   bool wasCritical, bool stunnedEnemy, bool defeatedEnemy);
    ~AttackFeedback();

    AttackResult result;
    int totalDamage;
    bool wasCritical;
    bool stunnedEnemy;
    bool defeatedEnemy;

};

#endif // __attackfeedback__
