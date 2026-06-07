#include "ui/inventory.hpp"
#include "gear/gear.hpp"
#include "magic/spells.hpp"

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

    const std::vector<GearType>& gear = player.GetInventory();
    const std::vector<SpellType>& spells = player.GetSpells();

    int gearY = 230;

    for(GearType gearType : gear)
    {
        Gear gear = GetGearData(gearType);
        DrawText(gear.name.c_str(), 200, gearY, 24, WHITE);
        gearY += 35;
    }

    int spellY = 470;

    for(SpellType spellType : spells)
    {
        Spell spell = GetSpellData(spellType);
        DrawText(spell.name.c_str(), 200, spellY, 24, WHITE);
        spellY += 35;
    }
}
