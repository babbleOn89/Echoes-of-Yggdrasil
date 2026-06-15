#pragma once
#include <string>

//type of spells the player can learn/equip
enum class SpellType
{
    NONE,
    SEEDS
};

//stores display/data info for a spell
struct Spell
{
    SpellType type;
    std::string name;
    std::string description;
    std::string texturePath;
};

//return the data associated with spell type
Spell GetSpellData(SpellType type);


