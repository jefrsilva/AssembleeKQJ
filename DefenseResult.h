#ifndef __defenseresult__
#define __defenseresult__

/**
 * \class DefenseResult
 * \author Jeferson Rodrigues da Silva
 * \date 12/16/2009
 * \file DefenseResult.h
 * \brief 
 */
class DefenseResult {

public:
    DefenseResult();
    DefenseResult(unsigned char type, int absorption);
    ~DefenseResult();

    unsigned char defenseType;
    int absorption;

};

#endif // __defenseresult__
