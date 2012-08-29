#ifndef __vector__
#define __vector__

const double EPSILON = 1.0e-5;

#include <cmath>

class Vector {

public:
    Vector();

    Vector(double x, double y);
    Vector(double x, double y, double z);
    Vector(Vector a, Vector b);
    ~Vector();

    double x;
    double y;
    double z;

    double length();
    Vector normalize();
    Vector translate(Vector t);
    double dot(Vector other);
    Vector cross(Vector other);
    Vector mult(double s);

};

#endif
