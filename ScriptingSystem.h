#ifndef __scriptingsystem__
#define __scriptingsystem__

extern "C" {
#include <lua.h>
#include <lualib.h>
}

#include <tolua++.h>

#include <string>

namespace Engine {

    /**
     * \class ScriptingSystem
     * \author Jeferson Rodrigues da Silva
     * \date 12/26/2009
     * \file ScriptingSystem.h
     * \brief
     */
    class ScriptingSystem {

    private:
        lua_State *luaState;

    public:
        ScriptingSystem();
        ~ScriptingSystem();

        lua_State *getLuaState();
        void resetLuaState();
        void runScript(std::string filename);

    };

}

#endif // __scriptingsystem__
