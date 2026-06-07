#pragma once
#include "entities/player.hpp"
#include <raylib.h>

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
