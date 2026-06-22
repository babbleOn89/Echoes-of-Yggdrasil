#include "world/meadow.hpp"
#include "stats/character_data.hpp"
#include "ui/dialogue.hpp"
#include "ui/controls.hpp"
#include "gear/gear.hpp"
#include "magic/spells.hpp"
#include <raymath.h>
#include <iostream>

Meadow::Meadow()
    : fox({800.0f, 600.0f}) // spawn fox in the boss arena
{
    //load meadow background and set world scale
    background = LoadTexture("assets/world/meadow.png");
    scaleX = 1.0f;
    scaleY = 1.5f;
    
    //calculates world dimensions from screen size and scale
    mapWidth = GetScreenWidth() * scaleX;
    mapHeight = GetScreenHeight() * scaleY;

    //start boss encounter
    bossRoomState = FOX_ENCOUNTER;

    bossRoomTimer = 0.0f;
}

Meadow::~Meadow()
{
    UnloadTexture(background);
}

void Meadow::Update(Player& player)
{
    Vector2 playerPos = player.GetPosition();
    
    switch(bossRoomState)
    {
        case FOX_ENCOUNTER:
            UpdateFoxEncounter(player, playerPos);
            break;

        case FOX_FIGHT:
            UpdateFoxFight(player, playerPos);
            break;

        case MAGIC_AWAKENED:
            UpdateMagicAwakened(player);
            break;

        case BYE_FOX:
            UpdateByeFox();
            break;

        case COMPANION_ARRIVES:
            UpdateCompanionArrives(player);
            break;

        case HI_HERMES:
            UpdateHiHermes();
            break;

        case SOME_EXPLAINING:
            UpdateSomeExplaining();
            break;

        case BOSSROOM_END:
            UpdateBossRoomEnd();
            break;
    }

}

void Meadow::Draw(
        Texture2D playerSprite,
        float playerScale,
        Texture2D /*companionSprite*/,
        float /*companionScale*/,
        const Player& player
        )
{
    //draw meadow background stretched to world size
    DrawTexturePro(
            background,
            Rectangle{0, 0, (float)background.width, (float)background.height},
            Rectangle{0,0, mapWidth, mapHeight},
            Vector2{0, 0},
            0.0f,
            WHITE
            );

    //draw player above the background
    player.Draw(playerSprite, playerScale);
    
    //draw the fox boss
    fox.Draw();

    //tempoary chickum
    DrawRectangle(
            850,
            625,
            32,
            32,
            WHITE
            );
}

void Meadow::UpdateFoxEncounter(Player& player, Vector2 playerPos)
{
    (void)player;

    Rectangle triggerArea = {
        700.0f,
        1000.0f,
        200.0f,
        200.0f,
    };

    fox.Update(playerPos);

    if(fox.IsWaiting() && CheckCollisionPointRec(playerPos, triggerArea))
    {
        bossRoomState = FOX_FIGHT;
        bossRoomTimer = 0.0f;
        fox.StartFight();
    }
}
void Meadow::UpdateFoxFight(Player& player, Vector2 playerPos)
{
    (void)player;

    fox.Update(playerPos);

    if(fox.IsFightDone())
    {
        bossRoomState = MAGIC_AWAKENED;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateMagicAwakened(Player& player)
{
    player.AddSpell(SpellType::FLAME);
    player.EquipSpell(SpellType::FLAME);
    bossRoomTimer += GetFrameTime();
    std::cout << "MAGIC AWAKENED!" << std::endl;

    if(bossRoomTimer >= 2.0f)
    {
        bossRoomState = BYE_FOX;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateByeFox()
{
    bossRoomTimer += GetFrameTime();

    //load flame shooting stuff here

    if(bossRoomTimer >= 2.0f)
    {
        bossRoomState = COMPANION_ARRIVES;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateCompanionArrives(Player& player)
{
    (void)player;

    bossRoomTimer += GetFrameTime();

    if(bossRoomTimer >= 2.0f)
    {
        bossRoomState = HI_HERMES;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateHiHermes()
{
    bossRoomTimer += GetFrameTime();

    if(bossRoomTimer >= 2.0f)
    {
        bossRoomState = SOME_EXPLAINING;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateSomeExplaining()
{
    bossRoomTimer += GetFrameTime();

    if(bossRoomTimer >= 3.0f)
    {
        bossRoomState = BOSSROOM_END;
        bossRoomTimer = 0.0f;
    }
}
void Meadow::UpdateBossRoomEnd()
{
  // Nothing yet.
  // Later: return control, transition, or unlock next area.
}
