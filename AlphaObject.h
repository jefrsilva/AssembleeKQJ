#ifndef __alphaobject__
#define __alphaobject__

#include "Vector.h"

class AlphaObject {

public:
    AlphaObject();
    AlphaObject(const Vector &position, double rot, double distance,
                int objectType, void *objectPtr);
    ~AlphaObject();

    Vector position;
    double rot;
    double distance;

    int objectType;
    void *objectPtr;

};

#endif // __alphaobject__
