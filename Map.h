#ifndef __map__
#define __map__

#include "Engine.h"

#include "Vector.h"
#include "LinearInterpolator.h"
#include "Tile.h"
#include "DoorTile.h"
#include "PressurePlateTile.h"
#include "HoleTile.h"

#include <vector>
#include <string>
#include <list>

class Player;
class Monster;

/**
 * \class Map
 * \author Jeferson Rodrigues da Silva
 * \date 12/08/2009
 * \file Map.h
 * \brief
 */
class Map { // tolua_export

private:
    std::string id;
    std::string name;

    std::string musicID;
    int tileset;
    double ceilingHeight;
    bool floorReflection;    
    
    Vector ambientLight;
    Vector diffuseLight;
    double lightConstant;
    double lightLinear;
    double lightQuadratic;
    
    double fogDensity;
    Vector fogColor;
    
    int width;
    int height;

    std::vector<std::vector<Tile *> > tiles;
    std::vector<Item *> items;  
    std::list<Monster *> monsters;
    std::map<std::string, Monster *> monsterInstances;

    Player *player;

    void swap(int &a, int &b);
    void renderTile(int row, int col, int modelsToRender);
    void renderMap(double edt, int partsToRender, bool selection);
    void renderAlphaObjects(Vector cameraPosition, double viewAngle,
                            double edt, bool selection);
    std::list<AlphaObject> getObjectsSortedByDistance(Vector playerPosition,
            double viewAngle);

    class sortByDistance {
    public:
        bool operator()(const AlphaObject a, const AlphaObject b) {
            return b.distance < a.distance;
        }
    };

public:
    Map(std::string mapID);
    ~Map();

    void update(double dt);
    void render(double edt, bool selection);
    void renderOrtho(int mapState);
    
    std::string getID();

    void setPlayer(Player *player);
    Player *getPlayer();
    
    void setName(std::string name); // tolua_export
    std::string getName();
    
    std::string getMusicID();
    double getCeilingHeight();
    
    void setupBackgroundColor();
    void setupFogAndLighting();
    
    // tolua_begin
    void setMusic(std::string music);
    void setTileset(int tileset); 
    void setCeilingHeight(double height); 
    void setFloorReflection(bool reflection);
    
    void setFog(double r, double g, double b, double density);
    void setAmbientLight(double r, double g, double b);
    void setDiffuseLight(double r, double g, double b);
    void setLightParams(double constant, double linear, double quadratic);
    
    void addItem(Item *item, int row, int col);
    void addMonster(Monster *monster, int row, int col);
    Monster *getMonster(std::string instanceID);
    DoorTile *getDoorAt(int row, int col);
    PressurePlateTile *getPressurePlateAt(int row, int col);
    HoleTile *getHoleAt(int row, int col);
    // tolua_end

    void load(std::string filename);
    void buildMap(std::vector<std::string> stringMap);
    Tile *getTile(int x, int y);
    Tile *getPlayerTile();
    
    void buildModels();
    void destroyModels();
    
    std::vector<Item *> getItems();
    std::list<Monster *> getMonsters();
    
    std::list<AlphaObject> getMonsterObjects();
    std::list<AlphaObject> getParticleObjects(Monster *monster);
    std::list<AlphaObject> getPlayerParticleObjects();    
    
    bool hasLineOfSight(const Vector &a, const Vector &b);
    std::vector<Tile *> findPath(const Vector &start, const Vector &end);
    std::vector<Tile *> findRangedPath(const Vector &start, const Vector &end);
    void moveMonsterTo(Monster *monster, Tile *tile);

}; // tolua_export

#endif // __map__
