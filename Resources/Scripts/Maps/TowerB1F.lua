-- TowerB1F.lua

print("dofile TowerB1F.lua")

TowerB1F = {}

function TowerB1F:setup() 
    self:setName("Tower B1F")
    self:setMusic("Tower")
    self:setTileset(3)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.004, 0.004)
    self:setFog(0.5, 0.4, 0.35, 0.035)
end

function TowerB1F:onEnterTile(row, col)
    if row == 38 and col == 17 then
        local destMap = "Swamp"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 2, 16, 2)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 17 and col == 38 then
        local destMap = "Tower1F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 18, 38, 2)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    end
end

function TowerB1F:onChangeTurn()
end
