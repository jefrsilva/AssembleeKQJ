#ifndef __randomnumbergenerator__
#define __randomnumbergenerator__

namespace Engine {

    /**
     * \class RandomNumberGenerator
     * \author Jeferson Rodrigues da Silva
     * \date 12/13/2009
     * \file RandomNumberGenerator.h
     * \brief
     */
    class RandomNumberGenerator {

    public:
        RandomNumberGenerator();
        ~RandomNumberGenerator();

        double randomReal();
        double randomReal(double minValue, double maxValue);
        int randomInt(int minValue, int maxValue);

    };

}

#endif // __randomnumbergenerator__
