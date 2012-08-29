-- WornShield.lua

print("dofile WornShield.lua")

WornShield = {}

function WornShield:setup()
    self:setName("Worn Shield")
    self:setTexture(2)
    self:setType(ITEM_TYPE_SHIELD)
    self:addDefense(Defense:new("W", 3))
    self:setDurability(15)
    self:setDelay(2)
    self:setWeight(3)
end
