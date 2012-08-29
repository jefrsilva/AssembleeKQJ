-- GoblinWorker.lua

print("dofile GoblinWorker.lua")

GoblinWorker = {}

function GoblinWorker:setup()
    self:setName("|ff0|Goblin Worker|fff|")
    self:setTexture(2)
    self:setMaxHealth(3)
    self:setHealth(3)
    self:setToughness(1)
    self:addAttack(Attack:new("Dagger Attack", "Wxx", 1))
    self:setDefense(Defense:new("R"))
    self:setSize(1)
    self:setWeight(35)   
    self:setActivationRange(5)    
    self:setFaction("Goblin")
end
