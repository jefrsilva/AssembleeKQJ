-- GoblinChieftain.lua

print("dofile GoblinChieftain.lua")

GoblinChieftain = {}

function GoblinChieftain:setup()
    self:setName("|ff0|Goblin Chieftain|fff|")
    self:setTexture(6)
    self:setMaxHealth(20)
    self:setHealth(20)
    self:setToughness(1)
    self:addAttack(Attack:new("Chant", "x", 0))
    self:addAttack(Attack:new("Fireball", "Rxx", 2))
    self:addAttack(Attack:new("Fireball", "RRx", 3))    
    self:setRangedAttacker(true)
    self:setDefense(Defense:new("R"))
    self:setSize(1)
    self:setWeight(35)    
    self:setActivationRange(5)    
    self:setFaction("Goblin")
end
