#include "InventoryBar.h"
#include "BoundingBox.h"
#include "Item.h"
#include "Player.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>

InventoryBar::InventoryBar(Player *player) {
    this->player = player;
    this->cursorPosition = Vector();

    double jump = 12.0 * INVENTORY_SLOT_SIZE / 10.0;
    double totalWidth =
        jump * MAX_INVENTORY_SLOTS - (2.0 * INVENTORY_SLOT_SIZE / 10.0);

    double initX = -totalWidth / 2.0 + (INVENTORY_SLOT_SIZE / 2.0);
    double initY = -0.5f + INVENTORY_SLOT_SIZE / 2.0;

    for (int i = 0; i < MAX_INVENTORY_SLOTS; i++) {
        InventorySlot *slot =
            new InventorySlot(i, Vector(initX + i * jump, initY));

        slots.push_back(slot);
    }

    this->showTooltips = true;
}

InventoryBar::~InventoryBar() {
    for (unsigned int i = 0; i < slots.size(); i++) {
        delete slots[i];
    }
}

void InventoryBar::update(double dt) {
    double cursorX = cursorPosition.x;
    double cursorY = cursorPosition.y;

    for (unsigned int i = 0; i < slots.size(); i++) {
        if (slots[i]->getBoundingBox().contains(cursorX, cursorY)) {
            std::vector<Item *> items = player->getInventory();
            if (items[i]) {
                slots[i]->setTooltip(items[i]->getTooltip());
            } else {
                slots[i]->setTooltip(0);
            }
            if (showTooltips) {
                slots[i]->setTooltipVisibility(true);
            } else {
                slots[i]->setTooltipVisibility(false);
            }
        } else {
            slots[i]->setTooltipVisibility(false);
        }
    }
}

void InventoryBar::render(double edt, bool selection) {
    glLoadIdentity();

    glDisable(GL_TEXTURE_2D);
    for (unsigned int i = 0; i < slots.size(); i++) {
        slots[i]->render(edt, selection);
    }

    if (!selection) {
        glEnable(GL_TEXTURE_2D);
        for (unsigned int i = 0; i < slots.size(); i++) {
            slots[i]->renderShortcut();
        }

        std::vector<Item *> items = player->getInventory();

        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        for (unsigned int i = 0; i < items.size(); i++) {
            if (items[i]) {
                videoSystem->bindTexture("Items");

                Vector slotPosition = slots[i]->getPosition();

                items[i]->renderOrtho(slotPosition, edt, true);
            }
        }
    }
}

void InventoryBar::setCursorPosition(const Vector &position) {
    this->cursorPosition = position;
}

bool InventoryBar::attachItem(Item *item, const Vector &position) {
    bool foundItem = false;

    double x = position.x;
    double y = position.y;

    for (unsigned int i = 0; i < slots.size() && !foundItem; i++) {
        if (slots[i]->getBoundingBox().contains(x, y)) {
            int prevSlot = item->getSlotNumber();
            if (prevSlot != -1) {
                player->removeItem(item);
            }

            player->addItem(item, i);
            item->setSlotNumber(i);
            item->unlock();
            foundItem = true;
        }
    }

    return foundItem;
}

Item *InventoryBar::detachItem(const Vector &position) {
    Item *item = 0;

    double x = position.x;
    double y = position.y;

    for (unsigned int i = 0; i < slots.size(); i++) {
        if (slots[i]->getBoundingBox().contains(x, y)) {
            std::vector<Item *> items = player->getInventory();
            if (items[i]) {
                item = items[i];
                player->lockItem(items[i]);
            }
        }
    }

    return item;
}

Item *InventoryBar::getItem(const Vector &position) {
    Item *item = 0;

    double x = position.x;
    double y = position.y;

    for (unsigned int i = 0; i < slots.size(); i++) {
        if (slots[i]->getBoundingBox().contains(x, y)) {
            std::vector<Item *> items = player->getInventory();
            if (items[i]) {
                item = items[i];
            }
        }
    }

    return item;
}

int InventoryBar::getSlotNumber(const Vector &position) {
    int slot = -1;

    double x = position.x;
    double y = position.y;

    for (unsigned int i = 0; i < slots.size(); i++) {
        if (slots[i]->getBoundingBox().contains(x, y)) {
            slot = i;
            break;
        }
    }

    return slot;
}

Vector InventoryBar::getSlotPosition(int slot) {
    Vector position = slots[slot]->getPosition();

    return position;
}

void InventoryBar::setTooltipVisibility(bool visibility) {
    showTooltips = visibility;
}
