-- Tower1F.lua

print("dofile Tower1F.lua")

Tower1F = {}

function Tower1F:setup() 
    self:setName("Tower 1F")
    self:setMusic("Tower")
    self:setTileset(3)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.004, 0.004)
    self:setFog(0.5, 0.4, 0.35, 0.035)
end

function Tower1F:onEnterTile(row, col)
    if row == 17 and col == 38 then
        local destMap = "TowerB1F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 18, 38, 2)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 22 and col == 38 then
        local destMap = "Tower2F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 21, 38, 0)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    end
end

function Tower1F:onChangeTurn()
end
