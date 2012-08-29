#include "SelectionManager.h"
#include "Engine.h"

#include <iostream>

using namespace Engine;

SelectionManager::SelectionManager() {
    std::cout << "Selection manager constructor." << std::endl;

    this->nextID = 0;
}

SelectionManager::~SelectionManager() {
    std::cout << "Selection manager destructor." << std::endl;
}

void SelectionManager::resetSelection() {
    this->nextID = 0;
    objects.clear();
}

unsigned int SelectionManager::getSelectionID() {
    unsigned int id = nextID;
    nextID++;

    return id;
}

void SelectionManager::setSelectionObject(unsigned int selectionID,
        int type, void *data) {
    std::pair<GLuint, SelectionObject> object =
        std::pair<GLuint, SelectionObject>(selectionID,
                                           SelectionObject(type, data));

    objects.insert(object);
}

SelectionObject SelectionManager::getSelectionObject(unsigned int selectionID) {
    SelectionObject object;
    
    std::map<unsigned int, SelectionObject>::iterator it =
        objects.find(selectionID);
    
    if (it != objects.end()) {
        object = SelectionObject(objects[selectionID]);
    }
    
    return object;
}
