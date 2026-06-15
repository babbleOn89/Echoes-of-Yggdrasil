#pragma once
#include "entities/player.hpp"
#include <raylib.h>

//handles inventory display and visibility
class Inventory
{
public:
    Inventory();

    void Toggle();
    bool IsOpen() const;

    void Draw(const Player& player) const;

private:
    //tracks whether the inventory window is open
    bool isOpen;
};
