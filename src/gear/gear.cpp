#include "gear/gear.hpp"

//return all data associated with a gear type
//used for item names, descriptions, textures, and world placement
Gear GetGearData(GearType type)
{
    if(type == GearType::REALLY_COOL_STICK)
    {
        return {
            GearType::REALLY_COOL_STICK,
            "Really Cool Stick",

            //description shown to the player
            "You found a really cool stick. \n"
            "You just had to pick it up!",

            //texture used for rendering the item
            "assets/gear/reallycoolstick.png",

            //world position
            {1520.0f, 415.0f},

            //pickup collision area
            {1525.0f, 420.0f, 75.0f, 150.0f},
            
            //pickup state
            false
        };
    }

    //fallback value for invalid or missing gear types
    return{
        GearType::NONE,
        "None",
        "No item.",
        ""
    };
}
