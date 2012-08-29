#include "RandomNumberGenerator.h"

#include <ctime>
#include <cstdlib>

using namespace Engine;

RandomNumberGenerator::RandomNumberGenerator() {
    srand((unsigned)time(0));    
}

RandomNumberGenerator::~RandomNumberGenerator() {
    
}

double RandomNumberGenerator::randomReal() {
    return ((double)rand() / (double)RAND_MAX);
}

double RandomNumberGenerator::randomReal(double minValue, double maxValue) {
    double t = randomReal();
    
    return (1.0 - t) * minValue + (t * maxValue);
}

int RandomNumberGenerator::randomInt(int minValue, int maxValue) {
    int randomValue;
    int range = (maxValue - minValue) + 1;

    randomValue = minValue + int(range * (double)rand() / ((double)RAND_MAX + 1.0));

    return randomValue;
}
