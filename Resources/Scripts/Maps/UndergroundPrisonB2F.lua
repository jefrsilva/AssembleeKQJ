-- UndergroundPrisonB2F.lua

print("dofile UndergroundPrisonB2F.lua")

UndergroundPrisonB2F = {}

function UndergroundPrisonB2F:setup() 
    local player
    local door
    local item    
    local monster
    local pressureplate

    self:setName("Underground Prison B2F")
    self:setMusic("Prison")
    self:setTileset(0)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.008, 0.008)
    self:setFog(0.0, 0.0, 0.0, 0.025)
    
    game:setGlobalVar("GoblinQuest", 0)
    game:setGlobalVar("UPFinalSectionDoor", 0)
    
    -- First room
    monster = game:newMonster("GoblinShaman", "GoblinS1")
    self:addMonster(monster, 8, 12)
    
    monster = game:newMonster("GoblinShaman", "GoblinS2")
    self:addMonster(monster, 12, 7)
    
    -- Puzzle path
    monster = game:newMonster("GiantRat", "GiantRat1")
    self:addMonster(monster, 1, 16)
    
    item = game:newItem("Torch")
    self:addItem(item, 1, 16)
    
    item = game:newItem("HealingPotion")
    self:addItem(item, 3, 14)
    
    item = game:newItem("WornShield")
    self:addItem(item, 3, 14)
    
    item = game:newItem("VitalityPotion")
    self:addItem(item, 8, 18)
    
    -- Puzzle room
    item = game:newItem("DwarvenAleKeg")
    self:addItem(item, 20, 24)
    
    item = game:newItem("DwarvenAleKeg")
    self:addItem(item, 20, 26)
    
    item = game:newItem("DwarvenAleKeg")
    self:addItem(item, 20, 28)
    
    pressureplate = self:getPressurePlateAt(11, 25)
    pressureplate:setOnActivate("activateFirstPuzzleDoor")
    pressureplate:setOnDeactivate("activateFirstPuzzleDoor")
    
    pressureplate = self:getPressurePlateAt(11, 26)
    pressureplate:setOnActivate("activateFirstPuzzleDoor")
    pressureplate:setOnDeactivate("activateFirstPuzzleDoor")    
    
    pressureplate = self:getPressurePlateAt(11, 27)
    pressureplate:setOnActivate("activateFirstPuzzleDoor")
    pressureplate:setOnDeactivate("activateFirstPuzzleDoor")    
    
    
    pressureplate = self:getPressurePlateAt(12, 25)
    pressureplate:setOnActivate("activateSecondPuzzleDoor")
    pressureplate:setOnDeactivate("activateSecondPuzzleDoor")    
    
    pressureplate = self:getPressurePlateAt(12, 26)
    pressureplate:setOnActivate("activateSecondPuzzleDoor")
    pressureplate:setOnDeactivate("activateSecondPuzzleDoor")        
    
    pressureplate = self:getPressurePlateAt(12, 27)
    pressureplate:setOnActivate("activateSecondPuzzleDoor")
    pressureplate:setOnDeactivate("activateSecondPuzzleDoor")        


    pressureplate = self:getPressurePlateAt(13, 25)
    pressureplate:setOnActivate("activateThirdPuzzleDoor")
    pressureplate:setOnDeactivate("activateThirdPuzzleDoor")        
    
    pressureplate = self:getPressurePlateAt(13, 26)
    pressureplate:setOnActivate("activateThirdPuzzleDoor")
    pressureplate:setOnDeactivate("activateThirdPuzzleDoor")            
    
    pressureplate = self:getPressurePlateAt(13, 27)
    pressureplate:setOnActivate("activateThirdPuzzleDoor")
    pressureplate:setOnDeactivate("activateThirdPuzzleDoor")            

    door = self:getDoorAt(15, 26)
    door:setLocked(true)
    
    door = self:getDoorAt(16, 26)
    door:setLocked(true)

    door = self:getDoorAt(17, 26)
    door:setLocked(true)
    
    -- Guardian room
    monster = game:newMonster("Guardian", "")
    self:addMonster(monster, 28, 27)

    monster = game:newMonster("Guardian", "")
    self:addMonster(monster, 28, 29)
    
    pressureplate = self:getPressurePlateAt(30, 28)
    pressureplate:setState(true)
    pressureplate:setWeightThreshold(59)
    pressureplate:setOnActivate("deactivateGuardians")
    pressureplate:setOnDeactivate("activateGuardians")
    
    item = game:newItem("ThunderAxe")
    self:addItem(item, 30, 28)

    item = game:newItem("VitalityPotion")
    self:addItem(item, 28, 22)
    
    -- Spear room
    monster = game:newMonster("GoblinWarrior", "GoblinW2")
    self:addMonster(monster, 3, 27)

    monster = game:newMonster("GoblinWarrior", "GoblinW3")
    self:addMonster(monster, 3, 29)
    
    item = game:newItem("BurningSpear")
    self:addItem(item, 2, 28)

    -- Main path
    monster = game:newMonster("GoblinShaman", "GoblinS3")
    self:addMonster(monster, 13, 3)
    
    monster = game:newMonster("GoblinWarrior", "GoblinW1")
    monster:addItemDrop("WornSword")
    self:addMonster(monster, 13, 3)
    
    -- Large section
    pressureplate = self:getPressurePlateAt(15, 20)
    pressureplate:setOnActivate("activateLargeSectionPuzzle1")
    pressureplate:setOnDeactivate("deactivateLargeSectionPuzzle1")
    
    pressureplate = self:getPressurePlateAt(19, 20)
    pressureplate:setOnActivate("activateLargeSectionPuzzle2")
    pressureplate:setOnDeactivate("deactivateLargeSectionPuzzle2")

    pressureplate = self:getPressurePlateAt(19, 22)
    pressureplate:setOnActivate("activateLargeSectionPuzzle3")
    pressureplate:setOnDeactivate("deactivateLargeSectionPuzzle3")
    
    monster = game:newMonster("GoblinShaman", "GoblinS4")
    self:addMonster(monster, 16, 16)
    
    monster = game:newMonster("GoblinWorker", "Goblin1")
    monster:addItemDrop("RustyDagger")    
    self:addMonster(monster, 10, 16)

    monster = game:newMonster("GoblinWorker", "Goblin2")
    self:addMonster(monster, 14, 12)

    monster = game:newMonster("GoblinWorker", "Goblin3")
    monster:addItemDrop("RustyDagger")
    self:addMonster(monster, 17, 13)

    monster = game:newMonster("GoblinWorker", "Goblin4")
    self:addMonster(monster, 21, 17)

    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 27, 14)

    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 28, 15)
    
    monster = game:newMonster("GoblinShaman", "")
    monster:addItemDrop("HealingPotion")
    self:addMonster(monster, 29, 15)

    item = game:newItem("ColdShield")
    self:addItem(item, 24, 22)
    
    -- Old storage section
    monster = game:newMonster("GoblinShaman", "GoblinS1")
    monster:addItemDrop("HealingPotion")
    self:addMonster(monster, 26, 22)
    
    -- Final section
    door = self:getDoorAt(21, 9)
    door:setLocked(true)

    door = self:getDoorAt(28, 9)
    door:setKey("MagicPrisonKey")
    door:setLocked(true)
    
    pressureplate = self:getPressurePlateAt(30, 1)
    pressureplate:setOnActivate("openFinalSectionDoor")
    pressureplate:setOnDeactivate("closeFinalSectionDoor")
    
    pressureplate = self:getPressurePlateAt(30, 2)
    pressureplate:setOnActivate("openFinalSectionDoor")
    pressureplate:setOnDeactivate("closeFinalSectionDoor")
    
    pressureplate = self:getPressurePlateAt(30, 3)
    pressureplate:setOnActivate("openFinalSectionDoor")
    pressureplate:setOnDeactivate("closeFinalSectionDoor")
    
    monster = game:newMonster("GoblinChieftain", "GoblinC1")
    monster:setFaction("GoblinSurvivors")
    self:addMonster(monster, 27, 9)
    
    monster = game:newMonster("GoblinWarrior", "")
    monster:addItemDrop("WornSword")
    monster:setFaction("GoblinSurvivors")
    self:addMonster(monster, 27, 8)

    monster = game:newMonster("GoblinWorker", "")
    monster:setFaction("GoblinSurvivors")
    self:addMonster(monster, 27, 8)
    
    monster = game:newMonster("GoblinWarrior", "")
    monster:setFaction("GoblinSurvivors")
    self:addMonster(monster, 27, 10)

    monster = game:newMonster("GoblinShaman", "")
    monster:addItemDrop("HealingPotion")
    monster:setFaction("GoblinSurvivors")
    self:addMonster(monster, 27, 10)
end

function UndergroundPrisonB2F:onEnterTile(row, col)
    if row == 2 and col == 1 then
        local destMap = "UndergroundPrisonB3F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 2, 10, 3)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 30 and col == 9 then
        local destMap = "Forest"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 29, 6, 0)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 26 and col == 9 then
        UndergroundPrisonB2F:goblinChieftainTalk()
    end
end

function UndergroundPrisonB2F:onChangeTurn()

end

function UndergroundPrisonB2F:activateGuardians()
    local player = game:getPlayer()
    player:setFactionStance("Guardian", FACTION_HOSTILE)
end

function UndergroundPrisonB2F:deactivateGuardians()
    local player = game:getPlayer()
    player:setFactionStance("Guardian", FACTION_NEUTRAL)
end

function UndergroundPrisonB2F:activateLargeSectionPuzzle1()
    local hole = self:getHoleAt(18, 20)
    hole:close()
end

function UndergroundPrisonB2F:deactivateLargeSectionPuzzle1()
    local hole = self:getHoleAt(18, 20)
    hole:open()
end

function UndergroundPrisonB2F:activateLargeSectionPuzzle2()
    local hole = self:getHoleAt(16, 22)
    hole:close()
end

function UndergroundPrisonB2F:deactivateLargeSectionPuzzle2()
    local hole = self:getHoleAt(16, 22)
    hole:open()
end

function UndergroundPrisonB2F:activateLargeSectionPuzzle3()
    local hole = self:getHoleAt(21, 19)
    hole:close()
end

function UndergroundPrisonB2F:deactivateLargeSectionPuzzle3()
    local hole = self:getHoleAt(21, 19)
    hole:open()
end

function UndergroundPrisonB2F:openFinalSectionDoor()
    local door = self:getDoorAt(21, 9)
    local pressureplate1 = self:getPressurePlateAt(30, 1)
    local pressureplate2 = self:getPressurePlateAt(30, 2)
    local pressureplate3 = self:getPressurePlateAt(30, 3)    
    
    if (game:getGlobalVar("UPFinalSectionDoor") == 0) then
        if (pressureplate1:isActivated() and
            not pressureplate2:isActivated() and
            not pressureplate3:isActivated()) then
            game:playSound("PuzzleStep")            
            game:setGlobalVar("UPFinalSectionDoor", 1)
        else
            UndergroundPrisonB2F:closeFinalSectionDoor()        
        end
    elseif (game:getGlobalVar("UPFinalSectionDoor") == 1) then
        if (pressureplate1:isActivated() and
            not pressureplate2:isActivated() and
            pressureplate3:isActivated()) then
            game:playSound("PuzzleStep")                        
            game:setGlobalVar("UPFinalSectionDoor", 2)
        else
            UndergroundPrisonB2F:closeFinalSectionDoor()        
        end
    elseif (game:getGlobalVar("UPFinalSectionDoor") == 2) then
        if (pressureplate1:isActivated() and
            pressureplate2:isActivated() and
            pressureplate3:isActivated()) then
            game:playSound("PuzzleSuccess")                        
            game:setGlobalVar("UPFinalSectionDoor", 3)
            
            door:open()
        else
            UndergroundPrisonB2F:closeFinalSectionDoor()        
        end
    end
end

function UndergroundPrisonB2F:closeFinalSectionDoor()
    local map = game:getMap()
    local door = map:getDoorAt(21, 9)
    local pressureplate1 = map:getPressurePlateAt(30, 1)
    local pressureplate2 = map:getPressurePlateAt(30, 2)
    local pressureplate3 = map:getPressurePlateAt(30, 3)    
    
    local puzzleState = 0
    if (pressureplate1:isActivated()) then
        puzzleState = puzzleState - 1
    end
    if (pressureplate2:isActivated()) then
        puzzleState = puzzleState - 1
    end
    if (pressureplate3:isActivated()) then
        puzzleState = puzzleState - 1
    end
    
    door:close()
    game:playSound("PuzzleFail")
    game:setGlobalVar("UPFinalSectionDoor", puzzleState)
end

function UndergroundPrisonB2F:goblinChieftainTalk()
    local goblinQuest = game:getGlobalVar("GoblinQuest")
    local map = game:getMap()
    local chieftain = map:getMonster("GoblinC1")
    
    if (chieftain ~= nil and goblinQuest == 0) then
        game:setPlayerDirection(2)
        game:pause()
        game:createTextWindow(chieftain, "Wait! We don't want to fight. You are strong and we are weak, we only ask for help.", 25, true)
        game:createTextWindow(chieftain, "Goblins dig everyday but one day we dig too much and we find the oozies home. Our boss stay and fight the oozies but they are many and we are few.", 25, true)
        game:createTextWindow(chieftain, "We close the tunnel while boss fight but we goblins are stupid and forget to take the boss key. Now are we can't leave and we have no more food.", 25, true)
        game:createTextWindow(chieftain, "You are strong, you fight oozies and get key to the exit. We give you sparky dagger to fight the oozies.", 25, true)
        game:createTextWindow(chieftain, "Go back deep and open closed tunnel. Don't forget to take heavy thingies to open tunnel.", 25, true)        
        
        local item = game:newItem("SparkyDagger")
        game:playerGiveItem(item)
        
        game:resume()
        game:setGlobalVar("GoblinQuest", 1)
    elseif (chieftain ~= nil and goblinQuest == 1 and not game:playerHasItem("MagicPrisonKey")) then
        game:setPlayerDirection(2)
        game:pause()
        game:createTextWindow(chieftain, "Do you fight oozies already?", 25, true)        
        game:createTextWindow(chieftain, "Then go back deep and open closed tunnel. Don't forget to take heavy thingies to open tunnel.", 25, true)        
        game:resume()
    elseif (chieftain ~= nil and goblinQuest == 1 and game:playerHasItem("MagicPrisonKey")) then        
        game:setPlayerDirection(2)
        game:pause()
        game:createTextWindow(chieftain, "You kill oozies and find boss key! Now we are strong and many and you are weak and few. Now goblins eat you and take key!", 25, true)        
        
        local player = game:getPlayer()
        player:setFactionStance("GoblinSurvivors", FACTION_HOSTILE)
        game:resume()
        
        local map = game:getMap()
        local door = map:getDoorAt(21, 9)
        door:close()
        
        game:setGlobalVar("GoblinQuest", 2)        
    end
end

function UndergroundPrisonB2F:activateFirstPuzzleDoor()
    local door = self:getDoorAt(15, 26)
    local pressureplate1 = self:getPressurePlateAt(11, 25)    
    local pressureplate2 = self:getPressurePlateAt(11, 26)    
    local pressureplate3 = self:getPressurePlateAt(11, 27)    

    local targetValue = 2
    
    local currentValue = 0
    if (pressureplate1:isActivated()) then
        currentValue = currentValue + 1
    end

    if (pressureplate2:isActivated()) then
        currentValue = currentValue + 2
    end

    if (pressureplate3:isActivated()) then
        currentValue = currentValue + 4
    end

    if (currentValue == targetValue) then
        door:open()
    else 
        door:close()
    end
end

function UndergroundPrisonB2F:activateSecondPuzzleDoor()
    local door = self:getDoorAt(16, 26)
    local pressureplate1 = self:getPressurePlateAt(12, 25)    
    local pressureplate2 = self:getPressurePlateAt(12, 26)    
    local pressureplate3 = self:getPressurePlateAt(12, 27)    

    local targetValue = 3
    
    local currentValue = 0
    if (pressureplate1:isActivated()) then
        currentValue = currentValue + 1
    end

    if (pressureplate2:isActivated()) then
        currentValue = currentValue + 2
    end

    if (pressureplate3:isActivated()) then
        currentValue = currentValue + 4
    end

    if (currentValue == targetValue) then
        door:open()
    else 
        door:close()
    end
end

function UndergroundPrisonB2F:activateThirdPuzzleDoor()
    local door = self:getDoorAt(17, 26)
    local pressureplate1 = self:getPressurePlateAt(13, 25)    
    local pressureplate2 = self:getPressurePlateAt(13, 26)    
    local pressureplate3 = self:getPressurePlateAt(13, 27)    

    local targetValue = 6
    
    local currentValue = 0
    if (pressureplate1:isActivated()) then
        currentValue = currentValue + 1
    end

    if (pressureplate2:isActivated()) then
        currentValue = currentValue + 2
    end

    if (pressureplate3:isActivated()) then
        currentValue = currentValue + 4
    end

    if (currentValue == targetValue) then
        door:open()
    else 
        door:close()
    end
end

