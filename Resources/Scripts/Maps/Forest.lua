-- Forest.lua

print("dofile Forest.lua")

Forest = {}

function Forest:setup() 
    local monster

    self:setName("Forest")
    self:setMusic("Forest")
    self:setTileset(2)
    self:setCeilingHeight(2.0)
    
    self:setAmbientLight(0.75, 0.75, 0.75)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.008, 0.008)
    self:setFog(1.0, 1.0, 1.0, 0.025)
    
    local monster = game:newMonster("Jester", "Jester")
    self:addMonster(monster, 25, 8)
end

function Forest:onEnterTile(row, col)
    if row == 30 and col == 6 then
        local destMap = "UndergroundPrisonB2F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 29, 9, 0)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 1 and col == 1 then
        local destMap = "DarkPassageway1"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 2, 16, 2)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 1 and col == 30 then
        local destMap = "Swamp"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 30, 2, 1)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 26 and col == 8 then
        Forest:jesterTalk()
    end
end

function Forest:onChangeTurn()

end

function Forest:jesterTalk()  
    local map = game:getMap()
    local jester = map:getMonster("Jester")

    game:setPlayerDirection(0)
    game:pause()
    game:createTextWindow(jester, "Finally! You almost killed me from pure boredom. Oh well, at least you finished that bunch of dumb goblins.", 25, true)
    game:createTextWindow(jester, "What? Is that the face of someone who can't remember what happened?", 25, true)    
    game:createTextWindow(jester, "Sigh... okay, I'll refresh your memory. The former queen also known as your former wife is in fact a powerful sorcerer.", 25, true)        
    game:createTextWindow(jester, "She poisoned you during your sleep and sent you to rot in this prison. Now the kingdom is a mess.", 25, true)            
    game:createTextWindow(jester, "Dwarfs turning into goblins, elves turning into frogs and a king who can't remember he was a king.", 25, true)                
    game:createTextWindow(jester, "Now I suggest you make haste and head to the castle or else there will not be much of a kingdom left.", 25, true)                    
    game:createTextWindow(jester, "...", 25, true)                        
    game:createTextWindow(jester, "...", 25, true)                        
    game:createTextWindow(jester, "Oops, I think the situation on this kingdom is worse than I imagined.", 25, true)                            
    game:createTextWindow(jester, "Looks like the lazy programmer couldn't script any more of these levels because he had to work on his master's thesis.", 25, true)                                
    game:createTextWindow(jester, "What the hell is a master's thesis? Sigh... there's really no hope for this kingdom... Well, I suppose I should say goodbye for now, thanks for coming and don't forget to bring cookies next time.", 25, true)
    game:returnToMenu()
end
