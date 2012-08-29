#ifndef __linearinterpolator__
#define __linearinterpolator__

/**
 * \class LinearInterpolator
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file LinearInterpolator.h
 * \brief
 */
class LinearInterpolator {

private:
    double start;
    double end;
    double *target;
    double t;
    double duration;

public:
    LinearInterpolator();
    ~LinearInterpolator();

    void attach(double *target);
    void set(double start, double end, double duration);
    void update(double dt);
    double getValue(double edt);
    
    bool finished();

};

#endif // __linearinterpolator__
