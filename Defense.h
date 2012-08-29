#ifndef __defense__
#define __defense__

#include "DefenseResult.h"

#include <string>

/**
 * \class Defense
 * \author Jeferson Rodrigues da Silva
 * \date 12/12/2009
 * \file Defense.h
 * \brief 
 */
class Defense { // tolua_export
    
private:
    std::string pattern;
    int absorption;

public:
    Defense();
    Defense(std::string pattern); // tolua_export
    Defense(std::string pattern, int absorption); // tolua_export
    ~Defense();
    
    std::string getTooltipString();
    std::string getPattern();
    
    DefenseResult getDefenseResult();

}; // tolua_export

#endif // __defense__
