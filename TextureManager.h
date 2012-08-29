#ifndef __texturemanager__
#define __texturemanager__

#include <map>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>

namespace Engine {

    /**
     * \class TextureManager
     * \author Jeferson Rodrigues da Silva
     * \date 11/26/2009
     * \file TextureManager.h
     * \brief 
     */
    class TextureManager {

    private:
        std::map<std::string, GLuint> textures;

        /*!
         * \brief Creates an OpenGL texture from an image file.
         * \param filename The filename of the image.
         */
        GLuint createTextureFromImage(std::string filename);

        /*!
         * \brief Gets a pixel from a SDL surface.
         * \param surface Pointer to the surface.
         * \param x X coordinate of the pixel.
         * \param y Y coordinate of the pixel.
         */
        unsigned int getPixel(SDL_Surface *surface, int x, int y);

        /*!
        * \brief Deletes a specific texture from memory.
        * \param textureID The texture ID.
        */
        void deleteTexture(GLuint textureID);

    public:
        TextureManager();
        ~TextureManager();

        /*!
         * \brief Creates a new texture from an image file.
         * \param filename Path to the image
         * \param textureID The new texture ID
         */
        void loadTexture(std::string filename, std::string textureID);

        /*!
         * \brief Gets the texture name associated to a texture ID.
         * \param textureID The texture ID
         * \return The OpenGL texture name
         */
        GLuint getTextureName(std::string textureID);
    };

}

#endif // __texturemanager__
