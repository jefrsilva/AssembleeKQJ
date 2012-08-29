#ifndef __textrenderer__
#define __textrenderer__

#include "Vector.h"

#include <vector>
#include <string>

/**
 * \class TextRenderer
 * \author Jeferson Rodrigues da Silva
 * \date 12/07/2009
 * \file TextRenderer.h
 * \brief
 */
class TextRenderer {

private:
    double fontSize;
    double tabLength;

public:
    TextRenderer();
    ~TextRenderer();

    void setFontSize(double fontSize);
    double getFontSize();
    void setTabLength(double tabLength);
    double getTabLength();
    
    std::vector<std::string> getTextWords(std::string text);
    std::vector<std::string> breakText(std::string text, double width);
    
    double getTextLineWidth(std::string text);
    double getTextWidth(std::vector<std::string> text);
    double getTextHeight(std::vector<std::string> text);

    void renderTextLine(int alignment, const Vector &position,
                        std::string text);
    void renderText(int alignment, const Vector &position,
                    std::vector<std::string> text);
    void renderText(int alignment, const Vector &position,
                    std::string text);
                    
    void setTextColor(std::string color);

};

#endif // __textrenderer__
