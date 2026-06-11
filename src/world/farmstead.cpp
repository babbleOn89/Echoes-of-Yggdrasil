#include "world/farmstead.hpp"
#include "stats/character_data.hpp"
#include "ui/dialogue.hpp"
#include "ui/controls.hpp"
#include "gear/gear.hpp"
#include <raymath.h>


Farmstead::Farmstead()
{
    background = LoadTexture("assets/world_ui/farm_one.png");
    scaleX = 2.0f;
    scaleY = 1.5f;

    companionPosition = {1900.0f, 350.0f};
    companionTopY = 350.0f;
    companionBottomY = 500.0f;
    companionSpeed = 1.0f;
    companionDirection = 1;

    mapWidth = GetScreenWidth() * scaleX;
    mapHeight = GetScreenHeight() * scaleY;

    tutorialState = TUTORIAL_WASD;
    tutorialTimer = 3.0f;
    playerCanMove = false;

    seedContainerArea = {1120, 345, 100, 50};
    chickumCoopArea = {1700, 213, 1000, 192};

    coolStickTexture = LoadTexture("assets/gear/reallycoolstick.png");
    coolStickPickedUp = false;
    
    seedsTexture = LoadTexture("assets/spells/seeds.png");
    seedsPickedUp = false;

}

Farmstead::~Farmstead()
{
    UnloadTexture(background);
    UnloadTexture(coolStickTexture);
    UnloadTexture(seedsTexture);
}

void Farmstead::UpdateCamera(Vector2 playerPosition)
{
    camera.target = playerPosition; 
}

void Farmstead::Draw(
        Texture2D playerSprite,
        float playerScale,
        Texture2D companionSprite,
        float companionScale,
        const Player& player
        )
{
    DrawTexturePro(
            background,
            Rectangle{0, 0, (float)background.width, (float)background.height},
            Rectangle{0, 0, mapWidth, mapHeight},
            Vector2{0, 0},
            0.0f,
            WHITE
            );
    DrawTextureEx(
            companionSprite,
            companionPosition,
            0.0f,
            companionScale,
            WHITE
            );
    Gear coolStick = GetGearData(GearType::REALLY_COOL_STICK);

    //Debug coords
    //Vector2 pos = player.GetPosition();

    //DrawText(
    //        TextFormat("X: %.0f Y: %.0f", pos.x, pos.y),
    //        pos.x - 50,
    //        pos.y - 100,
    //        50,
    //        SKYBLUE
    //        );

    // stick hitbox debug
    //DrawRectangleLines(
    //        coolStick.pickupArea.x,
    //        coolStick.pickupArea.y,
    //        coolStick.pickupArea.width,
    //        coolStick.pickupArea.height,
    //        RED
    //        );

    // seed hitbox debug
    //DrawCircle(seedContainerArea.x, seedContainerArea.y, 6, RED);

    //DrawRectangleLines(
    //        seedContainerArea.x,
    //        seedContainerArea.y,
    //        seedContainerArea.width,
    //        seedContainerArea.height,
    //        GREEN
    //        );
    
    // interact point debug
    //DrawCircle(
    //        pos.x,
    //        pos.y - 40.0f ,
    //        8,
    //        RED
    //        );

    if(!coolStickPickedUp)
    {
        DrawTextureEx(
                coolStickTexture,
                coolStick.position,
                0.0f,
                0.10f,
                WHITE
                );
    }

    if(!seedsPickedUp)
    {
        DrawTextureEx(
                seedsTexture,
                {1130, 260},
                0.0f,
                0.07f,
                WHITE
                );
    }

    player.Draw(playerSprite, playerScale);
}

void Farmstead::UpdateCompanion()
{
    companionPosition.y += companionSpeed * companionDirection;

    if(companionPosition.y >= companionBottomY)
    {
        companionDirection = -1;
    }

    if(companionPosition.y <= companionTopY)
    {
        companionDirection = 1;
    }
}

void Farmstead::UpdateTutorial(Player& player)
{
    if(tutorialTimer > 0)
    {
        tutorialTimer -= GetFrameTime();
        playerCanMove = tutorialState != TUTORIAL_WASD;
        return;
    }

    playerCanMove = true;

    Vector2 pos = player.GetPosition();

    // Use player's "feet"/center-ish point instead of raw top-left position
    Vector2 interactPoint = {
        pos.x + 20.0f,
        pos.y + 10.0f
    };

    if(tutorialState == TUTORIAL_WASD)
    {
        if(Controls::Up() ||
           Controls::Down() ||
           Controls::Left() ||
           Controls::Right())
        {
            tutorialState = TUTORIAL_GET_SEED;
        }
    }

    else if(tutorialState == TUTORIAL_GET_SEED)
    {
        if(CheckCollisionPointRec(interactPoint, seedContainerArea))
        {
            player.AddSpell(SpellType::SEEDS);
            player.EquipSpell(SpellType::SEEDS);

            tutorialState = TUTORIAL_PICK_UP_SEED;
            tutorialTimer = 3.0f;
        }
    }

    else if(tutorialState == TUTORIAL_PICK_UP_SEED)
    {
        tutorialState = TUTORIAL_STICK;
        tutorialTimer = 5.0f;
    }

    else if(tutorialState == TUTORIAL_STICK)
    {
        if(player.HasGear(GearType::REALLY_COOL_STICK))
        {
            player.EquipGear(GearType::REALLY_COOL_STICK);

            tutorialState = TUTORIAL_SWING_STICK;
            tutorialTimer = 0.3f;
        }
    }

    else if(tutorialState == TUTORIAL_SWING_STICK)
    {
        if(Controls::MeleePressed())
        {
            tutorialState = TUTORIAL_GO_FEED_CHICKUMS;
            tutorialTimer = 2.0f;
        }
    }

    else if(tutorialState == TUTORIAL_GO_FEED_CHICKUMS)
    {
        if(CheckCollisionPointRec(interactPoint, chickumCoopArea))
        {
            tutorialState = TUTORIAL_FEED_CHICKUMS;
            tutorialTimer = 3.0f;
        }
    }

    else if(tutorialState == TUTORIAL_FEED_CHICKUMS)
    {
        if(Controls::SpellUpPressed() &&
           player.GetEquippedSpell() == SpellType::SEEDS)  
        {
            tutorialState = TUTORIAL_DONE;
        }
    }
}

bool Farmstead::CanPlayerMove() const
{
    return playerCanMove;
}

void Farmstead::DrawTutorialUI()
{
    if(tutorialState == TUTORIAL_DONE)
        return;
    int lineIndex = (int) tutorialState;

    Dialogue::DrawBox(Dialogue::tutorialLines[lineIndex]);
}

bool Farmstead::ShouldDrawTutorialUI() const
{
    return tutorialState != TUTORIAL_DONE;
}

void Farmstead::UpdatePickups(Player& player)
{
    Gear coolStick = GetGearData(GearType::REALLY_COOL_STICK);

    if(!coolStickPickedUp &&
            CheckCollisionPointRec(player.GetPosition(), coolStick.pickupArea) &&
            Controls::InteractPressed())
    {
        player.AddGear(GearType::REALLY_COOL_STICK);
        coolStickPickedUp = true;
    }
}

float Farmstead::GetMapWidth() const  { return mapWidth; }

float Farmstead::GetMapHeight() const { return mapHeight; }

