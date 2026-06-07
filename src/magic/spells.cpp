#include "magic/spells.hpp"

Spell GetSpellData(SpellType type)
{
    if(type == SpellType::SEEDS)
    {
        return {
            SpellType::SEEDS,
            "Seeds",
            "A small bag of chicken feed.",
            "assets/items/seeds.png",
        };
    }

    return{
        SpellType::NONE,
        "None",
        "No item.",
        ""
    };
}
