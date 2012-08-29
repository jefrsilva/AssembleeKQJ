#ifndef __gameoverscreen__
#define __gameoverscreen__

#include "Vector.h"
#include "LinearInterpolator.h"

class TextRenderer;
class Cursor;

/**
 * \class GameOverScreen
 * \author Jeferson Rodrigues da Silva
 * \date 01/09/2010
 * \file GameOverScreen.h
 * \brief
 */
class GameOverScreen {

private:
    TextRenderer *textRenderer;
    Cursor *cursor;
    
    Vector fadeColor;
    double fadeOpacity;
    LinearInterpolator iplFadeOpacity;

public:
    GameOverScreen();
    ~GameOverScreen();

    void setCursorPosition(const Vector &position);
    Vector getCursorPosition();

    void update(double dt);
    void render(double edt);

    void setupOrthoView();
    void restoreView();
    
    void setFadeColor(const Vector &color);
    void setFadeAlpha(double alpha);
    void fadeIn(double alpha, double duration);
    void fadeOut(double duration);
    bool finishedFading();

};

#endif // __gameoverscreen__
