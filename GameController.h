#ifndef __gamecontroller__
#define __gamecontroller__

class Player;
class Map;
class UserInterface;
class EventManager;
class Event;
class Item;
class Monster;

#include "Engine.h"
#include "Vector.h"

#include <map>

/**
 * \class GameController
 * \author Jeferson Rodrigues da Silva
 * \date 12/12/2009
 * \file GameController.h
 * \brief
 */
class GameController { // tolua_export

private:
    std::map<std::string, Map *> maps;
    std::map<std::string, int> globalVars;

    int currentTurn;

    Player *player;
    Map *map;
    UserInterface *gui;
    EventManager *eventManager;

    Engine::SelectionObject selection;

    bool paused;
    bool endGame;
    int nextState;

    bool movingForward;
    bool movingBackwards;
    bool strafingLeft;
    bool strafingRight;
    bool turningLeft;
    bool turningRight;

    bool endTurn;

    void setupView();
    void handleSelection();

public:
    GameController();
    ~GameController();
    
    void newGame();

    void update(double dt);
    void render(double edt);

    void freeTurnUpdate(double dt);
    void playerTurnUpdate(double dt);
    void enemyTurnUpdate(double dt);

    void handleLeftClick(const Vector &mousePosition);
    void handleRightClick(const Vector &mousePosition);
    void setCursorPosition(const Vector &cursorPosition);

    void setPlayerMotion(int direction);
    void setPlayerRotation(int direction);
    void stopPlayerMotion(int direction);
    void stopPlayerRotation(int direction);

    void movePlayer(int direction);
    void turnPlayer(int direction);
    
    void setShowMap(bool showMap);
    void toggleMap();
    void toggleTutorial();

    int getCurrentTurn();
    void nextTurn();
    void changeTurn(int turn);
    void endPlayerTurn();
    void queueAsyncEvent(Event *event);
    void queueEvent(Event *event);
    void queueFrontEvent(Event *event);

    void handleInventoryShortcut(int slot);

    void activateHostileMonsters();
    void playerAttack(Item *item, Monster *monster);
    void playerDefense(Item *item);

    void dropItems(Monster *monster);
    void setPlayerMap(Map *map);
    void callEnterTileScript(const Vector &mapPosition);
    void callChangeTurnScript();

    void setPaused(bool paused);
    
    void restart();
    void changeState();

    // Script functions
    // tolua_begin
    Player *getPlayer();
    Map *getMap();
    
    void setGlobalVar(std::string varName, int varValue);
    int getGlobalVar(std::string varName);

    void pause();
    void resume();
    
    void returnToMenu();

    void fadeInMapMusic(std::string mapID, int duration);
    void fadeOutMusic(int duration);

    void setFadeColor(double r, double g, double b);
    void fadeIn(double duration);
    void fadeOut(double duration);
    
    void playerGiveItem(Item *item);
    bool playerHasItem(std::string itemID);
    void healPlayer(int amount);
    void increaseMaxHealth(int amount);
    void setPlayerDirection(int direction);
    void setPlayerLocation(std::string mapName,
                           int row, int col, int direction);
    
    void loadMap(std::string mapID);
    void playMusic(std::string musicID);
    void playSound(std::string soundID);
    
    Monster *newMonster(std::string monsterID, std::string instanceID);
    Item *newItem(std::string itemID);

    void createTextWindow(double x, double y, std::string text, int width,
                          bool blocking);
    void createTextWindow(Monster *monster, std::string text, int width,
                          bool blocking);
    void createTutorialWindow(std::string text);
    void clearTutorialWindow();
    // tolua_end

}; // tolua_export

#endif // __gamecontroller__
