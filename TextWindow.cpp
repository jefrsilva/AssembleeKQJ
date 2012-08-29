#include "TextWindow.h"
#include "TextRenderer.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>

TextWindow::TextWindow() {
    this->position = Vector();

    this->textRenderer = new TextRenderer();

    this->newCharCounter = 0;
    this->newCharInterval = 30;
    this->numChars = 0;
    
    this->hasPointer = true;
    this->backgroundColor = Vector();
}

TextWindow::~TextWindow() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }
}

void TextWindow::update(double dt) {
    newCharCounter += dt;
    while (newCharCounter >= newCharInterval) {
        newCharCounter -= newCharInterval;
        if (numChars < text.length()) {
            if (text[numChars] == '|') {
                numChars += 5;
            } else {
                numChars++;
            }

            Engine::AudioSystem *audioSystem =
                Engine::Core::getInstance()->getAudioSystem();

            audioSystem->playSound("Dialogue", 0);
        } else if (numChars > text.length()) {
            numChars = text.length();
        }
    }
}

void TextWindow::render(double edt) {
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

    std::vector<std::string> textLines;
    textLines = textRenderer->breakText(text, maxWidth);

    double width =
        2.0 * TOOLTIP_BORDER + textRenderer->getTextWidth(textLines);
    double height =
        2.0 * TOOLTIP_BORDER + textRenderer->getTextHeight(textLines);

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
        tipTop = y - 3.0 * TOOLTIP_BORDER;
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

    glColor4f(backgroundColor.x, backgroundColor.y, backgroundColor.z, 0.75f);
    glBegin(GL_TRIANGLE_STRIP);

    glVertex3f(tipRight, tipBottom, 0.0f);
    glVertex3f(tipRight, tipTop, 0.0f);
    glVertex3f(tipLeft, tipBottom, 0.0f);
    glVertex3f(tipLeft, tipTop, 0.0f);

    glEnd();

    if (hasPointer) {
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
    }

    glEnable(GL_TEXTURE_2D);

    std::vector<std::string> linesToRender;
    unsigned int totalChars = 0;
    for (unsigned int i = 0; i < textLines.size(); i++) {
        unsigned int lineLength = textLines[i].size();
        if (totalChars == numChars) {
            linesToRender.push_back("");
        } else {
            if (totalChars + lineLength <= numChars) {
                linesToRender.push_back(textLines[i]);
                totalChars += textLines[i].size();
            } else {
                std::string lastLine =
                    textLines[i].substr(0, numChars - totalChars);

                linesToRender.push_back(lastLine);
                totalChars = numChars;
            }
        }
    }

    textRenderer->renderText(ALIGN_LEFT,
                             Vector(tipLeft + TOOLTIP_BORDER,
                                    tipBottom + TOOLTIP_BORDER),
                             linesToRender);
}

void TextWindow::setOrigin(const Vector &position) {
    this->position = position;
}

void TextWindow::setText(std::string text) {
    this->text = text;
}

void TextWindow::setWidth(double width) {
    this->maxWidth = width;
}

void TextWindow::setPointer(bool pointer) {
    this->hasPointer = pointer;
}

void TextWindow::setBackgroundColor(double r, double g, double b) {
    backgroundColor = Vector(r, g, b);
}

std::string TextWindow::getText() {
    return text;
}

void TextWindow::skip() {
    numChars = text.length();
}

bool TextWindow::hasFinished() {
    bool finished = (numChars == text.length());

    return finished;
}
