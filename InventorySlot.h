#ifndef __inventoryslot__
#define __inventoryslot__

#include "Vector.h"

class TextRenderer;
class Tooltip;
class BoundingBox;

/**
 * \class InventorySlot
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file InventorySlot.h
 * \brief
 */
class InventorySlot {
    
private:
    TextRenderer *textRenderer;
    Tooltip *tooltip;

    int index;
    Vector position;

public:
    InventorySlot(int index, const Vector &position);
    ~InventorySlot();
    
    void update(double dt);
    void render(double edt, bool selection);
    void renderShortcut();
    BoundingBox getBoundingBox();
    void setTooltipVisibility(bool visibility);
    Vector getPosition();
    void setTooltip(Tooltip *tooltip);

};

#endif // __inventoryslot__
