#include "TextureManager.h"
#include "Engine.h"

#include <iostream>
#include <string>

using namespace Engine;

TextureManager::TextureManager() {
    std::cout << "Texture manager constructor." << std::endl;
}

TextureManager::~TextureManager() {
    std::map<std::string, GLuint>::iterator it;

    for (it = textures.begin(); it != textures.end(); it++) {
        std::pair<std::string, GLuint> textureInfo = (*it);

        deleteTexture(textureInfo.second);
    }
    
    std::cout << "Texture manager destructor." << std::endl;
}

GLuint TextureManager::createTextureFromImage(std::string filename) {
    GLuint textureID = -1;
    SDL_Surface *image = IMG_Load(filename.c_str());

    if (!image) {
        std::cout << "Error on loading image " << filename << " - "
        << IMG_GetError() << std::endl;
    } else {
        int texWidth = 1;
        while (texWidth < image->w) {
            texWidth *= 2;
        }

        int texHeight = 1;
        while (texHeight < image->h) {
            texHeight *= 2;
        }

        int numChannels = 4;
        int textureSize = texWidth * texHeight * numChannels;
        GLubyte *textureData = new GLubyte[textureSize];

        for (int y = 0; y < image->h; y++) {
            for (int x = 0; x < image->w; x++) {
                unsigned int pixel = getPixel(image, x, image->h - 1 - y);

                unsigned char r, g, b, a;
                SDL_GetRGBA(pixel, image->format, &r, &g, &b, &a);

                unsigned int offset =
                    (y * texWidth * numChannels) + (x * numChannels);
                textureData[offset + 0] = r;
                textureData[offset + 1] = g;
                textureData[offset + 2] = b;
                textureData[offset + 3] = a;
            }
        }

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     texWidth, texHeight,
                     0,
                     GL_RGBA,
                     GL_UNSIGNED_BYTE,
                     textureData);

        delete [] textureData;
        SDL_FreeSurface(image);
    }

    return textureID;
}

unsigned int TextureManager::getPixel(SDL_Surface *surface, int x, int y) {
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {
        case 1:
            return *p;

        case 2:
            return *(Uint16 *)p;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                return p[0] << 16 | p[1] << 8 | p[2];
            } else {
                return p[0] | p[1] << 8 | p[2] << 16;
            }

        case 4:
            return *(Uint32 *)p;

        default:
            return 0;
    }
}

void TextureManager::deleteTexture(GLuint textureID) {
    glDeleteTextures(1, &textureID);
}

void TextureManager::loadTexture(std::string filename, std::string textureID) {
    GLuint textureName = createTextureFromImage(filename);

    textures[textureID] = textureName;
}

GLuint TextureManager::getTextureName(std::string textureID) {
    return textures[textureID];
}
