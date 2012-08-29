-- GoblinShaman.lua

print("dofile GoblinShaman.lua")

GoblinShaman = {}

function GoblinShaman:setup()
    self:setName("|ff0|Goblin Shaman|fff|")
    self:setTexture(0)
    self:setMaxHealth(4)
    self:setHealth(4)
    self:setToughness(1)
    self:addAttack(Attack:new("Chant", "x", 0))
    self:addAttack(Attack:new("Fireball", "R", 2))
    self:setRangedAttacker(true)
    self:setDefense(Defense:new("R"))
    self:setSize(1)
    self:setWeight(35)    
    self:setActivationRange(5)    
    self:setFaction("Goblin")
end
