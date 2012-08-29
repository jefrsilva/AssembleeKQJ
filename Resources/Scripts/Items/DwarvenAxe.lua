-- DwarvenAxe.lua

print("dofile DwarvenAxe.lua")

DwarvenAxe = {}

function DwarvenAxe:setup()
    self:setName("Dwarven Axe")
    self:setTexture(13)
    self:setType(ITEM_TYPE_AXE)
    self:addAttack(Attack:new("WWx", 2, 2))
    self:setToughness(1)
    self:setDurability(30)
    self:setDelay(2)
    self:setWeight(8)
end
