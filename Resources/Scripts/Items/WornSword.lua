-- WornSword.lua

print("dofile WornSword.lua")

WornSword = {}

function WornSword:setup()
    self:setName("Worn Sword")
    self:setTexture(0)
    self:setType(ITEM_TYPE_SWORD)
    self:addAttack(Attack:new("WWWx", 2, 1))
    self:setToughness(1)
    self:setDurability(15)
    self:setDelay(1)
    self:setWeight(5)
end
