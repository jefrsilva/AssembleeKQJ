-- HealingPotion.lua

print("dofile HealingPotion.lua")

HealingPotion = {}

function HealingPotion:setup()
    self:setName("Healing Potion")
    self:setTexture(9)
    self:setType(ITEM_TYPE_CONSUMABLE)
    self:setWeight(0)
    self:setDescription("Recovers 15 health points when consumed.")
end

function HealingPotion:onConsume()
    local healAmount = 15

    local player = game:getPlayer()
    
    local health = player:getHealth()
    local maxHealth = player:getMaxHealth()
    
    if (health < maxHealth) then
        game:healPlayer(healAmount)
        self:setConsumed(true)
    end
end
