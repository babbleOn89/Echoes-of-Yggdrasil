#pragma once
#include <raylib.h>
#include <vector>
#include "items.hpp"
#include "magic.hpp"

class Player
{
public:
    Player();

    void HandleInput();
    void Draw(Texture2D sprite, float scale) const;

    Vector2 GetPosition() const;
    void SetPosition(Vector2 newPosition);

    void AddItem(ItemType item);
    bool HasItem(ItemType item) const;
    void EquipItem(ItemType item);
    ItemType GetEquippedItem() const;
    const std::vector<ItemType>& GetInventory() const;

    void AddSpell(SpellType spell);
    bool HasSpell(SpellType spell) const;
    void EquipSpell(SpellType spell);
    SpellType GetEquippedSpell() const;
    const std::vector<SpellType>& GetSpells() const;

private:
    Vector2 position;
    float speed;
    float scale;

    std::vector<ItemType> inventory;
    ItemType equippedItem;

    std::vector<SpellType> spellbook;
    SpellType equippedSpell;
};
