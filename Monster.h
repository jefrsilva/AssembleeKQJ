#ifndef __monster__
#define __monster__

#include "Attack.h"
#include "AttackFeedback.h"
#include "Defense.h"
#include "LinearInterpolator.h"
#include "Vector.h"

#include <string>
#include <vector>
#include <list>

class Tooltip;
class Tile;
class Animation;
class Particle;
class Player;

class Monster { // tolua_export

private:
    int texture;

    bool activated;
    bool endedTurn;
    int stunCounter;

    std::string id;
    std::string instanceID;

    Vector mapPosition;
    Vector worldPosition;
    LinearInterpolator iplWorldX;
    LinearInterpolator iplWorldY;
    LinearInterpolator iplWorldZ;
    LinearInterpolator iplOpacity;
    
    double opacity;

    Tooltip *tooltip;
    Tile *tile;
    std::list<Animation *> animations;

    std::string name;
    int health;
    int maxHealth;
    std::vector<Attack> attacks;
    Defense defenses;
    int toughness;
    int size;
    int weight;
    int activationRange;
    bool rangedAttacker;
    std::vector<std::string> drops;
    
    std::string faction;
    
    double shakeCounter;
    double shakeDuration;

    unsigned int currentAttack;
    unsigned int currentWeakness;

public:
    Monster(std::string id, std::string instanceID);
    ~Monster();

    void update(double dt);
    void render(double edt, bool selection);

    Tooltip *getTooltip();
    
    void setup();

    void setTexture(int texture); // tolua_export
    void addAttack(const Attack &attack); // tolua_export
    void setDefense(const Defense &defense); // tolua_export
    void setName(std::string name); // tolua_export
    std::string getName();
    void setMaxHealth(int maxHealth); // tolua_export
    void setHealth(int health); // tolua_export
    int getHealth();
    void setToughness(int toughness); // tolua_export
    int getToughness();
    void setSize(int size); // tolua_export
    int getSize();
    void setWeight(int weight); // tolua_export
    int getWeight();
    void setActivationRange(int range); // tolua_export
    int getActivationRange();
    void setRangedAttacker(bool ranged); // tolua_export
    bool isRangedAttacker();
    void addItemDrop(std::string itemID); // tolua_export
    std::vector<std::string> getItemDrops();
    void setFaction(std::string faction); // tolua_export
    std::string getFaction();

    std::string getInstanceID();

    void setMapPosition(const Vector &position);
    Vector getMapPosition();
    
    void setWorldPosition(const Vector &position);
    void setWorldDestination(const Vector &position);
    Vector getWorldPosition(double edt);
    
    void setTile(Tile *tile);
    Tile *getTile();

    void activate();
    void deactivate();
    bool isActivated();
    
    bool isMoving();
    
    void resetTurn();
    void endTurn();
    bool hasEndedTurn();
    
    Attack getNextAttack();
    AttackFeedback receiveAttack(AttackResult result);
    void tickStunCounter();
    bool isStunned();
    
    void attachAnimation(Animation *animation);
    std::list<Particle *> getParticles();
    
    void shake(double duration);
    void die();
    bool isAlive();
    
    AttackFeedback attack(Player *player);

}; // tolua_export

#endif // __monster__
