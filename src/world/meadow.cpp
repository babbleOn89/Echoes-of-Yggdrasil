#include "world/meadow.hpp"
#include "stats/character_data.hpp"
#include "ui/dialogue.hpp"
#include "ui/controls.hpp"
#include "gear/gear.hpp"
#include <raymath.h>

Meadow::Meadow()
    : fox({800.0f, 600.0f}) // spawn fox in the boss arena
{
    //load meadow background and set world scale
    background = LoadTexture("assets/world/meadow.png");
    scaleX = 1.0f;
    scaleY = 1.5f;
    
    //calculates world dimensions from screen size and scale
    mapWidth = GetScreenWidth() * scaleX;
    mapHeight = GetScreenHeight() * scaleY;

    //start boss encounter
    bossRoomState = FOX_ENCOUNTER;

}

Meadow::~Meadow()
{
    UnloadTexture(background);
}

void Meadow::Update(Player& player)
{
    //temporary behavior: "fox" tracks the player every frame
    //boss state logic will control this later
    fox.Update(player.GetPosition());
}

void Meadow::Draw(
        Texture2D playerSprite,
        float playerScale,
        Texture2D /*companionSprite*/,
        float /*companionScale*/,
        const Player& player
        )
{
    //draw meadow background stretched to world size
    DrawTexturePro(
            background,
            Rectangle{0, 0, (float)background.width, (float)background.height},
            Rectangle{0,0, mapWidth, mapHeight},
            Vector2{0, 0},
            0.0f,
            WHITE
            );

    //draw player above the background
    player.Draw(playerSprite, playerScale);
    
    //draw the fox boss
    fox.Draw();

    //tempoary chickum
    DrawRectangle(
            850,
            625,
            32,
            32,
            WHITE
            );
}
