#ifndef __videosystem__
#define __videosystem__

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include <string>

namespace Engine {

    class TextureManager;
    class DisplayListManager;
    class SelectionManager;
    class SelectionObject;

    /**
     * \class VideoSystem
     * \author Jeferson Rodrigues da Silva
     * \date 11/26/2009
     * \file VideoSystem.h
     * \brief
     */
    class VideoSystem {

    private:
        unsigned int windowWidth;
        unsigned int windowHeight;
        unsigned int windowDepth;
        SDL_Surface *screen;
        TextureManager *textureManager;
        DisplayListManager *displayListManager;
        SelectionManager *selectionManager;

        GLdouble modelview[16];
        GLdouble projection[16];
        GLint viewport[4];

    public:
        VideoSystem();
        ~VideoSystem();

        /*!
         * \brief Sets the video mode.
         * \param width The window width
         * \param height The window height
         * \param depth The window color depth
         * \param fullscreen Should open in fullscreen mode
         * \return 0 on success, -1 otherwise
         */
        int setVideoMode(unsigned int width, unsigned int height,
                         unsigned int depth, bool fullscreen);

        /*!
         * \brief Swaps the double buffer.
         */
        void swapBuffers();

        /*!
         * \brief Loads a new texture from an image and associates it with a
         *        texture ID.
         * \param filename Path to the texture image
         * \param textureID The texture ID
         */
        void loadTexture(std::string filename, std::string textureID);

        /*!
         * \brief Binds the texture associated to a texture ID.
         * \param textureID The texture ID
         */
        void bindTexture(std::string textureID);

        /*!
         * \brief Creates a new display list associated to a list ID.
         * \param listID The list ID
         */
        void newDisplayList(std::string listID);

        /*!
         * \brief Save and compile the current display list.
         */
        void endDisplayList();
        
        /*!
         * \brief Destroys a display list associated to a specified ID.
         * \param listID The list ID
         */
        void destroyDisplayList(std::string listID);

        /*!
         * \brief Renders a specified display list.
         * \param listID The list ID
         */
        void renderList(std::string listID);

        /*!
         * \brief Gets the window width.
         * \return The window width in pixels.
         */
        double getWindowWidth();

        /*!
         * \brief Gets the window height.
         * \return The window height in pixels.
         */
        double getWindowHeight();

        /*!
         * \brief Resets the selection objects.
         */
        void resetSelection();

        /*!
         * \brief Gets an unique selection object ID.
         * \return The selection ID.
         */
        unsigned int getSelectionID();

        /*!
         * \brief Associates an selection object to a selection ID.
         * \param selectionID The selection ID.
         * \param type The object type.
         * \param data Pointer to the object.
         */
        void setSelectionObject(unsigned int selectionID,
                                int type, void *data);

        /*!
         * \brief Gets the selection object associated to a specified ID.
         * \param selectionID The selection ID.
         * \return The selection object.
         */
        SelectionObject getSelectionObject(unsigned int selectionID);

        /*!
         * \brief Gets the selection object under the specified location.
         * \param x The x coordinate of the selection.
         * \param y The y coordinate of the selection.
         * \return The selection object.
         */
        SelectionObject getSelectionObject(double x, double y);

        /*!
         * \brief Saves the projection, modelview and viewport matrices.
         */
        void saveMatrices();

        /*!
         * \brief Finds the screen coordinates for a point in 3D.
         * \param worldX The x coordinate of the point
         * \param worldY The y coordinate of the point
         * \param worldZ the z coordinate of the point
         * \param orthoX Pointer to the screen x coordinate of the point
         * \param orthoY Pointer to the screen y coordinate of the point
         * \param orthoZ Pointer to the screen z coordinate of the point
         */
        void project(double worldX, double worldY, double worldZ,
                     double *orthoX, double *orthoY, double *orthoZ);
    };

}

#endif // __videosystem__
