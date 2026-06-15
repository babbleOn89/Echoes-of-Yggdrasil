#pragma once
#include "gear/gear.hpp"
#include "magic/spells.hpp"
#include <raylib.h>
#include <vector>

//representes the player character
//handles movement, rendering, inventory, and spell management
class Player
{
public:
    Player();

    //movement and rendering
    void HandleInput();
    void Draw(Texture2D sprite, float scale) const;
    
    //position helpers
    Vector2 GetPosition() const;
    void SetPosition(Vector2 newPosition);
    
    //gear management
    void AddGear(GearType item);
    bool HasGear(GearType item) const;
    void EquipGear(GearType gear);
    GearType GetEquippedGear() const;
    const std::vector<GearType>& GetInventory() const;
    
    //spell management
    void AddSpell(SpellType spell);
    bool HasSpell(SpellType spell) const;
    void EquipSpell(SpellType spell);
    SpellType GetEquippedSpell() const;
    const std::vector<SpellType>& GetSpells() const;

private:
    //player position in world
    Vector2 position;

    //movement speed
    float speed;

    //default sprite scale
    float scale;
    
    //gear inventory and currently equipped item
    std::vector<GearType> inventory;
    GearType equippedGear;
    
    //learned spells and currently equipped spells
    std::vector<SpellType> spellbook;
    SpellType equippedSpell;
};
