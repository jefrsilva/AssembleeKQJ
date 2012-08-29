#ifndef __defensefeedback__
#define __defensefeedback__

#include "DefenseResult.h"

/**
 * \class DefenseFeedback
 * \author Jeferson Rodrigues da Silva
 * \date 01/02/2010
 * \file DefenseFeedback.h
 * \brief 
 */
class DefenseFeedback {

public:
	DefenseFeedback();
    DefenseFeedback(DefenseResult result, int totalDamage);
	~DefenseFeedback();
    
    DefenseResult result;
    int totalDamage;

};

#endif // __defensefeedback__
