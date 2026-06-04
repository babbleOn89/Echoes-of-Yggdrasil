#pragma once
#include <raylib.h>

class Player
{
public:
    Player();

    void HandleInput();
    void Draw(Texture2D sprite, float scale) const;
    void SetPosition(Vector2 newPosition);

    Vector2 GetPosition() const;

private:
    Vector2 position;
    float speed;
    float scale;
};
