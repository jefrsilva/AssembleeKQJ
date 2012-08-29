#include "UserInterface.h"
#include "TextRenderer.h"
#include "HealthPot.h"
#include "TurnStone.h"
#include "InventoryBar.h"
#include "Tooltip.h"
#include "TextWindow.h"
#include "Cursor.h"
#include "Player.h"
#include "Map.h"
#include "Tile.h"
#include "Item.h"
#include "GlobalConstants.h"

#include "Animations.h"
#include "Particle.h"

#include "Engine.h"

#include <sstream>

UserInterface::UserInterface(Player *player) {
    this->player = player;
    this->map = 0;
    this->mapState = 0;
    this->showTutorial = true;

    this->textRenderer = new TextRenderer();
    this->healthPot = new HealthPot(player);
    this->turnStone = new TurnStone();
    this->inventoryBar = new InventoryBar(player);
    this->cursor = new Cursor();

    this->worldTooltip = 0;
    this->textWindow = 0;
    this->tutorialWindow = 0;

    this->showTooltips = true;
    this->showWorldTooltips = true;

    this->fadeColor = Vector(0.0, 0.0, 0.0);
    this->fadeOpacity = 1.0;
    this->iplFadeOpacity.attach(&this->fadeOpacity);
}

UserInterface::~UserInterface() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }

    if (this->healthPot) {
        delete this->healthPot;
        this->healthPot = 0;
    }

    if (this->turnStone) {
        delete this->turnStone;
        this->turnStone = 0;
    }

    if (this->inventoryBar) {
        delete this->inventoryBar;
        this->inventoryBar = 0;
    }

    if (this->cursor) {
        delete this->cursor;
        this->cursor = 0;
    }

    if (this->textWindow) {
        delete this->textWindow;
        this->textWindow = 0;
    }
}

void UserInterface::update(double dt) {
    iplFadeOpacity.update(dt);

    healthPot->update(dt);
    turnStone->update(dt);

    Vector pos = cursor->getPosition();
    if (healthPot->getBoundingBox().contains(pos.x, pos.y)) {
        healthPot->setTooltipVisibility(showTooltips);
    } else {
        healthPot->setTooltipVisibility(false);
    }

    if (turnStone->getBoundingBox().contains(pos.x, pos.y)) {
        turnStone->setTooltipVisibility(true);
    } else {
        turnStone->setTooltipVisibility(false);
    }

    inventoryBar->setTooltipVisibility(showTooltips);
    inventoryBar->update(dt);

    std::list<Animation *>::iterator it = animations.begin();
    while (it != animations.end()) {
        Animation *animation = (*it);

        if (animation->hasFinished()) {
            it = animations.erase(it);
        } else {
            it++;
        }
    }

    if (textWindow) {
        textWindow->update(dt);
    }

    if (tutorialWindow && showTutorial) {
        tutorialWindow->update(dt);
    }

    cursor->update(dt);
}

void UserInterface::render(double edt, bool selection) {
    setupOrthoView();

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    if (!selection) {
        videoSystem->bindTexture("Interface");
    }

    if (!selection) {
        renderGradients();
    }

    healthPot->render(edt, selection);
    if (!selection) {
        renderDefense();
    }
    
    turnStone->render(edt, selection);
    inventoryBar->render(edt, selection);

    if (!selection) {
        std::list<Animation *>::iterator it;
        for (it = animations.begin(); it != animations.end(); it++) {
            Animation *animation = (*it);

            if (!animation->hasFinished()) {
                std::list<Particle *> particles = animation->getParticles();

                std::list<Particle *>::iterator itP;
                for (itP = particles.begin(); itP != particles.end(); itP++) {
                    Particle *particle = (*itP);

                    if (particle->isAlive()) {
                        particle->render(edt);
                    }

                }
            }

            if (animation->isBlocking()) {
                // break;
            }
        }
    }

    if (!selection) {
        if (worldTooltip && showWorldTooltips) {
            Vector pos = cursor->getPosition();
            worldTooltip->setVisibility(true);
            worldTooltip->setOrigin(pos);
            worldTooltip->render(edt);
        }

        if (map) {
            double fontSize = 1.0 / 48.0;
            textRenderer->setFontSize(fontSize);
            textRenderer->renderText(ALIGN_CENTER,
                                     Vector(0.0, 0.5 - 2.0 * fontSize),
                                     map->getName());
        }

        if (textWindow) {
            textWindow->render(edt);
        }

        if (tutorialWindow && showTutorial) {
            tutorialWindow->render(edt);
        }

        glDisable(GL_TEXTURE_2D);
        if (map && mapState != MAP_STATE_HIDDEN) {
            videoSystem->bindTexture("Map");

            map->renderOrtho(mapState);
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        }
        glEnable(GL_TEXTURE_2D);

        videoSystem->bindTexture("Interface");
        cursor->render(edt);

        glDisable(GL_TEXTURE_2D);

        glColor4f(fadeColor.x, fadeColor.y, fadeColor.z,
                  iplFadeOpacity.getValue(edt));

        glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(1.0f, -0.5f, 0.0f);
        glVertex3f(1.0f, 0.5f, 0.0f);
        glVertex3f(-1.0f, -0.5f, 0.0f);
        glVertex3f(-1.0f, 0.5f, 0.0f);
        glEnd();

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

        glEnable(GL_TEXTURE_2D);
    }

    restoreView();
}

void UserInterface::renderDefense() {
    Player *player = map->getPlayer();
    DefenseResult defenseResult = player->getDefense();
    unsigned char defenseType = defenseResult.defenseType;

    if (defenseResult.absorption > 0) {

        Vector color = Vector();
        if (defenseType == 'W') {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 1.0;
        } else if (defenseType == 'R') {
            color.x = 1.0;
            color.y = 0.0;
            color.z = 0.0;
        } else if (defenseType == 'G') {
            color.x = 0.0;
            color.y = 1.0;
            color.z = 0.0;
        } else if (defenseType == 'B') {
            color.x = 0.0;
            color.y = 0.0;
            color.z = 1.0;
        } else if (defenseType == 'Y') {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 0.0;
        }

        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        videoSystem->bindTexture("Particles");

        double size = 1.0 / 24.0;
        double opacity = 0.85;
        int texture = 12;

        double pw = 1.0 / TEX_IMAGE_PARTICLE_WIDTH;
        double ph = 1.0 / TEX_IMAGE_PARTICLE_HEIGHT;

        double particleWidth = 8.0 * pw;
        double particleHeight = 8.0 * ph;

        int row = texture / 12;
        int col = texture % 12;

        double hOffset = col * (particleWidth + 2.0 * pw) + pw;
        double vOffset = 1.0 - ((row + 1) * (particleHeight + 2.0 * ph)) + ph;

        glColor4f(color.x, color.y, color.z, opacity);

        Vector pos = getHealthPotPosition().translate(Vector(0.0, 0.0375));

        glPushMatrix();
        glTranslatef(0.0, 0.045, 0.0f);

        glBegin(GL_TRIANGLE_STRIP);

        glTexCoord2f(hOffset + particleWidth, vOffset);
        glVertex3f( 0.5 * size, -0.5 * size, 0.0f);

        glTexCoord2f(hOffset + particleWidth, vOffset + particleHeight);
        glVertex3f( 0.5 * size,  0.5 * size, 0.0f);

        glTexCoord2f(hOffset, vOffset);
        glVertex3f(-0.5 * size, -0.5 * size, 0.0f);

        glTexCoord2f(hOffset, vOffset + particleHeight);
        glVertex3f(-0.5 * size,  0.5 * size, 0.0f);

        glEnd();

        glPopMatrix();
        
        std::stringstream absorptionText;
        absorptionText << defenseResult.absorption;
        textRenderer->renderText(ALIGN_CENTER, pos, absorptionText.str());

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    }
}

void UserInterface::setMap(Map *map) {
    this->map = map;
}

void UserInterface::setShowMap(bool showMap) {
    if (showMap) {
        mapState = 1;
    } else {
        mapState = 0;
    }
}

void UserInterface::toggleMap() {
    mapState = (mapState + 1) % 3;
}

void UserInterface::toggleTutorial() {
    showTutorial = !showTutorial;
}

void UserInterface::setupOrthoView() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double width = videoSystem->getWindowWidth();
    double height = videoSystem->getWindowHeight();

    double orthoHeight = 1.0;
    double orthoWidth = (width / height) * orthoHeight;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-orthoWidth / 2.0, orthoWidth / 2.0,
            -orthoHeight / 2.0, orthoHeight / 2.0, 0.5f, -0.5f);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void UserInterface::restoreView() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void UserInterface::renderGradients() {
    glLoadIdentity();
    glDisable(GL_TEXTURE_2D);

    // Render bottom gradient
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f( 1.0f, -0.5f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, -0.5f + 3.0 * INVENTORY_SLOT_SIZE / 2.0, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f(-1.0f, -0.5f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -0.5f + 3.0 * INVENTORY_SLOT_SIZE / 2.0, 0.0f);
    glEnd();

    // Render top gradient
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, 0.5f - 3.0 * INVENTORY_SLOT_SIZE / 2.0, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f( 1.0f, 0.5f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 0.5f - 3.0 * INVENTORY_SLOT_SIZE / 2.0, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glEnd();

    glEnable(GL_TEXTURE_2D);
}

void UserInterface::setCursorPosition(const Vector &position) {
    cursor->setPosition(position);
    this->inventoryBar->setCursorPosition(position);
}

Vector UserInterface::getCursorPosition() {
    return cursor->getPosition();
}

Item *UserInterface::getCursorItem() {
    Item *item = cursor->getItem();

    return item;
}

Vector UserInterface::getHealthPotPosition() {
    Vector position = healthPot->getPosition();

    return position;
}

Vector UserInterface::getTurnStonePosition() {
    Vector position = turnStone->getPosition();

    return position;
}

void UserInterface::detachCursorItem() {
    Item *item = cursor->detachItem();
    if (item) {
        item->unlock();
    }
}

InventoryBar *UserInterface::getInventoryBar() {
    return inventoryBar;
}

Vector UserInterface::getSlotPosition(int slot) {
    Vector position = inventoryBar->getSlotPosition(slot);

    return position;
}

void UserInterface::setWorldTooltip(Tooltip *tooltip) {
    worldTooltip = tooltip;
}

void UserInterface::setTextWindow(TextWindow *textWindow) {
    if (this->worldTooltip) {
        this->worldTooltip = 0;
    }

    if (this->textWindow) {
        delete this->textWindow;
    }

    this->textWindow = textWindow;
}

TextWindow *UserInterface::getTextWindow() {
    return textWindow;
}

void UserInterface::setTutorialWindow(TextWindow *tutorialWindow) {
    if (this->tutorialWindow) {
        delete this->tutorialWindow;
    }

    this->tutorialWindow = tutorialWindow;
}

TextWindow *UserInterface::getTutorialWindow() {
    return tutorialWindow;
}

void UserInterface::clearTutorialWindow() {
    if (this->tutorialWindow) {
        delete this->tutorialWindow;
        this->tutorialWindow = 0;
    }
}

void UserInterface::handleMouseClick(Item *item, unsigned int button) {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    if (button == MOUSE_BUTTON_LEFT) {
        Item *cursorItem = cursor->detachItem();
        if (cursorItem) {
            // Swapping with the item on the ground
            Tile *tile = item->getTile();

            Vector itemPos = tile->getMapPosition();
            Vector playerPos = player->getMapPosition();

            double distance = Vector(itemPos, playerPos).length();

            if (distance <= 1.0) {
                audioSystem->playSound("Select", 0);

                item->identify();
                tile->removeItem(item);

                int prevSlot = cursorItem->getSlotNumber();
                if (prevSlot != -1) {
                    player->unlockItem(cursorItem);
                    player->removeItem(cursorItem);
                }

                tile->addItem(cursorItem);
                cursor->attachItem(item);
            } else {
                cursor->attachItem(cursorItem);
            }
        } else {
            // Getting an item from the ground
            Tile *tile = item->getTile();

            Vector itemPos = tile->getMapPosition();
            Vector playerPos = player->getMapPosition();

            double distance = Vector(itemPos, playerPos).length();

            if (distance <= 1.0) {
                audioSystem->playSound("Select", 0);

                item->identify();
                tile->removeItem(item);
                cursor->attachItem(item);
            }
        }
    }
}

void UserInterface::handleMouseClick(Tile *tile, unsigned int button) {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    if (button == MOUSE_BUTTON_LEFT) {
        Item *cursorItem = cursor->getItem();
        if (cursorItem) {
            // Dropping item
            audioSystem->playSound("Select", 0);
            int slot = cursorItem->getSlotNumber();
            if (slot != -1) {
                cursorItem->unlock();
                player->removeItem(cursorItem);
            }
            cursor->detachItem();
            tile->addItem(cursorItem);
        }
    }
}

bool UserInterface::handleMouseClick(const Vector &position,
                                     unsigned int button) {
    Engine::AudioSystem *audioSystem =
        Engine::Core::getInstance()->getAudioSystem();

    bool clickHandled = false;

    if (button == MOUSE_BUTTON_LEFT) {

        if (textWindow) {

            if (!textWindow->hasFinished()) {
                textWindow->skip();
            } else {
                delete textWindow;
                textWindow = 0;
            }

        } else {

            Item *cursorItem = cursor->getItem();
            if (cursorItem) {
                Item *item = inventoryBar->detachItem(position);
                if (item) {
                    // Swapping with an item on a slot
                    cursor->detachItem();

                    int prevSlot = player->getItemSlot(cursorItem);
                    int newSlot = inventoryBar->getSlotNumber(position);
                    if (prevSlot != newSlot) {
                        // Placing on a different slot
                        cursorItem->unlock();
                        inventoryBar->attachItem(cursorItem, position);

                        if (prevSlot != -1) {
                            player->addItem(item, prevSlot);
                            item->lock();
                        }

                        cursor->attachItem(item);
                        clickHandled = true;
                    } else {
                        // Placing item back on the same slot
                        item->unlock();
                        clickHandled = true;
                    }
                } else {
                    // Inserting item on an empty slot
                    if (inventoryBar->attachItem(cursorItem, position)) {
                        cursor->detachItem();
                        clickHandled = true;
                    }
                }
            } else {
                // Getting item from the inventory bar
                Item *item = inventoryBar->detachItem(position);
                if (item) {
                    cursor->attachItem(item);
                    clickHandled = true;
                }
            }

            if (clickHandled) {
                audioSystem->playSound("Select", 0);
            }

        }
    }

    return clickHandled;
}

void UserInterface::setTurn(int turn) {
    turnStone->setTurn(turn);
}

void UserInterface::attachAnimation(Animation *animation) {
    animations.push_back(animation);
}

void UserInterface::setTooltipVisibility(bool visibility) {
    showTooltips = visibility;
}

void UserInterface::setWorldTooltipVisibility(bool visibility) {
    showWorldTooltips = visibility;
}

void UserInterface::setFadeColor(const Vector &color) {
    this->fadeColor = color;
}

void UserInterface::fadeIn(double duration) {
    iplFadeOpacity.set(1.0, 0.0, duration);
}

void UserInterface::fadeOut(double duration) {
    iplFadeOpacity.set(0.0, 1.0, duration);
}

bool UserInterface::finishedFading() {
    return iplFadeOpacity.finished();
}
