#include "BoundingBox.h"

BoundingBox::BoundingBox(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

BoundingBox::~BoundingBox() {

}

bool BoundingBox::contains(double px, double py) {
    bool contains = false;
    
    if (px >= x && px <= x + width &&
        py >= y && py <= y + height) {
        contains = true;
    }
    
    return contains;
}
