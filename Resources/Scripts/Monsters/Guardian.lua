-- Guardian.lua

print("dofile Guardian.lua")

Guardian = {}

function Guardian:setup()
    self:setName("|f8f|Guardian|fff|")
    self:setTexture(12)
    self:setMaxHealth(50)
    self:setHealth(50)
    self:setToughness(3)
    self:addAttack(Attack:new("Guardian's Wrath", "Y", 10))
    self:setDefense(Defense:new("BBB"))
    self:setSize(2)
    self:setWeight(90)    
    self:setActivationRange(8)    
    self:setFaction("Guardian")
end
