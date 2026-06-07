#pragma once
#include "gear/gear.hpp"
#include "magic/spells.hpp"
#include <raylib.h>
#include <vector>

class Player
{
public:
    Player();

    void HandleInput();
    void Draw(Texture2D sprite, float scale) const;

    Vector2 GetPosition() const;
    void SetPosition(Vector2 newPosition);

    void AddGear(GearType item);
    bool HasGear(GearType item) const;
    void EquipGear(GearType gear);
    GearType GetEquippedGear() const;
    const std::vector<GearType>& GetInventory() const;

    void AddSpell(SpellType spell);
    bool HasSpell(SpellType spell) const;
    void EquipSpell(SpellType spell);
    SpellType GetEquippedSpell() const;
    const std::vector<SpellType>& GetSpells() const;

private:
    Vector2 position;
    float speed;
    float scale;

    std::vector<GearType> inventory;
    GearType equippedGear;

    std::vector<SpellType> spellbook;
    SpellType equippedSpell;
};
