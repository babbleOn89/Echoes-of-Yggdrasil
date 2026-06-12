#include "world/bosstutorial.hpp"
#include "stats/character_data.hpp"
#include "ui/dialogue.hpp"
#include "ui/controls.hpp"
#include "gear/gear.hpp"
#include <raymath.h>

Meadow::Meadow()
{
    background = LoadTexture("assets/world/meadow.png");
    scaleX = 1.0f;
    scaleY = 1.5f;

    mapWidth = GetScreenWidth() * scaleX;
    mapHeight = GetScreenHeight() * scaleY;

   bossRoomState = FOX_ENCOUNTER;

}

Meadow::~Meadow()
{
    UnloadTexture(background);
}

void Meadow::Update(Player& player)
{
    //add the enum stuff later
}

void Meadow::Draw(
        Texture2D playerSprite,
        float playerScale,
        Texture2D companionSprite,
        float companionScale,
        const Player& player
        )
{
    DrawTexturePro(
            background,
            Rectangle{0, 0, (float)background.width, (float)background.height},
            Rectangle{0,0, mapWidth, mapHeight},
            Vector2{0, 0},
            0.0f,
            WHITE
            );
    player.Draw(playerSprite, playerScale);

    DrawRectangle(
            800,
            600,
            64,
            64,
            RED
            );
    
    DrawRectangle(
            850,
            625,
            32,
            32,
            WHITE
            );
}
