-- CaveWorm.lua

print("dofile CaveWorm.lua")

CaveWorm = {}

function CaveWorm:setup()
    self:setName("|ff0|Cave Worm|fff|")
    self:setTexture(3)
    self:setMaxHealth(3)
    self:setHealth(3)
    self:setToughness(1)
    self:addAttack(Attack:new("Wait", "x", 0))
    self:addAttack(Attack:new("Bite", "W", 1))    
    self:setDefense(Defense:new("W"))
    self:setSize(1)
    self:setWeight(8)
    self:setActivationRange(5)
    self:setFaction("Hostile")
end
