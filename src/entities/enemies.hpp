#pragma once
#include <raylib.h>

//simple tutorial boss enemy
//handles movement, position, and rendering
class FoxBoss
{
public:
    //creates a fox at the specified starting position
    FoxBoss(Vector2 startPos);
    
    //update the fox behavior each frame
    void Update(Vector2 playerPos);

    //draw the fox on the screen
    void Draw() const;

private:
    //current world position of the fox
    Vector2 position;

    //movemeent speed in pixels per frame
    float speed;

    //collision and drawing bounds
    Rectangle hitbox;
};
