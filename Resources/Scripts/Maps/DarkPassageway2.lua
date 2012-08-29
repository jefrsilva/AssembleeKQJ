-- DarkPassageway2.lua

print("dofile DarkPassageway2.lua")

DarkPassageway2 = {}

function DarkPassageway2:setup() 
    self:setName("Dark Passageway")
    self:setMusic("DarkPassageway")
    self:setTileset(4)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.016, 0.016)
    self:setFog(0.0, 0.0, 0.0, 0.035)
end

function DarkPassageway2:onEnterTile(row, col)
end

function DarkPassageway2:onChangeTurn()
end
