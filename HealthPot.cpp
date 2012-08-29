#include "HealthPot.h"
#include "Player.h"
#include "GlobalConstants.h"
#include "Tooltip.h"

#include "Engine.h"

#include <sstream>

HealthPot::HealthPot(Player *player) {
    this->player = player;

    this->tooltip = new Tooltip();

    double potHeight = 1.0 / 8.0;
    double potWidth = 13.0 * potHeight / 16.0;

    this->position = Vector(-0.66 + 0.2 * potWidth + potWidth / 2.0,
                            -0.50 + 0.1 * potHeight);

    tooltip->setOrigin(Vector(position.x,
                              position.y + potHeight));
}

HealthPot::~HealthPot() {
    if (this->tooltip) {
        delete this->tooltip;
        this->tooltip = 0;
    }
}

void HealthPot::update(double dt) {
    int health = player->getHealth();
    int maxHealth = player->getMaxHealth();

    std::stringstream text;
    text << "Health: " << (int)health << "/" << maxHealth;
    tooltip->setText(text.str());
}

void HealthPot::render(double edt, bool selection) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    if (!selection) {
        videoSystem->bindTexture("Interface");
    }

    glLoadIdentity();

    double pw = 1.0 / TEX_IMAGE_UI_WIDTH;
    double ph = 1.0 / TEX_IMAGE_UI_HEIGHT;

    double healthPotWidth = 13.0 * pw;
    double healthPotHeight = 16.0 * ph;

    double hOffset = pw;
    double vOffset = 1.0 - healthPotHeight - ph;

    double potHeight = 1.0 / 8.0;
    double potWidth = 13.0 * potHeight / 16.0;

    glTranslatef(position.x,
                 position.y,
                 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(hOffset + healthPotWidth, vOffset);
    glVertex3f(potWidth / 2.0, 0.0f, 0.0f);

    glTexCoord2f(hOffset + healthPotWidth, vOffset + healthPotHeight);
    glVertex3f(potWidth / 2.0, potHeight, 0.0f);

    glTexCoord2f(hOffset, vOffset);
    glVertex3f(-potWidth / 2.0, 0.0f, 0.0f);

    glTexCoord2f(hOffset, vOffset + healthPotHeight);
    glVertex3f(-potWidth / 2.0, potHeight, 0.0f);

    glEnd();

    if (!selection) {
        hOffset = 16 * pw;
        vOffset = 1.0 - healthPotHeight - ph;

        double health = player->getHealth();
        double maxHealth = player->getMaxHealth();

        double healthPct = (health / maxHealth) * 9.0;

        glBegin(GL_TRIANGLE_STRIP);

        glTexCoord2f(hOffset + healthPotWidth, vOffset + ph);
        glVertex3f(potWidth / 2.0, 1.0 * potHeight / 16.0, 0.0f);

        glTexCoord2f(hOffset + healthPotWidth, vOffset + (1.0 + healthPct) * ph);
        glVertex3f(potWidth / 2.0, (1.0 + healthPct) * potHeight / 16.0, 0.0f);

        glTexCoord2f(hOffset, vOffset + ph);
        glVertex3f(-potWidth / 2.0, 1.0 * potHeight / 16.0, 0.0f);

        glTexCoord2f(hOffset, vOffset + (1.0 + healthPct) * ph);
        glVertex3f(-potWidth / 2.0, (1.0 + healthPct) * potHeight / 16.0, 0.0f);

        glEnd();

        tooltip->render(edt);
    }
}

Vector HealthPot::getPosition() {
    return position;
}

void HealthPot::setTooltipVisibility(bool visibility) {
    tooltip->setVisibility(visibility);
}

BoundingBox HealthPot::getBoundingBox() {
    double potHeight = 1.0 / 8.0;
    double potWidth = 13.0 * potHeight / 16.0;

    BoundingBox b = BoundingBox(position.x - potWidth / 2.0,
                                position.y,
                                potWidth, potHeight);

    return b;
}
