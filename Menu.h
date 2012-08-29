#ifndef __menu__
#define __menu__

#include "Vector.h"
#include "LinearInterpolator.h"

class TextRenderer;
class Cursor;

/**
 * \class Menu
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file Menu.h
 * \brief
 */
class Menu {

private:
    TextRenderer *textRenderer;
    Cursor *cursor;
    int menuSelected;
    
    Vector fadeColor;
    double fadeOpacity;
    LinearInterpolator iplFadeOpacity;
    
public:
    Menu();
    ~Menu();

    void setCursorPosition(const Vector &position);
    Vector getCursorPosition();
    
    int getSelected();

    void update(double dt);
    void render(double edt);
    void renderGradients();
    void renderKQJ();
    void renderObject(const Vector &position, const Vector &color,
                      double opacity, double size, int texture);

    void setupOrthoView();
    void restoreView();
    
    void setFadeColor(const Vector &color);
    void setFadeAlpha(double alpha);
    void fadeIn(double duration);
    void fadeOut(double duration);
    bool finishedFading();

};

#endif // __menu__
