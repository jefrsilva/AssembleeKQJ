-- BurningSpear.lua

print("dofile BurningSpear.lua")

BurningSpear = {}

function BurningSpear:setup()
    self:setName("|f88|Burning Spear|fff|")
    self:setTexture(7)
    self:setType(ITEM_TYPE_SPEAR)
    self:addAttack(Attack:new("RRRx", 1, 2))
    self:setToughness(1)
    self:setDurability(20)
    self:setDelay(2)
    self:setWeight(5)
end
