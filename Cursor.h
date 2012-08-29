#ifndef __cursor__
#define __cursor__

#include "Vector.h"

class Item;

/**
 * \class Cursor
 * \author Jeferson Rodrigues da Silva
 * \date 12/09/2009
 * \file Cursor.h
 * \brief 
 */
class Cursor {
    
private:
    Vector position;
    Item *item;

public:
    Cursor();
    ~Cursor();
    
    void update(double dt);
    void render(double edt);
    
    void setPosition(const Vector &position);
    Vector getPosition();

    Item *getItem();
    void attachItem(Item *item);
    Item *detachItem();

};

#endif // __cursor__
