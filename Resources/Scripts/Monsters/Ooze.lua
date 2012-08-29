-- Ooze.lua

print("dofile Ooze.lua")

Ooze = {}

function Ooze:setup()
    self:setName("|ff0|Ooze|fff|")
    self:setTexture(1)
    self:setMaxHealth(6)
    self:setHealth(6)
    self:setToughness(1)
    self:addAttack(Attack:new("Tackle", "Wx", 1))
    self:addAttack(Attack:new("Acid attack", "G", 3))
    self:setDefense(Defense:new("Y"))
    self:setSize(1)
    self:setWeight(10)    
    self:setActivationRange(3)    
    self:setFaction("Hostile")
end
