#include "InventorySlot.h"
#include "TextRenderer.h"
#include "Tooltip.h"
#include "Item.h"
#include "BoundingBox.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <sstream>

InventorySlot::InventorySlot(int index, const Vector &position) {
    this->textRenderer = new TextRenderer();

    this->index = index;
    this->position = position;

    this->tooltip = new Tooltip();
    this->tooltip->setOrigin(Vector(position.x,
                                    position.y + INVENTORY_SLOT_SIZE));
    this->tooltip->setText("Empty");
}

InventorySlot::~InventorySlot() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }

    if (this->tooltip) {
        delete this->tooltip;
        this->tooltip = 0;
    }
}

void InventorySlot::update(double dt) {
    tooltip->update(dt);
}

void InventorySlot::render(double edt, bool selection) {
    double x = position.x;
    double y = position.y;

    glDisable(GL_TEXTURE_2D);
    
    if (!selection) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
    } else {
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    }
    
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(x + INVENTORY_SLOT_SIZE / 2.0, y, 0.0f);
    glVertex3f(x + INVENTORY_SLOT_SIZE / 2.0, y + INVENTORY_SLOT_SIZE, 0.0f);
    glVertex3f(x - INVENTORY_SLOT_SIZE / 2.0, y, 0.0f);
    glVertex3f(x - INVENTORY_SLOT_SIZE / 2.0, y + INVENTORY_SLOT_SIZE, 0.0f);
    glEnd();
    
    if (!selection) {
        glEnable(GL_TEXTURE_2D);        
        tooltip->render(edt);
    }
}

void InventorySlot::renderShortcut() {
    double fontSize = 1.0 / 96.0;
    textRenderer->setFontSize(fontSize);

    double x = position.x;
    double y = position.y;

    if (index < 10) {
        std::stringstream shortcut;

        shortcut << (index + 1) % 10;
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(x,
                                        y - 1.2 * fontSize),
                                 shortcut.str());

    } else {
        std::stringstream shortcut;

        shortcut << "F" << (index - 9);
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(x,
                                        y - 1.2 * fontSize),
                                 shortcut.str());
    }
}

BoundingBox InventorySlot::getBoundingBox() {
    double x = position.x;
    double y = position.y;

    BoundingBox box = BoundingBox(x - INVENTORY_SLOT_SIZE / 2.0,
                                  y,
                                  INVENTORY_SLOT_SIZE,
                                  INVENTORY_SLOT_SIZE);

    return box;
}

void InventorySlot::setTooltipVisibility(bool visibility) {
    tooltip->setVisibility(visibility);
}

Vector InventorySlot::getPosition() {
    return position;
}

void InventorySlot::setTooltip(Tooltip *tooltip) {
    if (tooltip) {
        this->tooltip->setText(tooltip->getText());
    } else {
        this->tooltip->setText("Empty");
    }
}
