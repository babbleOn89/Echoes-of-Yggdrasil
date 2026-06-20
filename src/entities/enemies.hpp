#pragma once
#include <raylib.h>

//simple tutorial boss enemy
//handles movement, position, and rendering
class FoxBoss
{
public:
    enum class FoxState
    {
        ENTERING,
        WAITING,
        ATTACKING,
        RETREATING,
        RECOVERING
    };
    
    //trigger to start the fight loop
    void StartFight();
    bool IsWaiting() const;

    //creates a fox at the specified starting position
    FoxBoss(Vector2 startPos);
    
    //update the fox behavior each frame
    void Update(Vector2 playerPos);

    //draw the fox on the screen
    void Draw() const;

    bool IsFightDone() const;

private:
    //Fox's state
    FoxState state;

    //current world position of the fox
    Vector2 position;

    //movement speed in pixels per frame
    float speed;

    //collision and drawing bounds
    Rectangle hitbox;
    
    //fox's attack pattern
    Vector2 retreatPoint;
    int lungesDone;
    float stateTimer;

    //fox's attack loop
    void UpdateEntering();
    void UpdateWaiting();
    void UpdateAttacking(Vector2 playerPos);
    void UpdateRetreating();
    void UpdateRecovering();
};
