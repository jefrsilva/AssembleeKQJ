-- GoblinWarrior.lua

print("dofile GoblinWarrior.lua")

GoblinWarrior = {}

function GoblinWarrior:setup()
    self:setName("|ff0|Goblin Warrior|fff|")
    self:setTexture(4)
    self:setMaxHealth(6)
    self:setHealth(6)
    self:setToughness(2)
    self:addAttack(Attack:new("Sword Attack", "WWx", 2))
    self:setDefense(Defense:new("RR"))
    self:setSize(1)
    self:setWeight(35)    
    self:setActivationRange(5)    
    self:setFaction("Goblin")
end
