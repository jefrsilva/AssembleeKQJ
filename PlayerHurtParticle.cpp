#include "PlayerHurtParticle.h"
#include "GlobalConstants.h"

#include "Engine.h"

PlayerHurtParticle::PlayerHurtParticle(const Vector &position) {
    Engine::RandomNumberGenerator *rng =
        Engine::Core::getInstance()->getRandomNumberGenerator();

    Vector center = position;
    this->pos = center;
    double angle = rng->randomReal() * (2.0 * M_PI);
    double distance = rng->randomReal(0.00, 0.06);
    pos.x += std::cos(angle) * distance;
    pos.y += std::sin(angle) * distance;


    this->vel = Vector();
    this->acc = Vector(0.0, -1.0e-6, 0.0);
    this->lifetime = 0.0;
    this->duration = 500.0;

    this->slowCounter = 0.0;
    this->slowInterval = 75.0;

    this->size = rng->randomReal(0.055, 0.065);
    this->texture = 11;
    this->rotation = rng->randomReal(-180.0, 180.0);
}

PlayerHurtParticle::~PlayerHurtParticle() {

}

double PlayerHurtParticle::getOpacity() {
    double alpha = 1.0 - (lifetime / duration);

    return alpha;
}

Vector PlayerHurtParticle::getPosition(double edt) {
    Vector eVel = vel.translate(acc.mult(edt));
    Vector ePos = pos.translate(vel.mult(edt));

    return ePos;
}

double PlayerHurtParticle::getSize() {
    return size * getOpacity();
}

double PlayerHurtParticle::getRotation() {
    return rotation;
}

int PlayerHurtParticle::getTexture() {
    return texture;
}

bool PlayerHurtParticle::isAlive() {
    bool alive = (lifetime < duration);

    return alive;
}

void PlayerHurtParticle::update(double dt) {
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

void PlayerHurtParticle::setBlendMode() {

}

void PlayerHurtParticle::render(double edt) {
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

Vector PlayerHurtParticle::getWorldPosition() {
    return pos;
}
