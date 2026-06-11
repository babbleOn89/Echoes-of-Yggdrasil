#pragma once
#include <raylib.h>

class HUD
{
public:
    HUD();

    void Draw(int health, int maxHealth, int mana, int MaxMana) const;

private:
    void DrawBar(int x, int y, int width, int height, int value,
            int MaxValue, Color fillColor) const;
    void DrawSpellSlots() const;
};
