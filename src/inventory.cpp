#include "inventory.hpp"
#include "items.hpp"
#include "magic.hpp"

Inventory::Inventory()
{
    isOpen = false;
}

void Inventory::Toggle()
{
    isOpen = !isOpen;
}

bool Inventory::IsOpen() const
{
    return isOpen;
}

void Inventory::Draw(const Player& player) const
{
    if(!isOpen)
        return;

    DrawRectangle(100, 75, 1200, 650, BLACK);
    DrawRectangleLines(100, 75, 1200, 650, WHITE);

    DrawText("INVENTORY", 560, 110, 36, WHITE);

    DrawText("ITEMS", 180, 180, 28, SKYBLUE);
    DrawText("SPELLS", 180, 420, 28, PURPLE);
    DrawText("GEAR", 950, 180, 28, GOLD);

    const std::vector<ItemType>& items = player.GetInventory();
    const std::vector<SpellType>& spells = player.GetSpells();

    int itemY = 230;

    for(ItemType itemType : items)
    {
        Item item = GetItemData(itemType);
        DrawText(item.name.c_str(), 200, itemY, 24, WHITE);
        itemY += 35;
    }

    int spellY = 470;

    for(SpellType spellType : spells)
    {
        Spell spell = GetSpellData(spellType);
        DrawText(spell.name.c_str(), 200, spellY, 24, WHITE);
        spellY += 35;
    }
}
