-- Swamp.lua

print("dofile Swamp.lua")

Swamp = {}

function Swamp:setup() 
    self:setName("Swamp")
    self:setMusic("Forest")
    self:setTileset(2)
    self:setCeilingHeight(2.0)
    
    self:setAmbientLight(0.5, 0.55, 0.25)
    self:setDiffuseLight(0.5, 0.55, 0.25)
    self:setLightParams(0.0, 0.008, 0.008)
    self:setFog(0.5, 0.55, 0.2, 0.025)
end

function Swamp:onEnterTile(row, col)
    if row == 30 and col == 1 then
        local destMap = "Forest"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 1, 29, 3)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 1 and col == 16 then
        local destMap = "TowerB1F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 38, 18, 1)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    end
end

function Swamp:onChangeTurn()
end
