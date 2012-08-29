#include "DisplayListManager.h"
#include "Engine.h"

#include <iostream>

using namespace Engine;

DisplayListManager::DisplayListManager() {
    std::cout << "Display list manager constructor." << std::endl;    
}

DisplayListManager::~DisplayListManager() {
    std::map<std::string, GLuint>::iterator it;

    for (it = displayLists.begin(); it != displayLists.end(); it++) {
        std::pair<std::string, GLuint> displayListInfo = (*it);

        deleteDisplayList(displayListInfo.second);
    }
    
    std::cout << "Display list manager destructor." << std::endl;
}

void DisplayListManager::newDisplayList(std::string listID) {
    GLuint displayListName = glGenLists(1);
    
    displayLists[listID] = displayListName;    
    glNewList(displayListName, GL_COMPILE);
}

void DisplayListManager::endDisplayList() {
    glEndList();
}

void DisplayListManager::destroyDisplayList(std::string listID) {
    std::map<std::string, GLuint>::iterator it =
        displayLists.find(listID);
        
    if (it != displayLists.end()) {
        GLuint displayListName = (*it).second;
        deleteDisplayList(displayListName);
        displayLists.erase(it);
    }
}

void DisplayListManager::renderDisplayList(std::string listID) {
    glCallList(displayLists[listID]);
}

void DisplayListManager::deleteDisplayList(GLuint displayListName) {
    glDeleteLists(displayListName, 1);
}
