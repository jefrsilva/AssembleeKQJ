-- Torch.lua

print("dofile Torch.lua")

Torch = {}

function Torch:setup()
    self:setName("Torch")
    self:setTexture(10)
    self:setType(ITEM_TYPE_SWORD)
    self:addAttack(Attack:new("RRx", 0, 1))
    self:setToughness(1)
    self:setDurability(10)
    self:setDelay(1)
    self:setWeight(3)
end
