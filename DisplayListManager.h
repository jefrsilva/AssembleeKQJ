#ifndef __displaylistmanager__
#define __displaylistmanager__

#include <map>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>

namespace Engine {

    /**
     * \class DisplayListManager
     * \author Jeferson Rodrigues da Silva
     * \date 12/06/2009
     * \file DisplayListManager.h
     * \brief 
     */
    class DisplayListManager {

    private:
        std::map<std::string, GLuint> displayLists;    
        
        void deleteDisplayList(GLuint displayListName);

    public:
        DisplayListManager();
        ~DisplayListManager();

        /*!
         * \brief Creates and start building a display list.
         * \param listID The display list ID.
         */
        void newDisplayList(std::string listID);
        
        /*!
         * \brief Save and compile the current display list.
         */
        void endDisplayList();
        
        /*!
         * \brief Destroys a display list.
         * \param listID The display list ID.
         */
        void destroyDisplayList(std::string listID);
        
        /*!
         * \brief Executes the specified display list. 
         * \param listID The display list ID.
         */
        void renderDisplayList(std::string listID);

    };

}

#endif // __displaylistmanager__
