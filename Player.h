#ifndef __player__
#define __player__

#include <vector>

#include "LinearInterpolator.h"
#include "Vector.h"
#include "Attack.h"
#include "AttackFeedback.h"
#include "DefenseFeedback.h"
#include "DefenseResult.h"

#include <list>
#include <map>

class Item;
class Animation;
class Particle;

/**
 * \class Player
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file Player.h
 * \brief
 */
class Player { // tolua_export
    
private:
    int maxHealth;
    int health;
    
    DefenseResult currentDefense;
    
    Vector mapPosition;
    Vector worldPosition;
    LinearInterpolator iplWorldX;
    LinearInterpolator iplWorldZ;
    
    double shakeCounter;
    double shakeDuration;

    double viewAngle;
    LinearInterpolator iplViewAngle;
    
    std::list<Animation *> animations;
    
    std::vector<Item *> inventory;
    
    std::map<std::string, int> factions;
    
    bool endedTurn;

public:
    Player();
    ~Player();
    
    void addHealth(int amount);
    
    std::vector<Item *> getInventory();

    void addItem(Item *item, int slot); // tolua_export
    void removeItem(Item *item);
    int getItemSlot(Item *item);
    void lockItem(Item *item);
    void unlockItem(Item *item);
    
    void update(double dt);
    void renderOrtho();
    
    void setMapPosition(const Vector &position, double viewAngle);
    Vector getMapPosition();
    Vector getWorldPosition();
    Vector getWorldPosition(double edt);
    double getViewAngle();
    double getViewAngle(double edt);
    
    void setDefense(DefenseResult defenseResult);
    DefenseResult getDefense();
    
    void setMapDestination(const Vector &destination);
    void setWorldDestination(const Vector &destination);
    void setViewDestination(double angle);
    
    bool isMoving();
    
    void tickInventoryDelay();
    void resetInventoryDelay();
    
    void attachAnimation(Animation *animation);
    std::list<Particle *> getParticles();
    
    void shake(double duration);
    DefenseFeedback takeDamage(AttackFeedback attackFeedback);
    
    void endTurn();
    void resetTurn();
    bool hasEndedTurn();
    
    bool hasItem(std::string itemID);
    
    // tolua_begin
    void setHealth(int health);
    int getHealth();
    void setMaxHealth(int maxHealth);
    int getMaxHealth();    
    
    void setFactionStance(std::string faction, int stance);
    int getFactionStance(std::string faction);
    // tolua_end

}; // tolua_export

#endif // __player__
