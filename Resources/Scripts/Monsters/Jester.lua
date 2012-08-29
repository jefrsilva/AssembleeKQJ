-- Jester.lua

print("dofile Jester.lua")

Jester = {}

function Jester:setup()
    self:setName("|f8f|Jester|fff|")
    self:setTexture(7)
    self:setMaxHealth(25)
    self:setHealth(25)
    self:setToughness(1)
    self:addAttack(Attack:new("Juggling", "WRGBYx", 3))
    self:setRangedAttacker(true)
    self:setDefense(Defense:new("WRGBY"))
    self:setSize(1)
    self:setWeight(35)    
    self:setActivationRange(5)    
    self:setFaction("Friendly")
end
