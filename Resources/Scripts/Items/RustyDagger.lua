-- RustyDagger.lua

print("dofile RustyDagger.lua")

RustyDagger = {}

function RustyDagger:setup()
    self:setName("Rusty Dagger")
    self:setTexture(8)
    self:setType(ITEM_TYPE_SWORD)
    self:addAttack(Attack:new("WWx", 1, 1))
    self:setToughness(1)
    self:setDurability(15)
    self:setDelay(1)
    self:setWeight(2)
end
