#ifndef __textwindow__
#define __textwindow__

#include "Vector.h"

class TextRenderer;

#include <vector>
#include <string>

/**
 * \class TextWindow
 * \author Jeferson Rodrigues da Silva
 * \date 12/31/2009
 * \file TextWindow.h
 * \brief
 */
class TextWindow {

private:
    Vector position;
        
    std::string text;
    double maxWidth;
    
    bool hasPointer;
    Vector backgroundColor;
    
    TextRenderer *textRenderer;
    
    double newCharCounter;
    double newCharInterval;
    unsigned int numChars;

public:
    TextWindow();
    ~TextWindow();
    
    void update(double dt);
    void render(double edt);
    
    void setOrigin(const Vector &position);
    void setText(std::string text);
    void setWidth(double width);
    void setPointer(bool pointer);
    void setBackgroundColor(double r, double g, double b);
    
    void skip();
    bool hasFinished();
    
    std::string getText();

};

#endif // __textwindow__
