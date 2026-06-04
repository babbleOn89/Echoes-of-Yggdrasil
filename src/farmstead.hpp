#pragma once
#include <raylib.h>
#include "player.hpp"

class Farmstead
{
public:
    Farmstead();
    ~Farmstead();

    void UpdateCamera(Vector2 playerPosition);
    void Draw(Texture2D playerSprite,
            float playerScale, 
            Texture2D companionSprite, 
            float companionScale, 
            const Player& player
            );
    void UpdateCompanion();

private:
    Texture2D background;
    Texture2D brandonSprite;
    Camera2D camera;

    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;

    Vector2 companionPosition;
    float companionTopY;
    float companionBottomY;
    float companionSpeed;
    int companionDirection;
};
