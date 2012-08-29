-- UndergroundPrisonB3F.lua

print("dofile UndergroundPrisonB3F.lua")

UndergroundPrisonB3F = {}

function UndergroundPrisonB3F:setup() 
    local player
    local door
    local hole
    local item    
    local monster
    local pressureplate
    
    player = game:getPlayer()

    self:setName("Underground Prison B3F")
    self:setMusic("Prison")
    self:setTileset(0)
    
    self:setAmbientLight(0.1, 0.1, 0.1)
    self:setDiffuseLight(1.0, 1.0, 1.0)
    self:setLightParams(0.0, 0.008, 0.008)
    self:setFog(0.0, 0.0, 0.0, 0.025)
    
    -- Cell section 
    monster = game:newMonster("GoblinWorker", "Goblin1")
    monster:addItemDrop("RustyDagger")
    self:addMonster(monster, 22, 3)
    
    item = game:newItem("RustyDagger")
    self:addItem(item, 29, 9)
    
    item = game:newItem("RustyKey")
    self:addItem(item, 29, 9)

    item = game:newItem("HealingPotion")
    self:addItem(item, 29, 9)
    
    item = game:newItem("CellNote")
    player:addItem(item, 0)
    
    door = self:getDoorAt(15, 3)
    door:setLocked(true)
    door:setKey("CellKey")  
    
    monster = game:newMonster("CaveWorm", "")
    self:addMonster(monster, 15, 1)

    monster = game:newMonster("CaveWorm", "")
    self:addMonster(monster, 14, 2)
    
    door = self:getDoorAt(15, 5)
    door:setLocked(true)
    door:setKey("CellKey")    
    
    door = self:getDoorAt(17, 3)
    door:setLocked(true)
    door:setKey("CellKey")    

    door = self:getDoorAt(17, 5)
    door:setLocked(true)
    door:setKey("CellKey")    

    item = game:newItem("HealingPotion")
    self:addItem(item, 18, 7)
    
    door = self:getDoorAt(27, 3)
    door:setLocked(true)
    door:setKey("CellKey")   
    
    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 27, 2)

    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 27, 2)

    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 26, 2)

    item = game:newItem("VitalityPotion")
    self:addItem(item, 26, 1)
    
    door = self:getDoorAt(29, 3)
    door:setLocked(true)
    door:setKey("CellKey")        

    door = self:getDoorAt(27, 5)
    door:setLocked(true)
    door:setKey("CellKey")    

    door = self:getDoorAt(29, 5)
    door:setLocked(true)
    door:setKey("RustyKey")
    
    -- Path to ooze section
    pressureplate = self:getPressurePlateAt(9, 17)
    pressureplate:setWeightThreshold(20)
    pressureplate:setOnActivate("openOozeSectionDoor")
    pressureplate:setOnDeactivate("closeOozeSectionDoor")    
    
    pressureplate = self:getPressurePlateAt(9, 19)
    pressureplate:setWeightThreshold(20)    
    pressureplate:setOnActivate("openOozeSectionDoor")
    pressureplate:setOnDeactivate("closeOozeSectionDoor")    
    
    monster = game:newMonster("CaveWorm", "CaveWorm9")
    self:addMonster(monster, 7, 17)
    
    monster = game:newMonster("GiantRat", "GiantRat3")
    self:addMonster(monster, 7, 20)
    
    -- Rat room
    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 1, 14)

    monster = game:newMonster("GiantRat", "")
    self:addMonster(monster, 1, 14)

    monster = game:newMonster("GiantRat", "GiantRat3")
    self:addMonster(monster, 2, 15)

    monster = game:newMonster("GiantRat", "GiantRat3")
    self:addMonster(monster, 1, 16)

    item = game:newItem("HealingPotion")
    self:addItem(item, 1, 17)
    
    -- Ooze section
    door = self:getDoorAt(11, 18)
    door:setLocked(true)
    
    item = game:newItem("CellKey")
    self:addItem(item, 30, 19)
    
    item = game:newItem("MagicPrisonKey")
    self:addItem(item, 30, 28)
    
    item = game:newItem("HealingPotion")
    self:addItem(item, 2, 20)
    
    hole = self:getHoleAt(24, 19)
    hole:close()    
    
    hole = self:getHoleAt(18, 26)
    hole:close()    
    
    hole = self:getHoleAt(10, 23)
    hole:close()    

    monster = game:newMonster("Ooze", "Ooze1")
    self:addMonster(monster, 2, 25)

    monster = game:newMonster("Ooze", "Ooze2")
    self:addMonster(monster, 8, 22)

    monster = game:newMonster("Ooze", "Ooze3")
    self:addMonster(monster, 10, 27)

    monster = game:newMonster("Ooze", "Ooze4")
    self:addMonster(monster, 15, 23)

    monster = game:newMonster("Ooze", "Ooze5")
    self:addMonster(monster, 20, 21)

    monster = game:newMonster("Ooze", "Ooze6")
    self:addMonster(monster, 21, 26)

    monster = game:newMonster("Ooze", "Ooze7")
    self:addMonster(monster, 25, 26)

    monster = game:newMonster("Ooze", "Ooze8")
    self:addMonster(monster, 26, 22)
    
    monster = game:newMonster("Ooze", "Ooze9")
    self:addMonster(monster, 29, 17)

    monster = game:newMonster("Ooze", "Ooze10")
    self:addMonster(monster, 29, 21)
    
    item = game:newItem("VitalityPotion")
    self:addItem(item, 3, 29)
    
    -- Path to next level
    door = self:getDoorAt(5, 1)
    door:setLocked(true)
    door:setKey("PrisonIronKey")
    
    monster = game:newMonster("GoblinWorker", "Goblin2")
    monster:addItemDrop("RustyDagger")    
    self:addMonster(monster, 21, 8)

    monster = game:newMonster("GoblinWorker", "Goblin3")
    self:addMonster(monster, 26, 13)
    
    monster = game:newMonster("CaveWorm", "CaveWorm5")
    self:addMonster(monster, 6, 6)
    
    monster = game:newMonster("CaveWorm", "CaveWorm6")
    self:addMonster(monster, 8, 4)
    
    monster = game:newMonster("GiantRat", "GiantRat1")
    self:addMonster(monster, 7, 8)
    
    monster = game:newMonster("GiantRat", "GiantRat2")
    self:addMonster(monster, 10, 3)
    
    monster = game:newMonster("GoblinWarrior", "GoblinW2")
    monster:addItemDrop("WornSword")
    self:addMonster(monster, 2, 8)

    -- Cave worm infested room  
    item = game:newItem("WornSword")
    self:addItem(item, 30, 15)

    item = game:newItem("WornShield")
    self:addItem(item, 30, 13)
    
    monster = game:newMonster("CaveWorm", "CaveWorm1")
    self:addMonster(monster, 28, 11)

    monster = game:newMonster("CaveWorm", "CaveWorm2")
    self:addMonster(monster, 30, 12)

    monster = game:newMonster("CaveWorm", "CaveWorm3")
    self:addMonster(monster, 29, 13)

    monster = game:newMonster("CaveWorm", "CaveWorm4")
    self:addMonster(monster, 29, 14)
    
    -- Workers room
    monster = game:newMonster("GoblinWorker", "Goblin4")
    self:addMonster(monster, 13, 15)

    monster = game:newMonster("GoblinWorker", "Goblin5")
    self:addMonster(monster, 15, 15)

    monster = game:newMonster("GoblinWarrior", "GoblinW1")
    monster:addItemDrop("WornSword") 
    monster:addItemDrop("PrisonIronKey")    
    self:addMonster(monster, 9, 14)
    
    item = game:newItem("DwarvenAxe")
    self:addItem(item, 10, 10)
    
    item = game:newItem("Torch")
    self:addItem(item, 19, 15)

    item = game:newItem("HealingPotion")
    self:addItem(item, 19, 15)
end

function UndergroundPrisonB3F:onEnterTile(row, col)
    if row == 2 and col == 11 then
        local destMap = "UndergroundPrisonB2F"
        local fadeDuration = 1000
    
        game:playSound("Stairs")
        game:fadeOutMusic(fadeDuration)
        game:fadeOut(fadeDuration)
        game:setPlayerLocation(destMap, 2, 2, 1)
        game:fadeInMapMusic(destMap, fadeDuration)
        game:fadeIn(fadeDuration)
    elseif row == 29 and col == 7 then        
        game:setPlayerDirection(2)
    elseif row == 29 and col == 5 then
        if (game:getGlobalVar("TutorialStage") == 2) then
            game:clearTutorialWindow()        
        end
    elseif row == 30 and col == 8 then
        if (game:getGlobalVar("TutorialStage") == 1) then
            game:clearTutorialWindow()
        end
    elseif row == 30 and col == 9 then
        UndergroundPrisonB3F:pickUpAndStoreTutorial()
    elseif row == 29 and col == 6 then
        UndergroundPrisonB3F:useItemsTutorial()
    elseif row == 25 and col == 19 then
        local hole = self:getHoleAt(24, 19)
        hole:open()
    elseif row == 17 and col == 26 then
        local hole = self:getHoleAt(18, 26)
        hole:open()
    elseif row == 9 and col == 23 then
        local hole = self:getHoleAt(10, 23)
        hole:open()
    elseif row == 18 and col == 9 then
        UndergroundPrisonB3F:mapTutorial()        
    elseif row == 16 and col == 11 then
        if (game:getGlobalVar("Tutorial2Stage") == 1) then    
            game:setGlobalVar("Tutorial2State", 2)                
            game:clearTutorialWindow()        
        end
    elseif row == 20 and col == 9 then
        if (game:getGlobalVar("Tutorial2Stage") == 1) then  
            game:setGlobalVar("Tutorial2State", 2)                
            game:clearTutorialWindow()        
        end
    elseif row == 9 and col == 18 then
        UndergroundPrisonB3F:pressurePlateTutorial()
    elseif row == 12 and col == 8 then
        UndergroundPrisonB3F:multipleAttacksTutorial1()
    elseif row == 29 and col == 12 then
        UndergroundPrisonB3F:shieldTutorial()
    elseif row == 30 and col == 13 then
        UndergroundPrisonB3F:shieldTutorial()    
    elseif row == 27 and col == 12 then
        if (game:getGlobalVar("ShieldTutorial") == 1) then    
            game:setGlobalVar("ShieldTutorial", 2)        
            game:clearTutorialWindow()        
        end

    end
end

function UndergroundPrisonB3F:onChangeTurn()
    if (game:getGlobalVar("Tutorial3Stage") == 1) then
        UndergroundPrisonB3F:multipleAttacksTutorial2()
    elseif (game:getGlobalVar("Tutorial3Stage") == 2) then
        UndergroundPrisonB3F:multipleAttacksTutorial3()    
    elseif (game:getGlobalVar("Tutorial3Stage") == 3) then
        UndergroundPrisonB3F:multipleAttacksTutorial4()    
    elseif (game:getGlobalVar("Tutorial3Stage") == 4) then
        game:setGlobalVar("Tutorial3Stage", 5)
        game:clearTutorialWindow()
    end

    if (game:getGlobalVar("TutorialStage") == 2) then
        UndergroundPrisonB3F:battleTutorial1()
    elseif (game:getGlobalVar("TutorialStage") == 3) then
        UndergroundPrisonB3F:battleTutorial2()
    elseif (game:getGlobalVar("TutorialStage") == 4) then
        UndergroundPrisonB3F:battleTutorial3()
    elseif (game:getGlobalVar("TutorialStage") == 5) then
        game:setGlobalVar("TutorialStage", 6)
        game:clearTutorialWindow()
    elseif (game:getGlobalVar("TutorialStage") == 6) then
        UndergroundPrisonB3F:battleTutorial4()
    elseif (game:getGlobalVar("TutorialStage") == 7) then
        UndergroundPrisonB3F:battleTutorial5()
    elseif (game:getGlobalVar("TutorialStage") == 8) then
        UndergroundPrisonB3F:battleTutorial6()
    elseif (game:getGlobalVar("TutorialStage") == 9) then
        UndergroundPrisonB3F:battleTutorial7()
    elseif (game:getGlobalVar("TutorialStage") == 10) then
        game:setGlobalVar("TutorialStage", 11)
        game:clearTutorialWindow()
    elseif (game:getGlobalVar("TutorialStage") == 11) then
        UndergroundPrisonB3F:battleTutorial8()
    elseif (game:getGlobalVar("TutorialStage") == 12) then
        UndergroundPrisonB3F:battleTutorial9()
    elseif (game:getGlobalVar("TutorialStage") == 13) then
        UndergroundPrisonB3F:battleTutorial10()
    elseif (game:getGlobalVar("TutorialStage") == 14) then
        game:setGlobalVar("TutorialStage", 15)
        game:clearTutorialWindow()
    elseif (game:getGlobalVar("TutorialStage") == 15) then
        UndergroundPrisonB3F:battleTutorial11()
    elseif (game:getGlobalVar("TutorialStage") == 16) then
        UndergroundPrisonB3F:battleTutorial12()
    elseif (game:getGlobalVar("TutorialStage") == 17) then
        UndergroundPrisonB3F:battleTutorial13()
    elseif (game:getGlobalVar("TutorialStage") == 18) then
        UndergroundPrisonB3F:battleTutorial14()
    elseif (game:getGlobalVar("TutorialStage") == 19) then
        game:setGlobalVar("TutorialStage", 20)
        game:clearTutorialWindow()
    end
end

function UndergroundPrisonB3F:shieldTutorial()
    if (game:getGlobalVar("ShieldTutorial") == 0) then
        game:setGlobalVar("ShieldTutorial", 1)
        game:createTutorialWindow("A shield can be used during your turn by |ff8|right-clicking|fff| on it. When you use a shield, you gain a number of damage reduction points for a specific type of attack specified by the reduction line on the shield tooltip. Unused reduction points disappear after the enemy's turn.")
    end
end

function UndergroundPrisonB3F:multipleAttacksTutorial1()
    if (game:getGlobalVar("Tutorial3Stage") == 0) then
        game:setGlobalVar("Tutorial3Stage", 1)
        game:createTutorialWindow("Some enemies have multiple attacks that are used always in the same order. Multiple attacks are indicated by multiple attack lines on the monster tooltip.")
    end
end

function UndergroundPrisonB3F:multipleAttacksTutorial2()
    if (game:getGlobalVar("Tutorial3Stage") == 1) then
        game:setGlobalVar("Tutorial3Stage", 2)
        local hourglass = string.format("|ff8|%c|fff|", 23)                
        game:createTutorialWindow("You can always see what will be the next attack to be used by a monster by finding the " .. hourglass .. " symbol to the right of the correspondent attack line.")
    end
end

function UndergroundPrisonB3F:multipleAttacksTutorial3()
    if (game:getGlobalVar("Tutorial3Stage") == 2) then
        game:setGlobalVar("Tutorial3Stage", 3)
        game:createTutorialWindow("Some weapons also have multiple attacks. They are indicated in the same way as multiple attacks for monsters.")
    end
end

function UndergroundPrisonB3F:multipleAttacksTutorial4()
    if (game:getGlobalVar("Tutorial3Stage") == 3) then
        game:setGlobalVar("Tutorial3Stage", 4)
        game:createTutorialWindow("If you are low on health, you may |8f8|consume|fff| a healing potion by |ff8|right-clicking|fff| on it.")
    end
end

function UndergroundPrisonB3F:mapTutorial()
    if (game:getGlobalVar("Tutorial2Stage") == 0) then
        game:setGlobalVar("Tutorial2Stage", 1)
        game:createTutorialWindow("You can access the |8f8|map|fff| for the current dungeon level by holding the |ff8|tab key|fff| or by pressing the |ff8|M key|fff|.")
    end
end

function UndergroundPrisonB3F:pressurePlateTutorial()
    if (game:getGlobalVar("Tutorial2Stage") == 1) then
        game:setGlobalVar("Tutorial2Stage", 2)
        game:createTutorialWindow("On the floor to your and left and right there are two pressure plates. Pressure plates are activated by adding enough weight to the plate. You can |8f8|put|fff| items on the plate by picking an item and |ff8|left-clicking|fff| on the plate.")
    end
end

function UndergroundPrisonB3F:pickUpAndStoreTutorial()
    if (game:getGlobalVar("TutorialStage") == 0) then
        game:setGlobalVar("TutorialStage", 1)
        game:createTutorialWindow("|fff|To |8f8|pick up|fff| an item, move the cursor over it and |ff8|left-click|fff|. Move the cursor to a free slot on the bottom of the screen and |ff8|left-click|fff| to |8f8|store|fff| the item for later use. ")
    end
end

function UndergroundPrisonB3F:useItemsTutorial()
    if (game:getGlobalVar("TutorialStage") == 1) then
        game:setGlobalVar("TutorialStage", 2)
        game:createTutorialWindow("Pick up the rusty key from the inventory bar and |ff8|left-click|fff| on the door to |8f8|unlock|fff| it. You may |8f8|drop|fff| the key by |ff8|left-clicking|fff| on the screen without selecting anything.")
    end
end

function UndergroundPrisonB3F:battleTutorial1()
    if (game:getGlobalVar("TutorialStage") == 2) then
        game:setGlobalVar("TutorialStage", 3)
        game:createTutorialWindow("When you enter the |8f8|battle mode|fff| the stone on the bottom left corner of the screen changes its color. In battle mode, you and the enemies take turns until the battle is resolved.")
    end
end

function UndergroundPrisonB3F:battleTutorial2()
    if (game:getGlobalVar("TutorialStage") == 3) then
        game:setGlobalVar("TutorialStage", 4)
        game:createTutorialWindow("If you are near the enemy, pick up your rusty dagger and |ff0|left-click|fff| on the enemy to |8f8|attack|fff|. Your turn should end automatically after the attack resolves.")
    end
end

function UndergroundPrisonB3F:battleTutorial3()
    if (game:getGlobalVar("TutorialStage") == 4) then
        game:setGlobalVar("TutorialStage", 5)
        game:createTutorialWindow("Sometimes you might want to |8f8|end your turn|fff| without taking any actions. In these cases you may use the |ff8|spacebar key|fff| to |8f8|end your turn|fff|.")
    end
end

function UndergroundPrisonB3F:battleTutorial4()
    local map = game:getMap()
    local monster = map:getMonster("Goblin1")

    if (monster == nil and game:getGlobalVar("TutorialStage") == 6) then
        game:setGlobalVar("TutorialStage", 7)
        local attackPattern = string.format("|fff|%c%c|888|%c|fff|", 17, 17, 16)
        game:createTutorialWindow("Move the cursor over a rusty dagger on your inventory. Note the attack line of the rusty dagger tooltip that shows a sequence of symbols and numbers: " .. attackPattern .. " 1(+1).")
    end
end

function UndergroundPrisonB3F:battleTutorial5()
    if (game:getGlobalVar("TutorialStage") == 7) then
        game:setGlobalVar("TutorialStage", 8)
        local whitePattern = string.format("%c", 17)
        local missPattern = string.format("|888|%c|fff|", 16)
        game:createTutorialWindow("The symbol " .. whitePattern .. " means a normal type attack and the symbol " .. missPattern .. " indicates a miss. Since the attack contains two " .. whitePattern .. " and one " .. missPattern .. " the attack has a 2 in 3 chance to hit the enemy and a 1 in 3 chance to miss.")
    end
end

function UndergroundPrisonB3F:battleTutorial6()
    if (game:getGlobalVar("TutorialStage") == 8) then
        game:setGlobalVar("TutorialStage", 9)
        game:createTutorialWindow("The attack damage is given by the numbers: 1(+1). The first number represents the |f88|base damage|fff| caused on a hit. The number in parenthesis indicates the |f88|bonus damage|fff| that is dealt when you perform a |8f8|critical hit|fff|.")
    end
end

function UndergroundPrisonB3F:battleTutorial7()
    if (game:getGlobalVar("TutorialStage") == 9) then
        game:setGlobalVar("TutorialStage", 10)
        game:createTutorialWindow("Enemy's attacks are described in the same way as weapons. The only difference is that the enemies can't perform |8f8|critical hits|fff| so they don't have |f88|bonus damage|fff|.")
    end
end

function UndergroundPrisonB3F:battleTutorial8()
    local map = game:getMap()
    local monster = map:getMonster("Goblin2")

    if (monster == nil and game:getGlobalVar("TutorialStage") == 11) then
        game:setGlobalVar("TutorialStage", 12)
        game:createTutorialWindow("A weapon can be used a finite number of times before it breaks. This is indicated by the weapon durability number. Each successful hit decreases by 1 the durability of the weapon.")
    end
end

function UndergroundPrisonB3F:battleTutorial9()
    if (game:getGlobalVar("TutorialStage") == 12) then
        game:setGlobalVar("TutorialStage", 13)
        game:createTutorialWindow("If a monster's toughness is greater than the weapon toughness, the weapon's durability will be decreased 1 extra point for each point of difference between the monster's toughness and the weapon's toughness.")
    end
end

function UndergroundPrisonB3F:battleTutorial10()
    if (game:getGlobalVar("TutorialStage") == 13) then
        game:setGlobalVar("TutorialStage", 14)
        game:createTutorialWindow("Weapons can only be used again after a number of turns has passed. This is indicated by the delay number that shows how many turns you must wait before using that weapon again.")
    end
end

function UndergroundPrisonB3F:battleTutorial11()
    local map = game:getMap()
    local monster = map:getMonster("Goblin3")

    if (monster == nil and game:getGlobalVar("TutorialStage") == 15) then
        game:setGlobalVar("TutorialStage", 16)
        game:createTutorialWindow("In order to face multiple enemies it is important to know how to perform |8f8|critical hits|fff|. To perform a critical hit, you should hit an enemy with an attack of the same type of the monster's weakness.")
    end
end

function UndergroundPrisonB3F:battleTutorial12()
    if (game:getGlobalVar("TutorialStage") == 16) then
        game:setGlobalVar("TutorialStage", 17)
        game:createTutorialWindow("When you perform a critical hit, you deal bonus damage and you earn the opportunity to act again on the same turn. You may also act again if you manage to kill an enemy.")
    end
end

function UndergroundPrisonB3F:battleTutorial13()
    if (game:getGlobalVar("TutorialStage") == 17) then
        game:setGlobalVar("TutorialStage", 18)
        game:createTutorialWindow("If a monster has more than one weakness symbol, you must hit them in order from left to right. If you fail to hit a weakness, all weaknesses are reset and your turn ends.")
    end
end

function UndergroundPrisonB3F:battleTutorial14()
    if (game:getGlobalVar("TutorialStage") == 18) then
        game:setGlobalVar("TutorialStage", 19)
        game:createTutorialWindow("If you manage to hit all monster's weaknesses in the correct order, that monster will skip its next turn and it will skip the current selected attack.")
    end
end

function UndergroundPrisonB3F:openOozeSectionDoor()
    local pressureplateL
    local pressureplateR
    local openDoor = false

    pressureplateL = self:getPressurePlateAt(9, 17)
    pressureplateR = self:getPressurePlateAt(9, 19)
    if (pressureplateL:isActivated() and pressureplateR:isActivated()) then
        local door
        
        door = self:getDoorAt(11, 18)
        door:open()
    end
end

function UndergroundPrisonB3F:closeOozeSectionDoor()
    local door
    
    door = self:getDoorAt(11, 18)
    door:close()
end
