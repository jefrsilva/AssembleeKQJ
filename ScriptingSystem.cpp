#include "ScriptingSystem.h"

#include <iostream>

using namespace Engine;

ScriptingSystem::ScriptingSystem() {
    std::cout << "Scripting system constructor." << std::endl;    
    
    luaState = lua_open();
    luaL_openlibs(luaState);
}

ScriptingSystem::~ScriptingSystem() {
    lua_close(luaState);
    luaState = 0;
    
    std::cout << "Scripting system destructor." << std::endl;
}

lua_State *ScriptingSystem::getLuaState() {
    return luaState;
}

void ScriptingSystem::resetLuaState() {
    if (luaState) {
        lua_close(luaState);
    }
    
    luaState = lua_open();
    luaL_openlibs(luaState);
}

void ScriptingSystem::runScript(std::string filename) {
    luaL_loadfile(luaState, filename.c_str()) || lua_pcall(luaState, 0, 0, 0);
}
