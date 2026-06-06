#include "farmstead.hpp"
#include "character_data.hpp"
#include "dialogue.hpp"
#include "items.hpp"
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

    camera = {0};
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
        };
    camera.target = {700.0f, 500.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    tutorialState = TUTORIAL_WASD;
    tutorialTimer = 3.0f;
    playerCanMove = false;

    seedContainerArea = {1050, 425, 200, 75};
    chickumCoopArea = {1700, 213, 1000, 192};

}

Farmstead::~Farmstead()
{
    UnloadTexture(background);
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
    BeginMode2D(camera);

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
    Item seedBag = GetItemData(ItemType::REALLY_COOL_STICK);

    DrawRectangleLines(
            seedBag.pickupArea.x,
            seedBag.pickupArea.y,
            seedBag.pickupArea.width,
            seedBag.pickupArea.height,
            RED
            );

    DrawCircle(seedBag.position.x, seedBag.position.y, 20, YELLOW);
    
    player.Draw(playerSprite, playerScale);
    
    //Debug coords

    //Vector2 pos = player.GetPosition();

    //DrawText(
    //        TextFormat("X: %.0f Y: %.0f", pos.x, pos.y),
    //        pos.x - 50,
    //        pos.y - 100,
    //        50,
    //        SKYBLUE
    //        );

    EndMode2D();
    
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

void Farmstead::UpdateTutorial(Player& player, bool inventoryOpen)
{
    if(tutorialTimer > 0)
    {
        tutorialTimer -= GetFrameTime();
        playerCanMove = false;
        return;
    }

    playerCanMove = true;

    Vector2 pos = player.GetPosition();

    if(tutorialState == TUTORIAL_WASD)
    {
        if(IsKeyDown(KEY_W) ||
           IsKeyDown(KEY_A) ||
           IsKeyDown(KEY_S) ||
           IsKeyDown(KEY_D))
        {
            tutorialState = TUTORIAL_GET_SEED;
            tutorialTimer = 0.0f;
        }
    }

    else if(tutorialState == TUTORIAL_GET_SEED)
    {
        if(CheckCollisionPointRec(pos, seedContainerArea))
        {
            tutorialState = TUTORIAL_PICK_UP_SEED;
            tutorialTimer = 0.0f;
        }
    }
    else if(tutorialState == TUTORIAL_PICK_UP_SEED)
    {
        
        player.AddSpell(SpellType::SEEDS);
        player.EquipSpell(SpellType::SEEDS);

        tutorialState = TUTORIAL_GO_FEED_CHICKUMS;
        tutorialTimer = 0.0f;
    }
    else if(tutorialState == TUTORIAL_GO_FEED_CHICKUMS)
    {
        if(CheckCollisionPointRec(pos, chickumCoopArea))
        {
            tutorialState = TUTORIAL_FEED_CHICKUMS;
        }
    }
    else if(tutorialState == TUTORIAL_FEED_CHICKUMS)
    {
        if(IsKeyPressed(KEY_UP) &&
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
    
    DrawRectangle(100, 600, 1200, 150, BLACK);
    DrawRectangleLines(100, 600, 1200, 150, WHITE);

    int lineIndex = (int)tutorialState;

    DrawText(
            Dialogue::tutorialLines[lineIndex].c_str(),
            130,
            630,
            24,
            WHITE
            );
}

bool Farmstead::ShouldDrawTutorialUI() const
{
    return tutorialTimer <= 0.0f && tutorialState != TUTORIAL_DONE;
}
