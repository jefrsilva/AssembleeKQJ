-- ThunderAxe.lua

print("dofile ThunderAxe.lua")

ThunderAxe = {}

function ThunderAxe:setup()
    self:setName("|ff8|Thunder Axe|fff|")
    self:setTexture(5)
    self:setType(ITEM_TYPE_AXE)
    self:addAttack(Attack:new("Yxxx", 4, 2))
    self:setToughness(2)
    self:setDurability(25)
    self:setDelay(2)
    self:setWeight(60)
end
