#include "magic/spells.hpp"

//return all data associated with a spell
//used for spell names, descriptions, and textures
//basically "gear" but *magic*
Spell GetSpellData(SpellType type)
{
    if(type == SpellType::SEEDS)
    {
        return {
            SpellType::SEEDS,

            //display name shown in menus
            "Seeds",

            //description shown to player
            "A small bag of chicken feed.",

            //spell icon texture
            "assets/spells/seeds.png",
        };
    }

    if(type == SpellType::FLAME)
    {
        return {
            SpellType::FLAME,
            "FLAME",
            "Ancient Gandyr Flame Awakens",
            "assets/spells/flame.png",
        };
    }
    
    //fallback value for invalid spell types
    return {
        SpellType::NONE,
        "None",
        "No item.",
        ""
    };
}
