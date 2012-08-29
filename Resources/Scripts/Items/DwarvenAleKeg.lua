-- DwarvenAleKeg.lua

print("dofile DwarvenAleKeg.lua")

DwarvenAleKeg = {}

function DwarvenAleKeg:setup()
    self:setName("Dwarven Ale Keg")
    self:setTexture(6)
    self:setType(ITEM_TYPE_OTHER)
    self:setWeight(20)
    self:setDescription("A heavy keg containing dwarven ale.")
end
