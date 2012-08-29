#include "GameOverScreen.h"
#include "TextRenderer.h"
#include "Cursor.h"
#include "GlobalConstants.h"

#include "Engine.h"

GameOverScreen::GameOverScreen() {
    this->textRenderer = new TextRenderer();
    this->cursor = new Cursor();
    
    this->fadeColor = Vector(1.0, 0.0, 0.0);
    this->fadeOpacity = 1.0;
    this->iplFadeOpacity.attach(&this->fadeOpacity);
    this->iplFadeOpacity.set(1.0, 0.0, 2000);
}

GameOverScreen::~GameOverScreen() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }

    if (this->cursor) {
        delete this->cursor;
        this->cursor = 0;
    }
}

void GameOverScreen::update(double dt) {
    iplFadeOpacity.update(dt);
}

void GameOverScreen::render(double edt) {
    setupOrthoView();

    glDisable(GL_TEXTURE_2D);

    glColor4f(0.25f, 0.0f, 0.0f, 1.0);

    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);
    
    textRenderer->setFontSize(1.0 / 24.0);
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, 0.0),
                             "|f00|Game Over|fff|");

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();
    videoSystem->bindTexture("Interface");
    cursor->render(edt);

    glDisable(GL_TEXTURE_2D);

    glColor4f(fadeColor.x, fadeColor.y, fadeColor.z,
              iplFadeOpacity.getValue(edt));

    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(1.0f, -0.5f, 0.0f);
    glVertex3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 0.0f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);

    restoreView();
}

void GameOverScreen::setupOrthoView() {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glClearDepth(200.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();

    double width = videoSystem->getWindowWidth();
    double height = videoSystem->getWindowHeight();

    double orthoHeight = 1.0;
    double orthoWidth = (width / height) * orthoHeight;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-orthoWidth / 2.0, orthoWidth / 2.0,
            -orthoHeight / 2.0, orthoHeight / 2.0, 0.5f, -0.5f);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GameOverScreen::restoreView() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void GameOverScreen::setCursorPosition(const Vector &position) {
    cursor->setPosition(position);
}

Vector GameOverScreen::getCursorPosition() {
    return cursor->getPosition();
}

void GameOverScreen::setFadeColor(const Vector &color) {
    this->fadeColor = color;
}

void GameOverScreen::setFadeAlpha(double alpha) {
    this->fadeOpacity = alpha;
    this->iplFadeOpacity.attach(&this->fadeOpacity);
}

void GameOverScreen::fadeIn(double alpha, double duration) {
    iplFadeOpacity.set(1.0, alpha, duration);
}

void GameOverScreen::fadeOut(double duration) {
    iplFadeOpacity.set(0.0, 1.0, duration);
}

bool GameOverScreen::finishedFading() {
    return iplFadeOpacity.finished();
}
