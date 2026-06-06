#pragma once

#include <raylib.h>
#include "player.hpp"

class Inventory
{
public:
    Inventory();

    void Toggle();
    bool IsOpen() const;

    void Draw(const Player& player) const;

private:
    bool isOpen;
};
