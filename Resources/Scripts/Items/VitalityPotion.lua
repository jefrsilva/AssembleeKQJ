-- VitalityPotion.lua

print("dofile VitalityPotion.lua")

VitalityPotion = {}

function VitalityPotion:setup()
    self:setName("|ff8|Vitality Potion|fff|")
    self:setTexture(12)
    self:setType(ITEM_TYPE_CONSUMABLE)
    self:setWeight(0)
    self:setDescription("Increases max health by 5 points when consumed.")
end

function VitalityPotion:onConsume()
    local maxHealthIncrease = 5
    
    game:increaseMaxHealth(maxHealthIncrease)
    self:setConsumed(true)
end
