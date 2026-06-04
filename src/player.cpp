#include "player.hpp"

Player::Player()
{
    position = {700.0f, 500.0f};
    speed = 3.0f;
    scale = 0.20f;
}

void Player::HandleInput()
{
    if(IsKeyDown(KEY_W)) position.y -= speed;
    if(IsKeyDown(KEY_S)) position.y += speed;
    if(IsKeyDown(KEY_A)) position.x -= speed;
    if(IsKeyDown(KEY_D)) position.x += speed;
}

void Player::Draw(Texture2D sprite, float scale) const
{
    float drawX = position.x - (sprite.width * scale) / 2.0f;
    float drawY = position.y - (sprite.height * scale);

    DrawTextureEx(
            sprite,
            {drawX, drawY},
            0.0f,
            scale,
            WHITE
            );
}

Vector2 Player::GetPosition() const
{
    return position;
}

void Player::SetPosition(Vector2 newPosition)
{
    position = newPosition;
}
