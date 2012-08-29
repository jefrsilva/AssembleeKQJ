#ifndef __tooltip__
#define __tooltip__

#include "Vector.h"

class TextRenderer;

#include <vector>
#include <string>

/**
 * \class Tooltip
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file Tooltip.h
 * \brief 
 */
class Tooltip {
    
private:
    bool visible;
    Vector position;
        
    std::vector<std::string> text;
    
    TextRenderer *textRenderer;

public:
    Tooltip();
    ~Tooltip();
    
    void update(double dt);
    void render(double edt);
    
    void setOrigin(const Vector &position);
    void setText(std::string text);
    void setText(std::vector<std::string> text);
    void setVisibility(bool visibility);
    
    std::vector<std::string> getText();

};

#endif // __tooltip__
