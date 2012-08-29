-- CellNote.lua

print("dofile CellNote.lua")

CellNote = {}

function CellNote:setup()
    self:setName("Note")
    self:setTexture(3)
    self:setType(ITEM_TYPE_OTHER)
    self:setWeight(0)
    self:setDescription("Okay, the situation isn't good. I managed to hide some useful items behind an illusionary wall on your cell. Take those items and find a way out. I'll be waiting outside.")
end
