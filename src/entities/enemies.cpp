#include "entities/enemies.hpp"
#include <raymath.h>

FoxBoss::FoxBoss(Vector2 startPos)
{
    state = FoxState::ENTERING;

    position = startPos;
    speed = 2.0f;

    hitbox = {
        position.x,
        position.y,
        80.0f,
        50.0f
    };

    retreatPoint = {800.0f, 600.0f};
    lungesDone = 0;
    stateTimer = 0.0f;
}

void FoxBoss::Update(Vector2 playerPos)
{
    switch(state)
    {
        case FoxState::ENTERING:
            UpdateEntering();
            break;

        case FoxState::WAITING:
            UpdateWaiting();
            break;

        case FoxState::ATTACKING:
            UpdateAttacking(playerPos);
            break;

        case FoxState::RETREATING:
            UpdateRetreating();
            break;

        case FoxState::RECOVERING:
            UpdateRecovering();
            break;
    }


    hitbox.x = position.x;
    hitbox.y = position.y;
}

void FoxBoss::Draw() const
{
    DrawRectangleRec(hitbox, ORANGE);
    DrawRectangleLinesEx(hitbox, 2, RED);                        
}

void FoxBoss::StartFight()
{
    if(state == FoxState::WAITING)
    {
        state = FoxState::ATTACKING;
        stateTimer = 0.0f;
    }
}

bool FoxBoss::IsWaiting() const
{
    return state == FoxState::WAITING;
}

void FoxBoss::UpdateEntering()
{
    Vector2 direction = Vector2Subtract(retreatPoint, position);

    if(Vector2Length(direction) > 5.0f)
    {
        direction = Vector2Normalize(direction);

        position.x += direction.x * speed;
        position.y += direction.y * speed;
    }
    else
    {
        state = FoxState::WAITING;
    }
}

void FoxBoss::UpdateWaiting()
{
}

void FoxBoss::UpdateAttacking(Vector2 playerPos)
{
    Vector2 direction = Vector2Subtract(playerPos, position);

    if(Vector2Length(direction) > 5.0f)
    {
        direction = Vector2Normalize(direction);

        position.x += direction.x * 6.0f;
        position.y += direction.y * 6.0f;
    }

    stateTimer += GetFrameTime();

    if(stateTimer >= 0.35f)
    {
        lungesDone++;
        stateTimer = 0.0f;
        state = FoxState::RETREATING;
    }
}

void FoxBoss::UpdateRetreating()
{
    Vector2 direction = Vector2Subtract(retreatPoint, position);

    if(Vector2Length(direction) > 5.0f)
    {
        direction = Vector2Normalize(direction);

        position.x += direction.x * 4.0f;
        position.y += direction.y * 4.0f;
    }
    
    else
    {
        if(lungesDone >= 3)
        {
            state = FoxState::WAITING;
        }
        else
        {
            state = FoxState::RECOVERING;
            stateTimer = 0.0f;
        }
    }
}

void FoxBoss::UpdateRecovering()
{
    stateTimer += GetFrameTime();

    if(stateTimer >= 0.75f)
    {
        state = FoxState::ATTACKING;
        stateTimer = 0.0f;
    }
}

bool FoxBoss::IsFightDone() const
{
    return lungesDone >= 3 && state == FoxState::WAITING;
}
