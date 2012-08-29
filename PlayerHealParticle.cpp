#include "PlayerHealParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

PlayerHealParticle::PlayerHealParticle(const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    Vector center = position;
    this->pos = center;
    double angle = rng->randomReal() * (2.0 * M_PI);
    double distance = rng->randomReal(0.00, 0.05);
    pos.x += std::cos(angle) * distance;
    pos.y += std::sin(angle) * distance;

    this->vel = Vector(0.0, 0.0005, 0.0);
    this->acc = Vector(0.0, 0.0, 0.0);
    this->lifetime = 0.0;
    this->duration = 500.0;

    this->slowCounter = 0.0;
    this->slowInterval = 75.0;

    this->size = rng->randomReal(0.055, 0.065);
    this->texture = 10;
    this->rotation = rng->randomReal(-180.0, 180.0);
}

PlayerHealParticle::~PlayerHealParticle() {

}

double PlayerHealParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector PlayerHealParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double PlayerHealParticle::getSize() {
    return size * getOpacity();
}

double PlayerHealParticle::getRotation() {
    return rotation;
}

int PlayerHealParticle::getTexture() {
    return texture;
}

bool PlayerHealParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void PlayerHealParticle::update(double dt) {
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

void PlayerHealParticle::setBlendMode() {
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

void PlayerHealParticle::render(double edt) {
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

    glColor4f(1.0f, 1.0f, 1.0f, opacity);

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

Vector PlayerHealParticle::getWorldPosition() {
    return pos;
}
