#include "PlayerTurnParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

PlayerTurnParticle::PlayerTurnParticle(const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    Vector center = position;
    this->pos = center;
    double angle = rng->randomReal() * (2.0 * M_PI);
    double distance = 0.15;
    pos.x += std::cos(angle) * distance;
    pos.y += std::sin(angle) * distance;

    this->vel = Vector();
    this->vel = Vector(pos, center);
    this->vel = this->vel.normalize();
    this->vel = this->vel.mult(0.0005);
    this->acc = Vector(0.0, 0.0, 0.0);
    this->lifetime = 0.0;
    this->duration = 500.0;

    this->slowCounter = 0.0;
    this->slowInterval = 75.0;

    this->size = rng->randomReal(0.055, 0.065);
    this->texture = 8;
    this->rotation = rng->randomReal(-180.0, 180.0);
}

PlayerTurnParticle::~PlayerTurnParticle() {

}

double PlayerTurnParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector PlayerTurnParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double PlayerTurnParticle::getSize() {
    return size * getOpacity();
}

double PlayerTurnParticle::getRotation() {
    return rotation;
}

int PlayerTurnParticle::getTexture() {
    return texture;
}

bool PlayerTurnParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void PlayerTurnParticle::update(double dt) {
    if (isAlive()) {
        slowCounter += dt;
        if (slowCounter > slowInterval) {
            slowCounter -= slowInterval;
            vel = vel.mult(0.75);
        }

        vel = vel.translate(acc.mult(dt));
        pos = pos.translate(vel.mult(dt));
        if (rotation >= 0.0) {
            rotation += (360.0 / 1000.0) * dt;
        } else {
            rotation -= (360.0 / 1000.0) * dt;
        }

        lifetime += dt;
        if (lifetime > duration) {
            lifetime = duration;
        }
    }
}

void PlayerTurnParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

void PlayerTurnParticle::render(double edt) {
    Engine::VideoSystem *videoSystem =
        Engine::Core::getInstance()->getVideoSystem();
    
    setBlendMode();
    videoSystem->bindTexture("Particles");

    double size = getSize();
    double opacity = getOpacity();
    double rotation = getRotation();
    int texture = getTexture();

    double pw = 1.0 / TEX_IMAGE_PARTICLE_WIDTH;
    double ph = 1.0 / TEX_IMAGE_PARTICLE_HEIGHT;

    double particleWidth = 8.0 * pw;
    double particleHeight = 8.0 * ph;

    int row = texture / 12;
    int col = texture % 12;

    double hOffset = col * (particleWidth + 2.0 * pw) + pw;
    double vOffset = 1.0 - ((row + 1) * (particleHeight + 2.0 * ph)) + ph;

    glColor4f(0.35f, 1.0f, 0.35f, opacity);

    glPushMatrix();
    glTranslatef(pos.x, pos.y, 0.0f);
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

    glPopMatrix();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Vector PlayerTurnParticle::getWorldPosition() {
    return pos;
}
