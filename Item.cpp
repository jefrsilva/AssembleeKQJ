#include "Item.h"
#include "Tooltip.h"
#include "Monster.h"
#include "Attack.h"
#include "TextRenderer.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>
#include <sstream>

Item::Item(std::string itemID) {
    this->id = itemID;

    this->type = type;
    this->name = name;
    this->texture = texture;
    this->tile = 0;
    this->locked = false;

    this->identified = false;

    this->toughness = 0;
    this->durability = 0;
    this->delay = 0;
    this->delayCounter = 0;
    this->weight = 0;
    this->description = "";

    tooltip = new Tooltip();
    tooltip->setOrigin(Vector());

    this->currentAttack = 0;
    this->currentDefense = 0;

    this->slotNumber = -1;

    this->textRenderer = new TextRenderer();
    
    this->consumed = false;
}

Item::Item(int type, std::string name, int texture) {
    this->type = type;
    this->name = name;
    this->texture = texture;
    this->tile = 0;
    this->locked = false;

    this->identified = false;

    this->toughness = 0;
    this->durability = 0;
    this->delay = 0;
    this->delayCounter = 0;
    this->weight = 0;
    this->description = "";

    tooltip = new Tooltip();
    tooltip->setOrigin(Vector());

    this->currentAttack = 0;
    this->currentDefense = 0;

    this->slotNumber = -1;

    this->textRenderer = new TextRenderer();
}

Item::~Item() {
    if (this->tooltip) {
        delete this->tooltip;
        this->tooltip = 0;
    }

    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }
}

void Item::update(double dt) {

}

void Item::render(double edt, bool selection) {
    if (selection) {
        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        unsigned int selectionID = videoSystem->getSelectionID();
        videoSystem->setSelectionObject(selectionID, SEL_OBJ_ITEM, this);

        int b = selectionID / (256 * 256);
        selectionID -= b * (256 * 256);

        int g = selectionID / 256;
        selectionID -= g * 256;

        int r = selectionID;

        glColor4f((double)r / 255.0,
                  (double)g / 255.0,
                  (double)b / 255.0, 1.0f);
    }

    double row = texture / 12;
    double col = texture % 12;

    double pw = 1.0 / TEX_IMAGE_ITEM_WIDTH;
    double ph = 1.0 / TEX_IMAGE_ITEM_HEIGHT;

    double itemWidth = 8.0 * pw;
    double itemHeight = 8.0 * ph;

    double hOffset = (col * (itemWidth + 2.0 * pw)) + pw;
    double vOffset = 1.0 - ((row + 1.0) * (itemHeight + 2.0 * ph)) + ph;
    double zOffset = TILE_SIZE / 64.0;

    if (!selection) {
        glDisable(GL_LIGHTING);

        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLE_STRIP);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(hOffset + itemWidth, vOffset);
        glVertex3f(ITEM_SIZE / 2.0,
                   0.0f,
                   -zOffset);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(hOffset + itemWidth, vOffset + itemHeight);
        glVertex3f(ITEM_SIZE / 2.0,
                   ITEM_SIZE,
                   -zOffset);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(hOffset, vOffset);
        glVertex3f(-ITEM_SIZE / 2.0,
                   0.0f,
                   -zOffset);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(hOffset, vOffset + itemHeight);
        glVertex3f(-ITEM_SIZE / 2.0,
                   ITEM_SIZE,
                   -zOffset);

        glEnd();

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

        glEnable(GL_LIGHTING);
    }

    glBegin(GL_TRIANGLE_STRIP);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset + itemWidth, vOffset);
    glVertex3f(ITEM_SIZE / 2.0, 0.0, zOffset);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset + itemWidth, vOffset + itemHeight);
    glVertex3f(ITEM_SIZE / 2.0, ITEM_SIZE, zOffset);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset, vOffset);
    glVertex3f(-ITEM_SIZE / 2.0, 0.0, zOffset);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(hOffset, vOffset + itemHeight);
    glVertex3f(-ITEM_SIZE / 2.0, ITEM_SIZE, zOffset);

    glEnd();
}

void Item::renderOrtho(Vector position, double edt, bool onBar) {
    double x = position.x;
    double y = position.y;

    double row = texture / 12;
    double col = texture % 12;

    double pw = 1.0 / TEX_IMAGE_ITEM_WIDTH;
    double ph = 1.0 / TEX_IMAGE_ITEM_HEIGHT;

    double itemWidth = 8.0 * pw;
    double itemHeight = 8.0 * ph;

    double hOffset = (col * (itemWidth + 2.0 * pw)) + pw;
    double vOffset = 1.0 - ((row + 1.0) * (itemHeight + 2.0 * ph)) + ph;

    double orthoItemSize = 8.0 * INVENTORY_SLOT_SIZE / 10.0;
    double borderSize = orthoItemSize / 10.0;

    double opacity = 1.0;
    if (onBar && locked) {
        opacity = 0.5;
    }

    if (delayCounter > 0) {
        glColor4f(0.75f, 0.0f, 0.0f, opacity);
    } else if (durability == 0 &&
               type != ITEM_TYPE_OTHER &&
               type != ITEM_TYPE_CONSUMABLE) {
        glColor4f(0.15f, 0.15f, 0.25f, opacity);
    } else {
        glColor4f(1.0f, 1.0f, 1.0f, opacity);
    }

    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(hOffset + itemWidth, vOffset);
    glVertex3f(x + orthoItemSize / 2.0, y + borderSize, 0.0f);

    glTexCoord2f(hOffset + itemWidth, vOffset + itemHeight);
    glVertex3f(x + orthoItemSize / 2.0, y + borderSize + orthoItemSize, 0.0f);

    glTexCoord2f(hOffset, vOffset);
    glVertex3f(x - orthoItemSize / 2.0, y + borderSize, 0.0f);

    glTexCoord2f(hOffset, vOffset + itemHeight);
    glVertex3f(x - orthoItemSize / 2.0, y + borderSize + orthoItemSize, 0.0f);

    glEnd();

    if (delayCounter > 0) {
        std::stringstream delayText;
        delayText << delayCounter;
        textRenderer->renderText(ALIGN_LEFT, position, delayText.str());
    }
}

Tooltip *Item::getTooltip() {
    std::vector<std::string> text;
    text.push_back(name);

    if (identified) {
        if (type == ITEM_TYPE_SWORD ||
                type == ITEM_TYPE_AXE ||
                type == ITEM_TYPE_SPEAR ||
                type == ITEM_TYPE_BOW) {
            text.push_back("");

            for (unsigned int i = 0; i < attacks.size(); i++) {
                std::stringstream attackPattern;
                if (i == 0) {
                    attackPattern << "Damage__ : " << attacks[i].getTooltipString();
                } else {
                    attackPattern << "____ : " << attacks[i].getTooltipString();
                }
                if (i == currentAttack) {
                    attackPattern << " |fe6|<|fff";
                }
                text.push_back(attackPattern.str());
            }

            text.push_back("");

            std::stringstream toughnessStr;
            toughnessStr << "Toughness_ : " << toughness;
            text.push_back(toughnessStr.str());

            std::stringstream durabilityStr;
            durabilityStr << "Durability_ : " << durability;
            text.push_back(durabilityStr.str());

            std::stringstream delayStr;
            delayStr << "Delay___ : " << delay;
            text.push_back(delayStr.str());
        } else if (type == ITEM_TYPE_SHIELD) {
            text.push_back("");

            for (unsigned int i = 0; i < defenses.size(); i++) {
                std::stringstream defensePattern;
                if (i == 0) {
                    defensePattern << "Reduction_ : " << defenses[i].getTooltipString();
                } else {
                    defensePattern << "____ : " << defenses[i].getTooltipString();
                }
                if (i == currentDefense) {
                    defensePattern << " |fe6|<|fff";
                }
                text.push_back(defensePattern.str());
            }
            
            text.push_back("");            

            std::stringstream durabilityStr;
            durabilityStr << "Durability_ : " << durability;
            text.push_back(durabilityStr.str());

            std::stringstream delayStr;
            delayStr << "Delay___ : " << delay;
            text.push_back(delayStr.str());
        } else if (type == ITEM_TYPE_CONSUMABLE ||
                   type == ITEM_TYPE_OTHER) {
            if (description.size() > 0) {
                text.push_back("");

                std::vector<std::string> textLines =
                    textRenderer->breakText(description, 25);
                for (unsigned int i = 0; i < textLines.size(); i++) {
                    text.push_back(textLines[i]);
                }
            }
        }
    }

    tooltip->setText(text);

    return tooltip;
}

std::string Item::getID() {
    return id;
}

void Item::setName(std::string name) {
    this->name = name;
}

void Item::setTexture(int texture) {
    this->texture = texture;
}

void Item::setType(int type) {
    this->type = type;
}

void Item::addAttack(const Attack &attack) {
    attacks.push_back(attack);
}

void Item::addDefense(const Defense &defense) {
    defenses.push_back(defense);
}

void Item::setToughness(int toughness) {
    this->toughness = toughness;
}

void Item::setDurability(int durability) {
    this->durability = durability;
}

int Item::getDurability() {
    return this->durability;
}

void Item::setDelay(int delay) {
    this->delay = delay;
}

void Item::setWeight(int weight) {
    this->weight = weight;
}

int Item::getWeight() {
    return weight;
}

void Item::setDescription(std::string description) {
    this->description = description;
}

int Item::getType() {
    return type;
}

void Item::setConsumed(bool consumed) {
    this->consumed = consumed;
}

bool Item::wasConsumed() {
    return consumed;
}

void Item::identify() {
    this->identified = true;
}

void Item::lock() {
    this->locked = true;
}

void Item::unlock() {
    this->locked = false;
}

void Item::setSlotNumber(int slotNumber) {
    this->slotNumber = slotNumber;
}

int Item::getSlotNumber() {
    return this->slotNumber;
}

void Item::setTile(Tile *tile) {
    this->tile = tile;
}

Tile *Item::getTile() {
    return this->tile;
}

Attack Item::getNextAttack() {
    Attack attack = attacks[currentAttack];

    currentAttack++;
    if (currentAttack >= attacks.size()) {
        currentAttack = 0;
    }

    return attack;
}

Defense Item::getNextDefense() {
    Defense defense = defenses[currentDefense];

    currentDefense++;
    if (currentDefense >= defenses.size()) {
        currentDefense = 0;
    }

    return defense;
}

void Item::enterDelay() {
    delayCounter = delay;
}

void Item::tickDelayCounter() {
    if (delayCounter > 0) {
        delayCounter--;
    }
}

void Item::resetDelayCounter() {
    delayCounter = 0;
}

bool Item::onDelay() {
    return (delayCounter > 0);
}

AttackFeedback Item::attack(Monster *monster) {
    AttackFeedback attackFeedback;

    Attack attack = getNextAttack();
    AttackResult result = attack.getAttackResult();

    if (result.attackType != 'x') {
        int monsterToughness = monster->getToughness();

        int durabilityReduction = 1;
        if (toughness < monsterToughness) {
            durabilityReduction += (monsterToughness - toughness);
        }
        durability -= durabilityReduction;
        if (durability < 0) {
            durability = 0;
        }
    }

    attackFeedback = monster->receiveAttack(result);
    attackFeedback.result = result;

    return attackFeedback;
}

DefenseResult Item::defend() {
    Defense defense = getNextDefense();
    DefenseResult defenseResult = defense.getDefenseResult();

    if (defenseResult.defenseType != 'x') {
        durability--;
    }

    return defenseResult;
}

void Item::consume() {
    if (type == ITEM_TYPE_CONSUMABLE) {
        Engine::ScriptingSystem *scriptingSystem =
            Engine::Core::getInstance()->getScriptingSystem();

        lua_State *luaState = scriptingSystem->getLuaState();

        lua_getglobal(luaState, id.c_str());
        lua_pushstring(luaState, "onConsume");
        lua_gettable(luaState, -2);
        tolua_pushusertype(luaState, (void *)this, "Item");
        lua_call(luaState, 1, 0);
        lua_pop(luaState, 1);
    }
}
