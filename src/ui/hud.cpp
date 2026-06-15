#include "ui/hud.hpp"

HUD::HUD()
{
}

void HUD::Draw(int health, int maxHealth, int mana, int maxMana) const
{
    //position main HUD panel near bottom-left of screen
    int panelX = 20;
    int panelY = GetScreenHeight() - 175;

    //main status panel background
    DrawRectangle(panelX, panelY, 320, 155, Fade(BLACK, 0.70f));
    DrawRectangleLines(panelX, panelY, 320, 155, WHITE);
    
    //health bar
    DrawText("HP", panelX + 15, panelY + 15, 18, WHITE);
    DrawBar(panelX + 100, panelY + 15, 190, 18, health, maxHealth, RED);
    
    //mana bar
    DrawText("MP", panelX + 15, panelY + 45, 18, WHITE);
    DrawBar(panelX + 100, panelY + 45, 190, 18, mana, maxMana, BLUE);
    
    //equipped weapon slot placeholder
    DrawRectangle(panelX + 15, panelY + 85, 48, 48, DARKGRAY);
    DrawRectangleLines(panelX + 15, panelY + 85, 48, 48, WHITE);
    DrawText("WPN", panelX + 20, panelY + 101, 14, WHITE);
    
    //temporary attack bar placeholder
    DrawText("ATK", panelX + 80, panelY + 88, 16, WHITE);
    DrawBar(panelX + 120, panelY + 90, 170, 18, 50, 100, ORANGE);
    
    //Spell slots are drawn separately on the right side
    DrawSpellSlots();
}

void HUD::DrawBar(int x, int y, int width, int height, int value,
        int maxValue, Color fillColor) const
{
    //avoid dividing by zero
    if(maxValue <= 0)
        return;
    //convert current value into a 0.0-1.0 percentage
    float percent = (float)value / (float)maxValue;
    
    //clamp percentage so the bar never draws outside its bounds
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
    //starting position for diamond-shaped arrow spell layout
    int baseX = GetScreenWidth() - 170;
    int baseY = GetScreenHeight() - 190;
    int size = 48;
    int gap = 10;

    //up
    DrawRectangle(baseX + size + gap, baseY, size, size, DARKGRAY);
    DrawRectangleLines(baseX + size + gap, baseY, size, size, WHITE);
    DrawText("^", baseX + size + gap + 17, baseY + 10, 28, WHITE);

    //left
    DrawRectangle(baseX, baseY + size + gap, size, size, DARKGRAY);
    DrawRectangleLines(baseX, baseY + size + gap, size, size, WHITE);
    DrawText("<", baseX + 16, baseY + size + gap + 10, 28, WHITE);

    //right
    DrawRectangle(baseX + (size + gap) * 2, baseY + size + gap, size,
            size, DARKGRAY);
    DrawRectangleLines(baseX + (size + gap) * 2, baseY + size + gap,
            size, size, WHITE);
    DrawText(">", baseX + (size + gap) * 2 + 16, baseY + size +
            gap + 10, 28, WHITE);

    //down
    DrawRectangle(baseX + size + gap, baseY + (size + gap) * 2,
            size, size, DARKGRAY);
    DrawRectangleLines(baseX + size + gap, baseY + (size + gap) * 2,
            size, size, WHITE);
    DrawText("v", baseX + size + gap + 17, baseY + (size + gap) * 2 + 10, 28, WHITE);
}


