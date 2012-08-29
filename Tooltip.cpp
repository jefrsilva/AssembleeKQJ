#include "Tooltip.h"
#include "TextRenderer.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>

Tooltip::Tooltip() {
    this->visible = false;
    this->position = Vector();

    this->textRenderer = new TextRenderer();
}

Tooltip::~Tooltip() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }
}

void Tooltip::update(double dt) {

}

void Tooltip::render(double edt) {
    if (visible) {
        double x = position.x;
        double y = position.y;

        Engine::VideoSystem *videoSystem =
            Engine::Core::getInstance()->getVideoSystem();

        double winWidth = videoSystem->getWindowWidth();
        double winHeight = videoSystem->getWindowHeight();

        double orthoHeight = 1.0;
        double orthoWidth = (winWidth / winHeight) * orthoHeight;

        double leftBorder = -orthoWidth / 2.0;
        double rightBorder = orthoWidth / 2.0;

        double topBorder = orthoHeight / 2.0;
        // double bottomBorder = -orthoHeight / 2.0;

        double width =
            2.0 * TOOLTIP_BORDER + textRenderer->getTextWidth(text);
        double height =
            2.0 * TOOLTIP_BORDER + textRenderer->getTextHeight(text);

        double tipBottom = y + 2.0 * TOOLTIP_BORDER;
        double tipTop = tipBottom + height;

        double tipLeft = x - width / 2.0;
        double tipRight = x + width / 2.0;

        double tooltipBaseLeft = x - TOOLTIP_BORDER / 2.0;
        double tooltipBaseRight = x + TOOLTIP_BORDER / 2.0;

        bool invert = false;
        if (tipTop > topBorder - 3.0 * TOOLTIP_BORDER) {
            invert = true;
        }

        if (invert) {
            tipTop = y - 2.0 * TOOLTIP_BORDER;
            tipBottom = tipTop - height;
        }

        if (tipLeft < leftBorder + TOOLTIP_BORDER) {
            double offset = leftBorder + TOOLTIP_BORDER - tipLeft;
            tipLeft += offset;
            tipRight += offset;
        }

        if (tipRight > rightBorder - TOOLTIP_BORDER) {
            double offset = tipRight - rightBorder + TOOLTIP_BORDER;
            tipLeft -= offset;
            tipRight -= offset;
        }

        if (tooltipBaseLeft < tipLeft + TOOLTIP_BORDER) {
            tooltipBaseLeft = tipLeft + TOOLTIP_BORDER;
            tooltipBaseRight = tooltipBaseLeft + TOOLTIP_BORDER;
        }

        if (tooltipBaseRight > tipRight - TOOLTIP_BORDER) {
            tooltipBaseRight = tipRight - TOOLTIP_BORDER;
            tooltipBaseLeft = tooltipBaseRight - TOOLTIP_BORDER;
        }

        glLoadIdentity();
        glDisable(GL_TEXTURE_2D);

        glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
        glBegin(GL_TRIANGLE_STRIP);

        glVertex3f(tipRight, tipBottom, 0.0f);
        glVertex3f(tipRight, tipTop, 0.0f);
        glVertex3f(tipLeft, tipBottom, 0.0f);
        glVertex3f(tipLeft, tipTop, 0.0f);

        glEnd();

        if (invert) {
            glBegin(GL_TRIANGLES);
            glVertex3f(x, y, 0.0f);
            glVertex3f(tooltipBaseLeft, y - 2.0 * TOOLTIP_BORDER, 0.0f);
            glVertex3f(tooltipBaseRight, y - 2.0 * TOOLTIP_BORDER, 0.0f);
            glEnd();
        } else {
            glBegin(GL_TRIANGLES);
            glVertex3f(x, y, 0.0f);
            glVertex3f(tooltipBaseRight, y + 2.0 * TOOLTIP_BORDER, 0.0f);
            glVertex3f(tooltipBaseLeft, y + 2.0 * TOOLTIP_BORDER, 0.0f);
            glEnd();
        }

        glEnable(GL_TEXTURE_2D);

        textRenderer->renderText(ALIGN_LEFT,
                                 Vector(tipLeft + TOOLTIP_BORDER,
                                        tipBottom + TOOLTIP_BORDER),
                                 text);
    }
}

void Tooltip::setOrigin(const Vector &position) {
    this->position = position;
}

void Tooltip::setText(std::string text) {
    this->text.clear();
    this->text.push_back(text);
}

void Tooltip::setText(std::vector<std::string> text) {
    this->text = text;
}

void Tooltip::setVisibility(bool visibility) {
    this->visible = visibility;
}

std::vector<std::string> Tooltip::getText() {
    return text;
}
