#ifndef __item__
#define __item__

#include "Vector.h"
#include "Attack.h"
#include "AttackFeedback.h"
#include "Defense.h"

#include <string>
#include <vector>

class Tooltip;
class Tile;
class Monster;
class TextRenderer;

/**
 * \class Item
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file Item.h
 * \brief 
 */
class Item { // tolua_export
    
private:
    std::string id;
    int type;
    std::string name;
    int texture;
    Tooltip *tooltip;
    Tile *tile;
    bool locked;
    
    bool identified;
    
    int slotNumber;
    
    int toughness;
    int durability;
    int delay;
    int delayCounter;
    int weight;
    
    std::string description;
    
    unsigned int currentAttack;
    unsigned int currentDefense;
    
    std::vector<Attack> attacks;
    std::vector<Defense> defenses;
    
    TextRenderer *textRenderer;
    
    bool consumed;

public:
    Item(std::string itemID);
    Item(int type, std::string name, int texture);
    ~Item();
    
    void update(double dt);
    void render(double edt, bool selection);
    void renderOrtho(Vector position, double edt, bool onBar);
    
    Tooltip *getTooltip();
    
    std::string getID();
    
    void setName(std::string name); // tolua_export
    void setTexture(int texture); // tolua_export
    void setType(int type); // tolua_export
    void addAttack(const Attack &attack); // tolua_export
    void addDefense(const Defense &defense); // tolua_export
    void setToughness(int toughness); // tolua_export 
    void setDurability(int durability); // tolua_export
    int getDurability(); 
    void setDelay(int delay); // tolua_export 
    void setWeight(int weight); // tolua_export
    int getWeight();
    void setDescription(std::string description); // tolua_export
    int getType();
    
    void setConsumed(bool consumed); // tolua_export
    bool wasConsumed();
    
    void identify();
    
    void lock();
    void unlock();
    void setSlotNumber(int slotNumber);
    int getSlotNumber();
    
    void setTile(Tile *tile);
    Tile *getTile();
        
    Attack getNextAttack();
    Defense getNextDefense();
    
    void enterDelay();
    void tickDelayCounter();
    void resetDelayCounter();
    bool onDelay();
    
    AttackFeedback attack(Monster *monster);
    DefenseResult defend();
    
    void consume();

}; // tolua_export

#endif // __item__
