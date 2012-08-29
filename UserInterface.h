#ifndef __userinterface__
#define __userinterface__

#include "Vector.h"
#include "LinearInterpolator.h"

class TextRenderer;
class HealthPot;
class TurnStone;
class InventoryBar;
class Tooltip;
class TextWindow;
class Cursor;
class Player;
class Map;
class Item;
class Tile;
class Animation;

#include <list>

/**
 * \class UserInterface
 * \author Jeferson Rodrigues da Silva
 * \date 12/07/2009
 * \file UserInterface.h
 * \brief
 */
class UserInterface {

private:
    TextRenderer *textRenderer;
    HealthPot *healthPot;
    TurnStone *turnStone;
    InventoryBar *inventoryBar;
    Map *map;
    Player *player;
    Tooltip *worldTooltip;
    TextWindow *textWindow;
    TextWindow *tutorialWindow;
    Cursor *cursor;
    
    int mapState;
    bool showTutorial;
    
    Vector fadeColor;
    double fadeOpacity;
    LinearInterpolator iplFadeOpacity;
    
    bool showTooltips;
    bool showWorldTooltips;
    
    std::list<Animation *> animations;
    
    void setupOrthoView();
    void restoreView();
    void renderGradients();

public:
    UserInterface(Player *player);
    ~UserInterface();

    void update(double dt);
    void render(double edt, bool selection);
    
    void renderDefense();
    
    void setMap(Map *map);
    
    void setShowMap(bool showMap);
    void toggleMap();
    void toggleTutorial();

    void setCursorPosition(const Vector &position);
    Vector getCursorPosition();
    
    Item *getCursorItem();
    void detachCursorItem();
    
    InventoryBar *getInventoryBar();
    
    Vector getSlotPosition(int slot);
    
    Vector getHealthPotPosition();
    Vector getTurnStonePosition();

    void setWorldTooltip(Tooltip *tooltip);
    
    void setTextWindow(TextWindow *textWindow);
    TextWindow *getTextWindow();
    
    void setTutorialWindow(TextWindow *tutorialWindow);
    TextWindow *getTutorialWindow();
    void clearTutorialWindow();

    bool handleMouseClick(const Vector &position, unsigned int button);
    void handleMouseClick(Item *item, unsigned int button);
    void handleMouseClick(Tile *tile, unsigned int button);
    
    void setTurn(int turn);
    void attachAnimation(Animation *animation);
    
    void setTooltipVisibility(bool visibility);
    void setWorldTooltipVisibility(bool visibility);
    
    void setFadeColor(const Vector &color);
    void fadeIn(double duration);
    void fadeOut(double duration);
    bool finishedFading();

};

#endif // __userinterface__
