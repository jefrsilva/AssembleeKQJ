#include "AlphaObject.h"
#include "GlobalConstants.h"

AlphaObject::AlphaObject() {
    this->position = Vector();
    this->rot = 0.0;
    this->distance = 0.0;

    this->objectType = ALPHAOBJECT_TYPE_NONE;
    this->objectPtr = 0;
}

AlphaObject::AlphaObject(const Vector &position, double rot, double distance,
                         int objectType, void *objectPtr) {
    this->position = position;
    this->rot = rot;
    this->distance = distance;
    
    this->objectType = objectType;
    this->objectPtr = objectPtr;
}

AlphaObject::~AlphaObject() {

}
