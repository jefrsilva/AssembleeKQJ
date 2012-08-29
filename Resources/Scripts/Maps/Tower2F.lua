-- Tower2F.lua

print("dofile Tower2F.lua")

Tower2F = {}

function Tower2F:setup() 
    self:setName("Tower 2F")
    self:setMusic("Tower")
    self:setTileset(3)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.004, 0.004)
    self:setFog(0.5, 0.4, 0.35, 0.035)
end

function Tower2F:onEnterTile(row, col)
    if row == 22 and col == 38 then
        local destMap = "Tower1F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 21, 38, 0)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    end
end

function Tower2F:onChangeTurn()
end
