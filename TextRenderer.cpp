#include "TextRenderer.h"
#include "GlobalConstants.h"

#include "Engine.h"

#include <iostream>
#include <sstream>

TextRenderer::TextRenderer() {
    this->fontSize = 1.0 / 48.0;
    this->tabLength = 2.0;
}

TextRenderer::~TextRenderer() {

}

void TextRenderer::setFontSize(double fontSize) {
    this->fontSize = fontSize;
}

double TextRenderer::getFontSize() {
    return this->fontSize;
}

void TextRenderer::setTabLength(double tabLength) {
    this->tabLength = tabLength;
}

double TextRenderer::getTabLength() {
    return this->tabLength;
}

std::vector<std::string> TextRenderer::getTextWords(std::string text) {
    std::vector<std::string> words;
    std::string word = "";

    for (unsigned int i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            word += text[i];
        } else {
            words.push_back(word);
            word = "";
        }
    }

    if (word.size() > 0) {
        words.push_back(word);
        word = "";
    }

    return words;
}

std::vector<std::string> TextRenderer::breakText(std::string text,
        double width) {
    std::vector<std::string> words = getTextWords(text);

    std::vector<std::string> textLines;
    std::string textLine = "";

    double spaceWidth =
        (double)(FONT_WIDTHS[32] + 1) / TEX_FONT_WIDTH;

    double lineWidth = 0.0;
    for (unsigned int i = 0; i < words.size(); i++) {
        double wordWidth = getTextLineWidth(words[i]);

        if (i == 0) {
            textLine = words[i];
            lineWidth = wordWidth;
        } else {

            if (lineWidth + spaceWidth + wordWidth > width) {
                textLines.push_back(textLine);

                textLine = words[i];
                lineWidth = wordWidth;
            } else {
                textLine = textLine + " " + words[i];

                lineWidth += (wordWidth + spaceWidth);
            }

        }
    }

    if (textLine.size() > 0) {
        textLines.push_back(textLine);
    }

    return textLines;

}

double TextRenderer::getTextWidth(std::vector<std::string> text) {
    double totalWidth = 0.0;

    for (unsigned int k = 0; k < text.size(); k++) {
        std::string line = text[k];

        if (line.size() > 0) {
            double lineWidth = getTextLineWidth(line);
            totalWidth = std::max(totalWidth, lineWidth);
        }
    }

    return totalWidth * fontSize;
}

double TextRenderer::getTextLineWidth(std::string text) {
    double lineWidth = 0.0;

    for (unsigned int i = 0; i < text.size(); i++) {
        unsigned char c = text[i];

        if (c == '_') {
            double nextTab = floor(lineWidth / tabLength) + 1.0;

            lineWidth += (nextTab * tabLength) - lineWidth;
        } else if (c == '|') {
            i += 4;
            continue;
        } else {
            double hJump =
                (double)(FONT_WIDTHS[c] + 1) / TEX_FONT_WIDTH;

            lineWidth += hJump;
        }
    }
    if (lineWidth > 0.0) {
        lineWidth -= 1.0 / TEX_FONT_WIDTH;
    }

    return lineWidth;
}

double TextRenderer::getTextHeight(std::vector<std::string> text) {
    double totalHeight =
        text.size() * (fontSize + 0.2 * fontSize) - (0.2 * fontSize);

    return totalHeight;
}

void TextRenderer::renderTextLine(int alignment, const Vector &position,
                                  std::string text) {
    double x = position.x;
    double y = position.y;

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double totalWidth = getTextLineWidth(text);

    double xPos = 0.0;
    double yPos = y / fontSize;

    if (alignment == ALIGN_CENTER) {
        xPos = x / fontSize - totalWidth / 2.0;
    } else if (alignment == ALIGN_LEFT) {
        xPos = x / fontSize;
    } else if (alignment == ALIGN_RIGHT) {
        xPos = x / fontSize - totalWidth;
    }

    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);

    double lineWidth = 0.0;

    int length = text.size();
    for (int i = 0; i < length; i++) {
        unsigned char c = text[i];

        if (c == '_') {
            double nextTab = floor(lineWidth / tabLength) + 1.0;

            double hJump = (nextTab * tabLength) - lineWidth;

            glTranslatef(hJump, 0.0f, 0.0f);
            lineWidth += hJump;
        } else if (c == '|') {
            std::stringstream colorPattern;
            colorPattern << text[i+1] << text[i+2] << text[i+3];
            setTextColor(colorPattern.str());

            i += 4;
            continue;
        } else {
            double hJump =
                (double)(FONT_WIDTHS[c] + FONT_OFFSETS[c] + 1) / TEX_FONT_WIDTH;
            glTranslatef((double)-FONT_OFFSETS[c] / TEX_FONT_WIDTH, 0.0f, 0.0f);

            if (c != 32) {
                videoSystem->renderList(std::string(1, c));
            }

            glTranslatef(hJump, 0.0f, 0.0f);

            lineWidth += (double)-FONT_OFFSETS[c] / TEX_FONT_WIDTH + hJump;
        }
    }

    glPopMatrix();
}

void TextRenderer::renderText(int alignment, const Vector &position,
                              std::vector<std::string> text) {
    double x = position.x;
    double y = position.y;

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    videoSystem->bindTexture("Font");

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glLoadIdentity();
    glPushMatrix();
    glScalef(fontSize, fontSize, 1.0f);
    glTranslatef(0.0f, getTextHeight(text) / fontSize, 0.0f);

    double lineOffset = -fontSize;
    for (unsigned int i = 0; i < text.size(); i++) {
        std::string line = text[i];

        if (line.size()) {
            if (line[0] == '#') {
                setTextColor(line);
            } else {
                renderTextLine(alignment,
                               Vector(x, y + lineOffset),
                               line);
                lineOffset -= 1.2 * fontSize;
            }
        } else {
            lineOffset -= 1.2 * fontSize;
        }
    }

    glPopMatrix();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void TextRenderer::renderText(int alignment, const Vector &position,
                              std::string text) {
    std::vector<std::string> multiText;
    multiText.push_back(text);

    renderText(alignment, position, multiText);
}

void TextRenderer::setTextColor(std::string color) {
    unsigned char rc = color[0];
    unsigned char gc = color[1];
    unsigned char bc = color[2];

    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    if (rc >= '0' && rc <= '9') {
        r = (int)(rc - '0');
    } else if (rc >= 'a' && rc <= 'f') {
        r = 10 + (int)(rc - 'a');
    }

    if (gc >= '0' && gc <= '9') {
        g = (int)(gc - '0');
    } else if (gc >= 'a' && gc <= 'f') {
        g = 10 + (int)(gc - 'a');
    }

    if (bc >= '0' && bc <= '9') {
        b = (int)(bc - '0');
    } else if (bc >= 'a' && bc <= 'f') {
        b = 10 + (int)(bc - 'a');
    }

    r = (r * 16.0) / 240.0;
    g = (g * 16.0) / 240.0;
    b = (b * 16.0) / 240.0;

    glColor4f(r, g, b, 1.0f);
}
