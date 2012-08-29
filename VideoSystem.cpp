#include "VideoSystem.h"
#include "Engine.h"

#include <iostream>

using namespace Engine;

VideoSystem::VideoSystem() {
    std::cout << "Video system constructor." << std::endl;

    this->windowWidth = 1024;
    this->windowHeight = 768;
    this->windowDepth = 32;

    this->screen = 0;
    this->textureManager = new TextureManager();
    this->displayListManager = new DisplayListManager();
    this->selectionManager = new SelectionManager();
}

VideoSystem::~VideoSystem() {
    if (this->screen) {
        SDL_FreeSurface(this->screen);
        this->screen = 0;
    }

    if (this->textureManager) {
        delete this->textureManager;
        this->textureManager = 0;
    }

    if (this->displayListManager) {
        delete this->displayListManager;
        this->displayListManager = 0;
    }

    if (this->selectionManager) {
        delete this->selectionManager;
        this->selectionManager = 0;
    }

    std::cout << "Video system destructor." << std::endl;
}

int VideoSystem::setVideoMode(unsigned int width, unsigned int height,
                              unsigned int depth, bool fullscreen) {
    int err = 0;

    this->windowWidth = width;
    this->windowHeight = height;

    if (fullscreen) {
        this->screen = SDL_SetVideoMode(width, height, depth,
                                        SDL_OPENGL | SDL_FULLSCREEN);
    } else {
        this->screen = SDL_SetVideoMode(width, height, depth, SDL_OPENGL);
    }
    if (!this->screen) {
        std::cout << "Failed to set video mode: " << SDL_GetError()
        << std::endl;
        err = -1;
    } else {
        this->windowWidth = width;
        this->windowHeight = height;
        this->windowDepth = depth;

        SDL_ShowCursor(SDL_DISABLE);

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    return err;
}

void VideoSystem::swapBuffers() {
    SDL_GL_SwapBuffers();
}

void VideoSystem::loadTexture(std::string filename, std::string textureID) {
    textureManager->loadTexture(filename, textureID);
}

void VideoSystem::bindTexture(std::string textureID) {
    GLuint textureName = textureManager->getTextureName(textureID);

    glBindTexture(GL_TEXTURE_2D, textureName);
}

void VideoSystem::newDisplayList(std::string listID) {
    displayListManager->newDisplayList(listID);
}

void VideoSystem::endDisplayList() {
    displayListManager->endDisplayList();
}

void VideoSystem::destroyDisplayList(std::string listID) {
    displayListManager->destroyDisplayList(listID);
}

void VideoSystem::renderList(std::string listID) {
    displayListManager->renderDisplayList(listID);
}

double VideoSystem::getWindowWidth() {
    return this->windowWidth;
}

double VideoSystem::getWindowHeight() {
    return this->windowHeight;
}

void VideoSystem::resetSelection() {
    selectionManager->resetSelection();
}

unsigned int VideoSystem::getSelectionID() {
    return selectionManager->getSelectionID();
}

void VideoSystem::setSelectionObject(unsigned int selectionID,
                                     int type, void *data) {
    selectionManager->setSelectionObject(selectionID, type, data);
}

SelectionObject VideoSystem::getSelectionObject(unsigned int selectionID) {
    return selectionManager->getSelectionObject(selectionID);
}

SelectionObject VideoSystem::getSelectionObject(double x, double y) {
    double orthoHeight = 1.0;
    double orthoWidth =
        ((double)windowWidth / (double)windowHeight) * orthoHeight;

    int ix = ((x + (orthoWidth / 2.0)) / orthoWidth) * windowWidth;
    int iy = ((y + (orthoHeight / 2.0)) / orthoHeight) * windowHeight;

    unsigned char pixel[4];
    glReadPixels(ix, iy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE,
                 pixel);


    unsigned int selectionID =
        pixel[0] + 256 * pixel[1] + (256 * 256) * pixel[2];

    SelectionObject object = getSelectionObject(selectionID);
    return object;
}

void VideoSystem::saveMatrices() {
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
}

void VideoSystem::project(double worldX, double worldY, double worldZ,
                          double *orthoX, double *orthoY, double *orthoZ) {
    gluProject(worldX, worldY, worldZ, modelview, projection, viewport,
               orthoX, orthoY, orthoZ);
}
