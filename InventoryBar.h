#ifndef __inventorybar__
#define __inventorybar__

#include "InventorySlot.h"
#include "Vector.h"

#include <vector>

class Player;
class Item;

/**
 * \class InventoryBar
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file InventoryBar.h
 * \brief
 */
class InventoryBar {
    
private:
    Player *player;
    std::vector<InventorySlot *> slots;
    Vector cursorPosition;
    bool showTooltips;

public:
    InventoryBar(Player *player);
    ~InventoryBar();
    
    void update(double dt);
    void render(double edt, bool selection);
    
    void setCursorPosition(const Vector &position);
    int getSlotNumber(const Vector &position);
    Vector getSlotPosition(int slot);
    
    bool attachItem(Item *item, const Vector &position);
    Item *detachItem(const Vector &position);
    Item *getItem(const Vector &position);
    
    void setTooltipVisibility(bool visibility);

};

#endif // __inventorybar__
