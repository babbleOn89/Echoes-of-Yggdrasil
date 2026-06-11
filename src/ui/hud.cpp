#include "ui/hud.hpp"

HUD::HUD()
{
}

void HUD::Draw(int health, int maxHealth, int mana, int maxMana) const
{
    int panelX = 20;
    int panelY = GetScreenHeight() - 175;

    //left panel
    DrawRectangle(panelX, panelY, 320, 155, Fade(BLACK, 0.70f));
    DrawRectangleLines(panelX, panelY, 320, 155, WHITE);

    DrawText("HP", panelX + 15, panelY + 15, 18, WHITE);
    DrawBar(panelX + 100, panelY + 15, 190, 18, health, maxHealth, RED);

    DrawText("MP", panelX + 15, panelY + 45, 18, WHITE);
    DrawBar(panelX + 100, panelY + 45, 190, 18, mana, maxMana, BLUE);
    
    DrawRectangle(panelX + 15, panelY + 85, 48, 48, DARKGRAY);
    DrawRectangleLines(panelX + 15, panelY + 85, 48, 48, WHITE);
    DrawText("WPN", panelX + 20, panelY + 101, 14, WHITE);

    DrawText("ATK", panelX + 80, panelY + 88, 16, WHITE);
    DrawBar(panelX + 120, panelY + 90, 170, 18, 50, 100, ORANGE);
    
    //right spell slots
    DrawSpellSlots();
}

void HUD::DrawBar(int x, int y, int width, int height, int value,
        int maxValue, Color fillColor) const
{
    if(maxValue <= 0)
        return;

    float percent = (float)value / (float)maxValue;

    if(percent < 0.0f)
        percent = 0.0f;

    if(percent > 1.0f)
        percent = 1.0f;

    DrawRectangle(x, y, width, height, DARKGRAY);
    DrawRectangle(x, y, (int)(width * percent), height, fillColor);
    DrawRectangleLines(x, y, width, height, WHITE);
}

void HUD::DrawSpellSlots() const
{
    int baseX = GetScreenWidth() - 170;
    int baseY = GetScreenHeight() - 190;
    int size = 48;
    int gap = 10;

    //Up
    DrawRectangle(baseX + size + gap, baseY, size, size, DARKGRAY);
    DrawRectangleLines(baseX + size + gap, baseY, size, size, WHITE);
    DrawText("^", baseX + size + gap + 17, baseY + 10, 28, WHITE);

    //Left
    DrawRectangle(baseX, baseY + size + gap, size, size, DARKGRAY);
    DrawRectangleLines(baseX, baseY + size + gap, size, size, WHITE);
    DrawText("<", baseX + 16, baseY + size + gap + 10, 28, WHITE);

    //RIGHT
    DrawRectangle(baseX + (size + gap) * 2, baseY + size + gap, size,
            size, DARKGRAY);
    DrawRectangleLines(baseX + (size + gap) * 2, baseY + size + gap,
            size, size, WHITE);
    DrawText(">", baseX + (size + gap) * 2 + 16, baseY + size +
            gap + 10, 28, WHITE);

    //Down
    DrawRectangle(baseX + size + gap, baseY + (size + gap) * 2,
            size, size, DARKGRAY);
    DrawRectangleLines(baseX + size + gap, baseY + (size + gap) * 2,
            size, size, WHITE);
    DrawText("v", baseX + size + gap + 17, baseY + (size + gap) * 2 + 10, 28, WHITE);
}


