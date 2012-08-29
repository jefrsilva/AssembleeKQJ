#include "Particle.h"
#include "GlobalConstants.h"

#include "Engine.h"

void Particle::render(double edt) {
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
}
