#include "LinearInterpolator.h"

LinearInterpolator::LinearInterpolator() {
    this->start = 0.0;
    this->end = 0.0;
    this->duration = 0.0;
    this->t = 0.0;
    this->target = 0;
}

LinearInterpolator::~LinearInterpolator() {

}

void LinearInterpolator::attach(double *target) {
    this->target = target;
    this->start = *target;
    this->end = *target;
    this->duration = 1000.0;
    this->t = 1.0;
}

void LinearInterpolator::set(double start, double end, double duration) {
    this->start = start;
    this->end = end;
    this->duration = duration;
    this->t = 0.0;
}

void LinearInterpolator::update(double dt) {
    t += (dt / duration);
    if (t > 1.0) {
        t = 1.0;
    }

    *target = getValue(0.0);
}

double LinearInterpolator::getValue(double edt) {
    double actualT = t + (edt / duration);
    if (actualT > 1.0) {
        actualT = 1.0;
    }

    double value = ((1.0 - actualT) * start) + (actualT * end);

    return value;
}

bool LinearInterpolator::finished() {
    return (t >= 1.0);
}
