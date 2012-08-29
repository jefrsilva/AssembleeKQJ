#include "TurnStone.h"
#include "Tooltip.h"
#include "GlobalConstants.h"

#include "Engine.h"

TurnStone::TurnStone() {
    this->tooltip = new Tooltip();

    double stoneHeight = 1.0 / 8.0;
    double stoneWidth = 13.0 * stoneHeight / 16.0;

    this->position = Vector(0.66 - 0.2 * stoneWidth - stoneWidth / 2.0,
                            -0.50 + 0.1 * stoneHeight);

    tooltip->setOrigin(Vector(position.x,
                              position.y + stoneHeight));
    tooltip->setText("No enemies nearby");

    stoneAlpha[0] = 0.5;
    stoneAlpha[1] = 0.0;
    stoneAlpha[2] = 0.0;

    iplStoneAlpha[0].attach(&stoneAlpha[0]);
    iplStoneAlpha[1].attach(&stoneAlpha[1]);
    iplStoneAlpha[2].attach(&stoneAlpha[2]);
}

TurnStone::~TurnStone() {
    if (this->tooltip) {
        delete this->tooltip;
        this->tooltip = 0;
    }
}

void TurnStone::update(double dt) {
    for (int i = 0; i < 3; i++) {
        iplStoneAlpha[i].update(dt);
    }
}

void TurnStone::render(double edt, bool selection) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    if (!selection) {
        videoSystem->bindTexture("Interface");
    }

    glLoadIdentity();

    double pw = 1.0 / TEX_IMAGE_UI_WIDTH;
    double ph = 1.0 / TEX_IMAGE_UI_HEIGHT;

    double stoneTexWidth = 13.0 * pw;
    double stoneTexHeight = 16.0 * ph;

    double stoneHeight = 1.0 / 8.0;
    double stoneWidth = 13.0 * stoneHeight / 16.0;

    glTranslatef(position.x,
                 position.y,
                 0.0f);

    for (int i = 0; i < 3; i++) {
        if (!selection) {
            glColor4f(1.0f, 1.0f, 1.0f, iplStoneAlpha[i].getValue(edt));
        }

        double hOffset = (i * (stoneTexWidth + 2.0 * pw)) + pw;
        double vOffset = 1.0 - (44.0 * ph) - stoneTexHeight - ph;

        glBegin(GL_TRIANGLE_STRIP);

        glTexCoord2f(hOffset + stoneTexWidth, vOffset);
        glVertex3f(stoneWidth / 2.0, 0.0f, 0.0f);

        glTexCoord2f(hOffset + stoneTexWidth, vOffset + stoneTexHeight);
        glVertex3f(stoneWidth / 2.0, stoneHeight, 0.0f);

        glTexCoord2f(hOffset, vOffset);
        glVertex3f(-stoneWidth / 2.0, 0.0f, 0.0f);

        glTexCoord2f(hOffset, vOffset + stoneTexHeight);
        glVertex3f(-stoneWidth / 2.0, stoneHeight, 0.0f);

        glEnd();
    }

    if (!selection) {
        tooltip->render(edt);
    }
}

void TurnStone::setTooltipVisibility(bool visibility) {
    tooltip->setVisibility(visibility);
}

BoundingBox TurnStone::getBoundingBox() {
    double stoneHeight = 1.0 / 8.0;
    double stoneWidth = 13.0 * stoneHeight / 16.0;

    BoundingBox b = BoundingBox(position.x - stoneWidth / 2.0,
                                position.y,
                                stoneWidth, stoneHeight);

    return b;
}

void TurnStone::setTurn(int turn) {
    if (turn == TURN_FREE) {
        tooltip->setText("No enemies nearby");
        for (int i = 1; i < 3; i++) {
            iplStoneAlpha[i].set(stoneAlpha[i], 0.0, 250);
        }
    } else {
        if (turn == TURN_PLAYER) {
            tooltip->setText("Your turn");
        } else if (turn == TURN_ENEMY) {
            tooltip->setText("Enemy turn");
        }

        for (int i = 1; i < 3; i++) {
            if (i == turn) {
                iplStoneAlpha[i].set(stoneAlpha[i], 1.0, 250);
            } else {
                iplStoneAlpha[i].set(stoneAlpha[i], 0.0, 250);
            }
        }
    }
}

Vector TurnStone::getPosition() {
    return position;
}
