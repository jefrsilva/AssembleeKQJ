#include "SelectionObject.h"

#include "Engine.h"

using namespace Engine;

SelectionObject::SelectionObject() {
    this->type = -1;
    this->data = 0;
}

SelectionObject::SelectionObject(int type, void *data) {
    this->type = type;
    this->data = data;
}

SelectionObject::SelectionObject(const SelectionObject &object) {
    this->type = object.type;
    this->data = object.data;
}

SelectionObject::~SelectionObject() {
    
}

int SelectionObject::getType() {
    return this->type;
}

void *SelectionObject::getData() {
    return this->data;
}
