#pragma once
#include <string>
#include <raylib.h>

//Types of equipment available in the game
enum class GearType
{
    NONE,
    REALLY_COOL_STICK
};

//stores all data associated with a piece of gear
struct Gear
{
    //unique gear identifier
    GearType type = GearType::NONE;

    //display inforation shown to the player
    std::string name = "";
    std::string description = "";

    //texture used dto draw the item in the world
    std::string texturePath = "";
    
    //world position where the item appears
    Vector2 position = {0.0f, 0.0f};

    //area the player must enter to pick up the item
    Rectangle pickupArea = {0.0f, 0.0f, 0.0f, 0.0f};

    //tracks whether the item has been collected
    bool pickedUp = false;
};

//return the data associated with a gear type
Gear GetGearData(GearType type);

