#pragma once
#include <string>
#include <raylib.h>

enum class ItemType
{
    NONE,
    REALLY_COOL_STICK
};

struct Item
{
    ItemType type;
    std::string name;
    std::string description;
    std::string texturePath;

    Vector2 position;
    Rectangle pickupArea;
    bool pickedUp;
};

Item GetItemData(ItemType type);

