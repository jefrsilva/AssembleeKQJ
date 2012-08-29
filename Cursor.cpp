#include "Cursor.h"
#include "Item.h"
#include "GlobalConstants.h"

#include "Engine.h"

Cursor::Cursor() {
    position = Vector();
    item = 0;
}

Cursor::~Cursor() {
    if (item) {
        delete item;
        item = 0;
    }
}

void Cursor::update(double dt) {

}

void Cursor::render(double edt) {
    double cursorType = 0.0;
    if (item) {
        cursorType = 1.0;
    }
    
    double pw = 1.0 / TEX_IMAGE_UI_WIDTH;
    double ph = 1.0 / TEX_IMAGE_UI_HEIGHT;

    double cursorWidth = TEX_CURSOR_WIDTH * pw;
    double cursorHeight = TEX_CURSOR_HEIGHT * ph;

    double hOffset = cursorType * (cursorWidth + 2.0 * pw) + pw;
    double vOffset = 1.0 - (29.0 * ph) - cursorHeight;

    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(hOffset + cursorWidth, vOffset);
    glVertex3f(position.x + CURSOR_SIZE, position.y - CURSOR_SIZE, 0.0f);

    glTexCoord2f(hOffset + cursorWidth, vOffset + cursorHeight);
    glVertex3f(position.x + CURSOR_SIZE, position.y, 0.0f);

    glTexCoord2f(hOffset, vOffset);
    glVertex3f(position.x, position.y - CURSOR_SIZE, 0.0f);

    glTexCoord2f(hOffset, vOffset + cursorHeight);
    glVertex3f(position.x, position.y, 0.0f);

    glEnd();

    if (item) {
        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        videoSystem->bindTexture("Items");
        
        double itemSize = 8.0 * INVENTORY_SLOT_SIZE / 10.0;

        double x =
            position.x + itemSize / 2.0 + CURSOR_SIZE / 2.0;
        double y =
            position.y - itemSize - CURSOR_SIZE / 2.0;

        item->renderOrtho(Vector(x, y), edt, false);
    }
}

void Cursor::setPosition(const Vector &position) {
    this->position = position;
}

Vector Cursor::getPosition() {
    return position;
}

Item *Cursor::getItem() {
    return item;
}

void Cursor::attachItem(Item *item) {
    if (item) {
        this->item = item;
    }
}

Item *Cursor::detachItem() {
    Item *detachedItem = 0;
    
    if (item) {
        detachedItem = item;
        item = 0;
    }
    
    return detachedItem;
}
