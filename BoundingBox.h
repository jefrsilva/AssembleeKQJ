#ifndef __boundingbox__
#define __boundingbox__

/**
 * \class BoundingBox
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file BoundingBox.h
 * \brief 
 */
class BoundingBox {
    
public:
    BoundingBox(double x, double y, double width, double height);
    ~BoundingBox();
    
    double x;
    double y;
    double width;
    double height;
    
    bool contains(double x, double y);

};

#endif // __boundingbox__
