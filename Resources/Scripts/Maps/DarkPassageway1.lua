-- DarkPassageway1.lua

print("dofile DarkPassageway1.lua")

DarkPassageway1 = {}

function DarkPassageway1:setup() 
    self:setName("Dark Passageway")
    self:setMusic("DarkPassageway")
    self:setTileset(4)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.024, 0.024)
    self:setFog(0.0, 0.0, 0.0, 0.075)
end

function DarkPassageway1:onEnterTile(row, col)
    if row == 1 and col == 16 then
        local destMap = "Forest"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 2, 1, 2)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    end
end

function DarkPassageway1:onChangeTurn()
end
