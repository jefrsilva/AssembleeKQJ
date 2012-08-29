#include "Player.h"
#include "Item.h"
#include "GlobalConstants.h"

#include "Animations.h"
#include "Particle.h"

#include "Engine.h"

#include <iostream>

Player::Player() {
    this->maxHealth = 25;
    this->health = this->maxHealth;

    this->currentDefense = DefenseResult('x', 0);

    for (int i = 0; i < MAX_INVENTORY_SLOTS; i++) {
        inventory.push_back(0);
    }

    mapPosition = Vector();
    worldPosition = Vector();
    viewAngle = 0.0;

    iplWorldX.attach(&worldPosition.x);
    iplWorldZ.attach(&worldPosition.z);
    iplViewAngle.attach(&viewAngle);

    this->endedTurn = false;
}

Player::~Player() {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        delete inventory[i];
    }
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
}

void Player::addHealth(int amount) {
    health += amount;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

int Player::getHealth() {
    return this->health;
}

int Player::getMaxHealth() {
    return this->maxHealth;
}

std::vector<Item *> Player::getInventory() {
    return inventory;
}

void Player::addItem(Item *item, int slot) {
    item->identify();
    inventory[slot] = item;
    item->setSlotNumber(slot);
}

void Player::removeItem(Item *item) {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory[i]->setSlotNumber(-1);
            inventory[i] = 0;
        }
    }
}

int Player::getItemSlot(Item *item) {
    int slot = -1;

    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            slot = i;
        }
    }

    return slot;
}

void Player::lockItem(Item *item) {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory[i]->lock();
        }
    }
}

void Player::unlockItem(Item *item) {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == item) {
            inventory[i]->unlock();
        }
    }
}

void Player::update(double dt) {
    iplWorldX.update(dt);
    iplWorldZ.update(dt);
    iplViewAngle.update(dt);

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

void Player::renderOrtho() {
    glRotatef(-viewAngle, 0.0, 0.0, 1.0);
    
    int texture = 8;
    
    double row = texture / 12;
    double col = texture % 12;

    double pw = 1.0 / TEX_IMAGE_ITEM_WIDTH;
    double ph = 1.0 / TEX_IMAGE_ITEM_HEIGHT;

    double tileWidth = 8.0 * pw;
    double tileHeight = 8.0 * ph;

    double hOffset = (col * (tileWidth + 2.0 * pw)) + pw;
    double vOffset = 1.0 - ((row + 1.0) * tileHeight + 2.0 * ph) + ph;
        
    double tileSize = 1.0 / 48.0;
    
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(hOffset + tileWidth, vOffset);
    glVertex3f(tileSize / 2.0, -tileSize / 2.0, 0.0f);
    
    glTexCoord2f(hOffset + tileWidth, vOffset + tileHeight);    
    glVertex3f(tileSize / 2.0, tileSize / 2.0, 0.0f);
    
    glTexCoord2f(hOffset, vOffset);    
    glVertex3f(-tileSize / 2.0, -tileSize / 2.0, 0.0f);
    
    glTexCoord2f(hOffset, vOffset + tileHeight);    
    glVertex3f(-tileSize / 2.0, tileSize / 2.0, 0.0f);
    glEnd();
    
    glRotatef(viewAngle, 0.0, 0.0, 1.0);    
}

Vector Player::getWorldPosition() {
    return worldPosition;
}

Vector Player::getWorldPosition(double edt) {
    Vector shaking = Vector();
    if (shakeCounter < shakeDuration) {
        shaking = Vector(sin(shakeCounter * SHAKE_SPEED) * (2.0 / TILE_SIZE),
                         0.0, 0.0);
    }

    double xOffset =
        shaking.x * std::cos((iplViewAngle.getValue(edt) / 180.0) * M_PI) -
        shaking.z * std::sin((iplViewAngle.getValue(edt) / 180.0) * M_PI);

    double zOffset =
        shaking.x * std::sin((iplViewAngle.getValue(edt) / 180.0) * M_PI) +
        shaking.z * std::cos((iplViewAngle.getValue(edt) / 180.0) * M_PI);

    Vector position = Vector(iplWorldX.getValue(edt) + xOffset,
                             0.0,
                             iplWorldZ.getValue(edt) + zOffset);

    return position;
}

void Player::setMapPosition(const Vector &position, double viewAngle) {
    mapPosition = position;
    worldPosition = Vector(position.x * TILE_SIZE,
                           0.0,
                           position.y * TILE_SIZE);
    iplWorldX.attach(&worldPosition.x);
    iplWorldZ.attach(&worldPosition.z);

    this->viewAngle = viewAngle;
    iplViewAngle.attach(&this->viewAngle);
}

Vector Player::getMapPosition() {
    return mapPosition;
}

double Player::getViewAngle() {
    return viewAngle;
}

double Player::getViewAngle(double edt) {
    return iplViewAngle.getValue(edt);
}

void Player::setDefense(DefenseResult defenseResult) {
    this->currentDefense = defenseResult;
}

DefenseResult Player::getDefense() {
    return currentDefense;
}

void Player::setMapDestination(const Vector &destination) {
    mapPosition = destination;
}

void Player::setWorldDestination(const Vector &destination) {
    iplWorldX.set(worldPosition.x,
                  destination.x,
                  WALK_SPEED);

    iplWorldZ.set(worldPosition.z,
                  destination.z,
                  WALK_SPEED);
}

void Player::setViewDestination(double angle) {
    iplViewAngle.set(viewAngle,
                     angle,
                     WALK_SPEED);
}

bool Player::isMoving() {
    bool moving = false;

    if (!iplWorldX.finished() ||
            !iplWorldZ.finished() ||
            !iplViewAngle.finished()) {
        moving = true;
    }

    return moving;
}

void Player::tickInventoryDelay() {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i]) {
            inventory[i]->tickDelayCounter();
        }
    }
}

void Player::resetInventoryDelay() {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i]) {
            inventory[i]->resetDelayCounter();
        }
    }
}

void Player::attachAnimation(Animation *animation) {
    animations.push_back(animation);
}

std::list<Particle *> Player::getParticles() {
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

void Player::shake(double duration) {
    shakeCounter = 0.0;
    shakeDuration = duration;
}

DefenseFeedback Player::takeDamage(AttackFeedback attackFeedback) {
    DefenseFeedback defenseFeedback;
    
    if (currentDefense.defenseType == 'x' ||
            currentDefense.defenseType != attackFeedback.result.attackType) {
        health -= attackFeedback.totalDamage;
        
        defenseFeedback.result = currentDefense;
        defenseFeedback.totalDamage = attackFeedback.totalDamage;
    } else if (currentDefense.defenseType == attackFeedback.result.attackType) {
        if (currentDefense.absorption >= attackFeedback.totalDamage) {
            currentDefense.absorption -= attackFeedback.totalDamage;
            if (currentDefense.absorption == 0) {
                currentDefense.defenseType = 'x';
            }
            
            defenseFeedback.result = currentDefense;
            defenseFeedback.totalDamage = 0;
        } else {
            attackFeedback.totalDamage -= currentDefense.absorption;
            currentDefense.absorption = 0;
            currentDefense.defenseType = 'x';
            
            health -= attackFeedback.totalDamage;
            
            defenseFeedback.result = currentDefense;
            defenseFeedback.totalDamage = attackFeedback.totalDamage;
        }
    }

    if (health < 0) {
        health = 0;
    }
    
    return defenseFeedback;
}

void Player::setFactionStance(std::string faction, int stance) {
    factions[faction] = stance;
}

int Player::getFactionStance(std::string faction) {
    return factions[faction];
}

void Player::endTurn() {
    endedTurn = true;
}

void Player::resetTurn() {
    currentDefense.defenseType = 'x';
    currentDefense.absorption = 0;
    
    endedTurn = false;
}

bool Player::hasEndedTurn() {
    return endedTurn;
}

bool Player::hasItem(std::string itemID) {
    bool hasItem = false;
    
    for (unsigned int i = 0; i < inventory.size(); i++) {
        Item *item = inventory[i];
        if (item) {
            if (item->getID() == itemID) {
                hasItem = true;
            }
        }
    }
    
    return hasItem;
}
