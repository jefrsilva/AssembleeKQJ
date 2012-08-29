#include "Monster.h"
#include "Player.h"
#include "Tooltip.h"
#include "Attack.h"
#include "Defense.h"
#include "Animation.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <sstream>

Monster::Monster(std::string id, std::string instanceID) {
    this->id = id;
    this->instanceID = instanceID;

    this->name = "";

    this->texture = -1;

    this->activated = false;
    this->endedTurn = true;
    this->stunCounter = 0;

    tooltip = new Tooltip();
    tooltip->setOrigin(Vector());

    this->tile = 0;

    this->health = 0;
    this->maxHealth = 0;
    this->toughness = 0;

    this->size = 0;

    this->opacity = 1.0;
    this->iplOpacity.attach(&this->opacity);

    this->shakeCounter = 0.0;
    this->shakeDuration = 0.0;

    this->currentAttack = 0;
    this->currentWeakness = 0;

    this->mapPosition = Vector();
    this->worldPosition = Vector();

    this->iplWorldX.attach(&worldPosition.x);
    this->iplWorldY.attach(&worldPosition.y);
    this->iplWorldZ.attach(&worldPosition.z);
    
    this->faction = "";
    this->activationRange = 0;
    this->rangedAttacker = false;
}

Monster::~Monster() {
    if (this->tooltip) {
        delete this->tooltip;
        this->tooltip = 0;
    }
}

void Monster::update(double dt) {
    iplWorldX.update(dt);
    iplWorldY.update(dt);
    iplWorldZ.update(dt);
    iplOpacity.update(dt);

    shakeCounter += dt;
    if (shakeCounter > shakeDuration) {
        shakeCounter = shakeDuration;
    }

    std::list<Animation *>::iterator it = animations.begin();

    bool finished = false;
    while (it != animations.end() && !finished) {
        Animation *animation = (*it);
        if (animation->hasFinished()) {
            it = animations.erase(it);
        } else {
            it++;
        }
    }
}

void Monster::render(double edt, bool selection) {
    if (selection) {
        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        unsigned int selectionID = videoSystem->getSelectionID();
        videoSystem->setSelectionObject(selectionID, SEL_OBJ_MONSTER, this);

        int b = selectionID / (256 * 256);
        selectionID -= b * (256 * 256);

        int g = selectionID / 256;
        selectionID -= g * 256;

        int r = selectionID;

        glColor4f((double)r / 255.0,
                  (double)g / 255.0,
                  (double)b / 255.0, 1.0f);
    }

    double pw = 1.0 / TEX_IMAGE_MONSTERS_WIDTH;
    double ph = 1.0 / TEX_IMAGE_MONSTERS_HEIGHT;

    double monsterWidth = size * (TEX_MONSTERS_WIDTH) * pw;
    double monsterHeight = size * (TEX_MONSTERS_HEIGHT) * ph;

    double row = texture / 12;
    double col = texture % 12;

    double hOffset = pw + col * (10 * pw);
    double vOffset = ph + (1.0 - (row + size) * (10 * ph));

    double monsterSize = size * MONSTER_SIZE;

    Vector shaking = Vector();
    if (shakeCounter < shakeDuration) {
        shaking = Vector(sin(shakeCounter * SHAKE_SPEED) * (1.0 / TILE_SIZE),
                         0.0, 0.0);
    }

    if (!selection) {
        glColor4f(1.0f, 1.0f, 1.0f, opacity);
    }

    glBegin(GL_TRIANGLE_STRIP);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset + monsterWidth, vOffset);
    glVertex3f(monsterSize / 2.0 + shaking.x, 0.0f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset + monsterWidth, vOffset + monsterHeight);
    glVertex3f(monsterSize / 2.0 + shaking.x, monsterSize, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset, vOffset);
    glVertex3f(-monsterSize / 2.0 + shaking.x, 0.0f, 0.0f);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset, vOffset + monsterHeight);
    glVertex3f(-monsterSize / 2.0 + shaking.x, monsterSize, 0.0f);

    glEnd();
}

Tooltip *Monster::getTooltip() {
    std::vector<std::string> text;
    text.push_back(name);
    text.push_back("");

    std::stringstream healthStr;
    healthStr << "Health__ : " << health << " / " << maxHealth;
    text.push_back(healthStr.str());

    for (unsigned int i = 0; i < attacks.size(); i++) {
        std::stringstream attackPattern;
        if (i == 0) {
            attackPattern << "Attacks_ : " << attacks[i].getTooltipString();
        } else {
            attackPattern << "____ : " << attacks[i].getTooltipString();
        }

        if (i == currentAttack) {
            attackPattern << " |fe6|<|fff|";
        }

        text.push_back(attackPattern.str());
    }

    text.push_back("");

    std::stringstream defensesStr;
    defensesStr << "Weakness_ : ";

    std::string defenseStr = defenses.getTooltipString();
    if (currentWeakness > 0) {
        defensesStr << "|333|";
        for (unsigned int i = 0; i < currentWeakness; i++) {
            defensesStr << defenseStr[i];
        }
        defensesStr << "|fff|";
        for (unsigned int i = currentWeakness; i < defenseStr.size(); i++) {
            defensesStr << defenseStr[i];
        }
    } else {
        defensesStr << defenseStr;
    }

    text.push_back(defensesStr.str());

    std::stringstream toughnessStr;
    toughnessStr << "Toughness_ : " << toughness;
    text.push_back(toughnessStr.str());

    tooltip->setText(text);

    return tooltip;
}

void Monster::setup() {
    Engine::ScriptingSystem *scriptingSystem = 
        Engine::Core::getInstance()->getScriptingSystem();
        
    lua_State *luaState = scriptingSystem->getLuaState();
    
    lua_getglobal(luaState, id.c_str());
    lua_pushstring(luaState, "setup");
    lua_gettable(luaState, -2);
    tolua_pushusertype(luaState, (void *)this, "Monster");    
    lua_call(luaState, 1, 0);
    lua_pop(luaState, 1);
}

void Monster::setTexture(int texture) {
    this->texture = texture;
}

void Monster::addAttack(const Attack &attack) {
    attacks.push_back(attack);
}

void Monster::setDefense(const Defense &defense) {
    defenses = defense;
}

void Monster::setName(std::string name) {
    this->name = name;
}

std::string Monster::getName() {
    return this->name;
}

void Monster::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}

void Monster::setHealth(int health) {
    this->health = health;
}

int Monster::getHealth() {
    return this->health;
}

void Monster::setToughness(int toughness) {
    this->toughness = toughness;
}

int Monster::getToughness() {
    return this->toughness;
}

void Monster::setSize(int size) {
    this->size = size;
}

int Monster::getSize() {
    return this->size;
}

void Monster::setWeight(int weight) {
    this->weight = weight;
}

int Monster::getWeight() {
    return this->weight;
}

void Monster::setActivationRange(int range) {
    this->activationRange = range;
}

int Monster::getActivationRange() {
    return this->activationRange;
}

void Monster::setRangedAttacker(bool ranged) {
    this->rangedAttacker = ranged;
}

bool Monster::isRangedAttacker() {
    return rangedAttacker;
}

void Monster::addItemDrop(std::string itemID) {
    drops.push_back(itemID);
}

std::vector<std::string> Monster::getItemDrops() {
    return drops;
}

void Monster::setFaction(std::string faction) {
    this->faction = faction;
}

std::string Monster::getFaction() {
    return faction;
}

std::string Monster::getInstanceID() {
    return instanceID;
}

void Monster::setMapPosition(const Vector &position) {
    mapPosition = position;
}

Vector Monster::getMapPosition() {
    return mapPosition;
}

void Monster::setWorldPosition(const Vector &position) {
    worldPosition = position;
}

void Monster::setWorldDestination(const Vector &position) {
    iplWorldX.set(worldPosition.x, position.x, WALK_SPEED);
    iplWorldZ.set(worldPosition.z, position.z, WALK_SPEED);
}

Vector Monster::getWorldPosition(double edt) {
    Vector position = Vector(iplWorldX.getValue(edt),
                             iplWorldY.getValue(edt),
                             iplWorldZ.getValue(edt));

    return position;
}

void Monster::activate() {
    activated = true;
}

void Monster::deactivate() {
    activated = false;
}

bool Monster::isActivated() {
    return activated;
}

void Monster::setTile(Tile *tile) {
    this->tile = tile;
}

Tile *Monster::getTile() {
    return this->tile;
}

bool Monster::isMoving() {
    bool moving = true;

    if (iplWorldX.finished() && iplWorldZ.finished()) {
        moving = false;
    }

    return moving;
}

void Monster::resetTurn() {
    endedTurn = false;
}

void Monster::endTurn() {
    endedTurn = true;
}

bool Monster::hasEndedTurn() {
    return endedTurn;
}

Attack Monster::getNextAttack() {
    Attack attack = attacks[currentAttack];

    currentAttack++;
    if (currentAttack >= attacks.size()) {
        currentAttack = 0;
    }

    return attack;
}

AttackFeedback Monster::receiveAttack(AttackResult result) {
    AttackFeedback feedback;
    feedback.result = result;

    std::string defPattern = defenses.getPattern();

    if (currentWeakness < defPattern.size()) {
        if (result.attackType == defPattern[currentWeakness]) {
            feedback.wasCritical = true;
            feedback.totalDamage = result.damage + result.damageBonus;

            currentWeakness++;
            health -= (result.damage + result.damageBonus);
            if (currentWeakness >= defPattern.size()) {
                feedback.stunnedEnemy = true;

                getNextAttack();
                stunCounter = 1;
            }
        } else {
            feedback.wasCritical = false;
            feedback.totalDamage = result.damage;

            health -= (result.damage);
            currentWeakness = 0;
        }
    } else {
        feedback.wasCritical = false;
        feedback.totalDamage = result.damage;

        health -= (result.damage);
    }

    if (health <= 0) {
        feedback.defeatedEnemy = true;

        health = 0;
    }

    return feedback;
}

void Monster::tickStunCounter() {
    if (stunCounter > 0) {
        stunCounter--;
        if (stunCounter == 0) {
            currentWeakness = 0;
        }
    }
}

bool Monster::isStunned() {
    return (stunCounter > 0);
}

void Monster::attachAnimation(Animation *animation) {
    animations.push_back(animation);
}

std::list<Particle *> Monster::getParticles() {
    std::list<Particle *> particles;

    std::list<Animation *>::iterator it;

    for (it = animations.begin(); it != animations.end(); it++) {
        Animation *animation = (*it);

        std::list<Particle *> newParticles = animation->getParticles();
        particles.insert(particles.begin(),
                         newParticles.begin(),
                         newParticles.end());
    }

    return particles;
}

void Monster::shake(double duration) {
    shakeCounter = 0.0;
    shakeDuration = duration;
}

void Monster::die() {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    audioSystem->playSound("Death", 0);

    iplWorldY.set(0.0, -HALF_TILE, 1000.0);
    iplOpacity.set(1.0, 0.0, 1000.0);
}

bool Monster::isAlive() {
    bool alive = true;

    bool finishedAnimations = true;
    std::list<Animation *>::iterator it = animations.begin();
    while (it != animations.end()) {
        Animation *animation = (*it);
        if (!animation->hasFinished()) {
            finishedAnimations = false;
        }

        it++;
    }

    if (health <= 0 && opacity == 0.0 && finishedAnimations) {
        alive = false;
    }

    return alive;
}

AttackFeedback Monster::attack(Player *player) {
    AttackFeedback feedback;

    Attack attack = getNextAttack();
    AttackResult result = attack.getAttackResult();

    feedback.result = result;
    feedback.totalDamage = result.damage;

    return feedback;
}
