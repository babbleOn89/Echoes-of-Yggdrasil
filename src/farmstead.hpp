#pragma once
#include <raylib.h>
#include "player.hpp"

class Farmstead
{
public:
    Farmstead();
    ~Farmstead();

    void UpdateCamera(Vector2 playerPosition);
    void Draw(Texture2D playerSprite, float playerScale, const Player& player);

private:
    Texture2D background;
    Camera2D camera;

    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;
};
