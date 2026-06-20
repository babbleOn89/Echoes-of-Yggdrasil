#pragma once
#include "magic/spells.hpp"
#include "gear/gear.hpp"
#include <raylib.h>
#include <map>

class HUD
{
public:
    HUD();
    ~HUD();

    void Draw(int health, int maxHealth, 
            int mana, int MaxMana, 
            SpellType upSpell, 
            GearType equippedGear) const;

private:
    void DrawBar(int x, int y, int width, int height, int value,
            int MaxValue, Color fillColor) const;
    void DrawSpellSlots(SpellType upSpell) const;

    std::map<SpellType, Texture2D> spellIcons;

    std::map<GearType, Texture2D> gearIcons;

    void DrawWeaponSlot(
            int centerX,
            int centerY,
            int radius,
            GearType equippedGear
            ) const;
};
