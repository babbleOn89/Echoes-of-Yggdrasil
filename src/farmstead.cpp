#include "farmstead.hpp"
#include <raymath.h>


Farmstead::Farmstead()
{
    background = LoadTexture("assets/world_ui/farm_one.png");
    brandonSprite = LoadTexture("assets/heros/msprite2.png");
    scaleX = 2.0f;
    scaleY = 1.5f;

    mapWidth = GetScreenWidth() * scaleX;
    mapHeight = GetScreenHeight() * scaleY;

    camera = {0};
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
        };
    camera.target = {700.0f, 500.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

}

Farmstead::~Farmstead()
{
    UnloadTexture(background);
}

void Farmstead::UpdateCamera(Vector2 playerPosition)
{
    camera.target = playerPosition; 
}

void Farmstead::Draw(
        Texture2D playerSprite,
        float playerScale,
        const Player& player
        )
{
    BeginMode2D(camera);

    DrawTexturePro(
            background,
            Rectangle{0, 0, (float)background.width, (float)background.height},
            Rectangle{0, 0, mapWidth, mapHeight},
            Vector2{0, 0},
            0.0f,
            WHITE
            );
    
    player.Draw(playerSprite, playerScale);

    EndMode2D();
}
