#pragma once
#include <string>
#include <raylib.h>

enum class GearType
{
    NONE,
    REALLY_COOL_STICK
};

struct Gear
{
    GearType type = GearType::NONE;
    std::string name = "";
    std::string description = "";
    std::string texturePath = "";;

    Vector2 position = {0.0f, 0.0f};
    Rectangle pickupArea = {0.0f, 0.0f, 0.0f, 0.0f};
    bool pickedUp = false;
};

Gear GetGearData(GearType type);

