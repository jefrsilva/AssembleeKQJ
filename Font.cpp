#include "Font.h"
#include "GlobalConstants.h"

#include "Engine.h"

Font::Font() {
}

Font::~Font() {

}

void Font::buildDisplayLists() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double pw = 1.0 / TEX_IMAGE_FONT_WIDTH;
    double ph = 1.0 / TEX_IMAGE_FONT_HEIGHT;

    double fontWidth = TEX_FONT_WIDTH * pw;
    double fontHeight = TEX_FONT_HEIGHT * ph;

    for (unsigned char c = 16; c < 176; c++) {
        double row = c / 16;
        double col = c % 16;

        double hOffset = col * fontWidth;
        double vOffset = 1.0 - (row + 1) * fontHeight;

        videoSystem->newDisplayList(std::string(1, c));
        
        glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2f(hOffset + fontWidth, vOffset);
        glVertex3f(1.0f, 0.0f, 0.0f);

        glTexCoord2f(hOffset + fontWidth, vOffset + fontHeight);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glTexCoord2f(hOffset, vOffset);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glTexCoord2f(hOffset, vOffset + fontHeight);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glEnd();
        
        videoSystem->endDisplayList();
    }
}
