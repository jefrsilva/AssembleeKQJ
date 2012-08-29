#ifndef __selectionmanager__
#define __selectionmanager__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>

#include <map>

#include "SelectionObject.h"

namespace Engine {
    
    /**
     * \class SelectionManager
     * \author Jeferson Rodrigues da Silva
     * \date 12/09/2009
     * \file SelectionManager.h
     * \brief
     */
    class SelectionManager {
        
    private:
        unsigned int nextID;
        std::map<unsigned int, SelectionObject> objects;

    public:
        SelectionManager();
        ~SelectionManager();
        
        void resetSelection();
        unsigned int getSelectionID();
        void setSelectionObject(unsigned int selectionID, int type, void *data);
        SelectionObject getSelectionObject(unsigned int selectionID);

    };

}

#endif // __selectionmanager__
