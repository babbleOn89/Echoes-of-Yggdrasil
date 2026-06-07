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
    GearType type;
    std::string name;
    std::string description;
    std::string texturePath;

    Vector2 position;
    Rectangle pickupArea;
    bool pickedUp;
};

Gear GetGearData(GearType type);

