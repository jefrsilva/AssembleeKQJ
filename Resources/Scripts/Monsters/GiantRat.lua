-- GiantRat.lua

print("dofile GiantRat.lua")

GiantRat = {}

function GiantRat:setup()
    self:setName("|ff0|Giant Rat|fff|")
    self:setTexture(5)
    self:setMaxHealth(4)
    self:setHealth(4)
    self:setToughness(1)
    self:addAttack(Attack:new("Bite", "Wxx", 1))
    self:addAttack(Attack:new("Bite", "W", 2))    
    self:setDefense(Defense:new("W"))
    self:setSize(1)
    self:setWeight(15)
    self:setActivationRange(5)
    self:setFaction("Hostile")
end
