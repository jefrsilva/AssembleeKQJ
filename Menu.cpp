#include "Menu.h"
#include "TextRenderer.h"
#include "Cursor.h"
#include "GlobalConstants.h"

#include "Engine.h"

Menu::Menu() {
    this->textRenderer = new TextRenderer();
    this->cursor = new Cursor();
    this->menuSelected = 0;

    this->fadeColor = Vector(0.0, 0.0, 0.0);
    this->fadeOpacity = 1.0;
    this->iplFadeOpacity.attach(&this->fadeOpacity);
}

Menu::~Menu() {
    if (this->textRenderer) {
        delete this->textRenderer;
        this->textRenderer = 0;
    }

    if (this->cursor) {
        delete this->cursor;
        this->cursor = 0;
    }
}

void Menu::update(double dt) {
    iplFadeOpacity.update(dt);

    menuSelected = 0;

    double menuPos = 0.2;

    Vector pos = getCursorPosition();
    if (pos.x >= -0.25 && pos.x <= 0.25) {
        if (pos.y >= menuPos + 0.035 - (0.5 / 48.0) &&
                pos.y <= menuPos + 0.035 + (1.5 / 48.0)) {
            menuSelected = 1;
        }
        if (pos.y >= menuPos - 0.035 - (0.5 / 48.0) &&
                pos.y <= menuPos - 0.035 + (1.5 / 48.0)) {
            menuSelected = 2;
        }
    }
}

void Menu::render(double edt) {
    setupOrthoView();

    renderGradients();
    renderKQJ();

    textRenderer->setFontSize(1.0 / 24.0);
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, 0.4),
                             "|ff8|The King, the Queen and the Jester|fff|");

    double menuPos = 0.2;
    textRenderer->setFontSize(1.0 / 48.0);
    if (menuSelected == 1) {
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(0.0, menuPos + 0.035),
                                 "|ff0|Start a new game|fff|");
    } else {
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(0.0, menuPos + 0.035),
                                 "Start a new game");
    }
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, menuPos),
                             "|888|Continue a previous game|fff|");
    if (menuSelected == 2) {
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(0.0, menuPos - 0.035),
                                 "|ff0|Quit game|fff|");
    } else {
        textRenderer->renderText(ALIGN_CENTER,
                                 Vector(0.0, menuPos - 0.035),
                                 "Quit game");
    }

    double vpos = -0.175;
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos), "|88f|Graphics|fff|");
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.025), "Arachne, im9today, MashPotato, Imp, pgil");
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.050), "dbb, Gyorgy Straub, tocky, Oddball, oryx");

    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.100), "|88f|Music|fff|");
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.125), "Craig Stern, Take One, TEM, Wyvern, Yokky");

    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.175), "|88f|Sound Effects|fff|");
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.200), "BigLon, feeblethemighty");

    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.250), "|88f|Design and Programming|fff|");
    textRenderer->renderText(ALIGN_CENTER,
                             Vector(0.0, vpos - 0.275), "Jeferson R. Silva");

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

void Menu::renderGradients() {
    glLoadIdentity();
    glDisable(GL_TEXTURE_2D);

    // Render bottom gradient
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(0.8f, 0.0f, 0.0f, 0.8f);
    glVertex3f( 1.0f, -0.5f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, -0.1f, 0.0f);

    glColor4f(0.8f, 0.0f, 0.0f, 0.8f);
    glVertex3f(-1.0f, -0.5f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -0.1f, 0.0f);
    glEnd();

    // Render top gradient
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(0.7f, 0.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, 0.35f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f( 1.0f, 0.5f, 0.0f);

    glColor4f(0.7f, 0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 0.35f, 0.0f);

    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glVertex3f(-1.0f, 0.5f, 0.0f);
    glEnd();

    glEnable(GL_TEXTURE_2D);
}

void Menu::renderKQJ() {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();
    videoSystem->bindTexture("Title");


    renderObject(Vector(-0.40, -0.05), Vector(0.5, 0.25, 0.25), 1.0, 0.25, 0);
    renderObject(Vector( 0.0, 0.0), Vector(0.4, 0.20, 0.20), 1.0, 0.20, 1);
    renderObject(Vector( 0.40, -0.05), Vector(0.5, 0.25, 0.25), 1.0, 0.25, 2);
}

void Menu::renderObject(const Vector &position,
                        const Vector &color,
                        double opacity, double size, int texture) {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(position.x, position.y, 0.0);

    double rotation = 0.0;

    double pw = 1.0 / 64.0;
    double ph = 1.0 / 64.0;

    double particleWidth = 8.0 * pw;
    double particleHeight = 8.0 * ph;

    int row = texture / 7;
    int col = texture % 7;

    double hOffset = col * (particleWidth + 2.0 * pw) + pw;
    double vOffset = 1.0 - ((row + 1) * (particleHeight + 2.0 * ph)) + ph;

    glColor4f(color.x, color.y, color.z, opacity);

    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLE_STRIP);

    glTexCoord2f(hOffset + particleWidth, vOffset);
    glVertex3f( 0.5 * size, -0.5 * size, 0.0f);

    glTexCoord2f(hOffset + particleWidth, vOffset + particleHeight);
    glVertex3f( 0.5 * size,  0.5 * size, 0.0f);

    glTexCoord2f(hOffset, vOffset);
    glVertex3f(-0.5 * size, -0.5 * size, 0.0f);

    glTexCoord2f(hOffset, vOffset + particleHeight);
    glVertex3f(-0.5 * size,  0.5 * size, 0.0f);

    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPopMatrix();
}

void Menu::setupOrthoView() {
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

void Menu::restoreView() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void Menu::setCursorPosition(const Vector &position) {
    cursor->setPosition(position);
}

Vector Menu::getCursorPosition() {
    return cursor->getPosition();
}

int Menu::getSelected() {
    return menuSelected;
}

void Menu::setFadeColor(const Vector &color) {
    this->fadeColor = color;
}

void Menu::setFadeAlpha(double alpha) {
    this->fadeOpacity = alpha;
    this->iplFadeOpacity.attach(&this->fadeOpacity);
}

void Menu::fadeIn(double duration) {
    iplFadeOpacity.set(1.0, 0.0, duration);
}

void Menu::fadeOut(double duration) {
    iplFadeOpacity.set(0.0, 1.0, duration);
}

bool Menu::finishedFading() {
    return iplFadeOpacity.finished();
}
