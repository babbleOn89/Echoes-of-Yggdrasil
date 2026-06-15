#include "entities/enemies.hpp"
#include <raymath.h>

FoxBoss::FoxBoss(Vector2 startPos)
{
    position = startPos;
    speed = 2.0f;

    hitbox = {
        position.x,
        position.y,
        80.0f,
        50.0f
    };
}

void FoxBoss::Update(Vector2 playerPos)
{
    //calculate direction from fox to player
    Vector2 direction = Vector2Subtract(playerPos, position);
    
    //avoid normalizing a zero-length vector
    if(Vector2Length(direction) > 0)
    {
        //normalize so movement speed remains constant
        direction = Vector2Normalize(direction);
        
        //move fox toward player
        position.x += direction.x * speed;
        position.y += direction.y * speed;
    }
    
    //keep hitbox aligned with fox position
    hitbox.x = position.x;
    hitbox.y = position.y;
}

void FoxBoss::Draw() const
{
    DrawRectangleRec(hitbox, ORANGE);
    DrawRectangleLinesEx(hitbox, 2, RED);                        
}
