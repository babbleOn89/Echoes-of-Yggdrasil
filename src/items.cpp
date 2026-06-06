#include "items.hpp"

Item GetItemData(ItemType type)
{
    if(type == ItemType::REALLY_COOL_STICK)
    {
        return {
            ItemType::REALLY_COOL_STICK,
            "Really Cool Stick",
            "You found a really cool stick. \n"
            "You just had to pick it up!",
            "assets/items/seed.png",
            {1050.0f, 462.0f},
            {1150.0f, 496.0f, 200.0f, 75.0f},
            false
        };
    }

    return{
        ItemType::NONE,
        "None",
        "No item.",
        ""
    };
}
