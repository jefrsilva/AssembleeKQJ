-- HedgeMaze.lua

print("dofile HedgeMaze.lua")

HedgeMaze = {}

function HedgeMaze:setup() 
    self:setName("Hedge Maze")
    self:setMusic("HedgeMaze")
    self:setTileset(5)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.008, 0.008)
    self:setFog(0.0, 0.0, 0.0, 0.025)
end

function HedgeMaze:onEnterTile(row, col)
end

function HedgeMaze:onChangeTurn()
end
