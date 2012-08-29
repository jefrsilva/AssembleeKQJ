-- SparkyDagger.lua

print("dofile SparkyDagger.lua")

SparkyDagger = {}

function SparkyDagger:setup()
    self:setName("|ff0|Sparky Dagger|fff|")
    self:setTexture(4)
    self:setType(ITEM_TYPE_SWORD)
    self:addAttack(Attack:new("Y", 0, 3))
    self:setToughness(1)
    self:setDurability(7)
    self:setDelay(2)
    self:setWeight(5)
end
