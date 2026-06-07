#pragma once
#include <string>
#include <raylib.h>

enum class SpellType
{
    NONE,
    SEEDS
};

struct Spell
{
    SpellType type;
    std::string name;
    std::string description;
    std::string texturePath;
};

Spell GetSpellData(SpellType type);


