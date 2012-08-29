-- NewGame.lua

dofile("Resources/Scripts/Constants.lua")

-- Item scripts
dofile("Resources/Scripts/Items/CellKey.lua")
dofile("Resources/Scripts/Items/CellNote.lua")
dofile("Resources/Scripts/Items/HealingPotion.lua")
dofile("Resources/Scripts/Items/RustyKey.lua")
dofile("Resources/Scripts/Items/PrisonIronKey.lua")
dofile("Resources/Scripts/Items/RustyDagger.lua")
dofile("Resources/Scripts/Items/WornSword.lua")
dofile("Resources/Scripts/Items/WornShield.lua")
dofile("Resources/Scripts/Items/BurningSpear.lua")
dofile("Resources/Scripts/Items/DwarvenAleKeg.lua")
dofile("Resources/Scripts/Items/ThunderAxe.lua")
dofile("Resources/Scripts/Items/DwarvenAxe.lua")
dofile("Resources/Scripts/Items/Torch.lua")
dofile("Resources/Scripts/Items/ColdShield.lua")
dofile("Resources/Scripts/Items/VitalityPotion.lua")
dofile("Resources/Scripts/Items/MagicPrisonKey.lua")
dofile("Resources/Scripts/Items/SparkyDagger.lua")
  
-- Monster scripts
dofile("Resources/Scripts/Monsters/CaveWorm.lua")
dofile("Resources/Scripts/Monsters/GiantRat.lua")
dofile("Resources/Scripts/Monsters/GoblinWorker.lua")
dofile("Resources/Scripts/Monsters/GoblinWarrior.lua")
dofile("Resources/Scripts/Monsters/GoblinShaman.lua")
dofile("Resources/Scripts/Monsters/Ooze.lua")
dofile("Resources/Scripts/Monsters/GoblinChieftain.lua")
dofile("Resources/Scripts/Monsters/Guardian.lua")
dofile("Resources/Scripts/Monsters/Jester.lua")

-- Setting initial state
game:loadMap("UndergroundPrisonB3F")
game:loadMap("UndergroundPrisonB2F")
game:loadMap("Forest")
game:loadMap("Swamp")
game:loadMap("DarkPassageway1")
game:loadMap("DarkPassageway2")
game:loadMap("TowerB1F")
game:loadMap("Tower1F")
game:loadMap("Tower2F")
game:loadMap("HedgeMaze")

local initialMap = "UndergroundPrisonB3F"
local fadeDuration = 2000

local player = game:getPlayer()
player:setMaxHealth(30)
player:setHealth(30)
player:setFactionStance("Hostile", FACTION_HOSTILE)
player:setFactionStance("Friendly", FACTION_FRIENDLY)
player:setFactionStance("Guardian", FACTION_NEUTRAL)
player:setFactionStance("Goblin", FACTION_HOSTILE)
player:setFactionStance("GoblinSurvivors", FACTION_FRIENDLY)

game:setPlayerLocation(initialMap, 30, 6, 0)
game:fadeInMapMusic(initialMap, fadeDuration)
game:fadeIn(fadeDuration)

game:setGlobalVar("TutorialStage", 0)
game:setGlobalVar("Tutorial2Stage", 0)
game:setGlobalVar("Tutorial3Stage", 0)
game:setGlobalVar("ShieldTutorial", 0)
game:createTutorialWindow("Use the |ff8|arrow keys|fff| or the |ff8|WASDQE keys|fff| to |8f8|move|fff| around the dungeon. Press the |ff8|T key|fff| to toggle the tutorial window.")
