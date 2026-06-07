#include "gear/gear.hpp"

Gear GetGearData(GearType type)
{
    if(type == GearType::REALLY_COOL_STICK)
    {
        return {
            GearType::REALLY_COOL_STICK,
            "Really Cool Stick",
            "You found a really cool stick. \n"
            "You just had to pick it up!",
            "assets/gear/reallycoolstick.png",
            {1520.0f, 415.0f},
            {1525.0f, 420.0f, 75.0f, 150.0f},
            false
        };
    }

    return{
        GearType::NONE,
        "None",
        "No item.",
        ""
    };
}
