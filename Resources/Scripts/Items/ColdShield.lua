-- ColdShield.lua

print("dofile ColdShield.lua")

ColdShield = {}

function ColdShield:setup()
    self:setName("Cold Shield")
    self:setTexture(11)
    self:setType(ITEM_TYPE_SHIELD)
    self:addDefense(Defense:new("R", 4))
    self:setDurability(20)
    self:setDelay(2)
    self:setWeight(5)
end
