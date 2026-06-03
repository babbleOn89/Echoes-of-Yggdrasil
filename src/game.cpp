#include <raylib.h>
#include <iostream>
#include "game.hpp"

Game::Game()
{
    currentState = INTRO_ROOM;

    introRoom = LoadTexture("assets/world_ui/intro.png");
    characterSelect = LoadTexture("assets/world_ui/title.png");

    brandySprite = LoadTexture("assets/hero/fsprite2.png");
    brandonSprite = LoadTexture("assets/hero/msprite2.png");

    brandonPos = {75.0f, -50.0f};
    brandonTarget = {700.0f, 5.0f};
    brandyPos = {350.0f, 150.0f};

    playerPos = {300.0f, 300.0f};
    playerSpeed = 3.0f;
    
    selectedCharacter = 0;
    chosenCharacter = -1;

    introState = WALK_IN;
    dialogueIndex = 0;
}

Game::~Game()
{
    UnloadTexture(introRoom);
    UnloadTexture(characterSelect);
    UnloadTexture(brandySprite);
    UnloadTexture(brandonSprite);
}

void Game::Update()
{
    if(currentState == INTRO_ROOM)
    {
        if(introState == WALK_IN)
        {
            if(brandonPos.y < 5)
            {
                brandonPos.y += 2.0f;
            }
            else
            {
                introState = WALK_TO_TABLE;
            }
        }

        if(introState == WALK_TO_TABLE)
        {
            if(brandonPos.x < brandonTarget.x)
            {
                brandonPos.x += 2.0f;
            }
            else
            {
                introState = WALK_DOWN;
            }
        }

        if(introState == WALK_DOWN)
        {
            if(brandonPos.y < 150)
            {
                brandonPos.y += 2;
            }
            else
            {
                introState = DIALOGUE;
            }
        }
        
        if(introState == DIALOGUE)
        {
            if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
            {
                dialogueIndex++;

                if(dialogueIndex >= 6)
                {
                    currentState = CHARACTER_SELECT;
                }
            }
        }       
    }
    else if(currentState == CHARACTER_SELECT)
    {
        if(IsKeyPressed(KEY_LEFT))
        {
            selectedCharacter = 0;
        }

        if(IsKeyPressed(KEY_RIGHT))
        {
            selectedCharacter = 1;
        }

        if(IsKeyPressed(KEY_ENTER))
        {
            chosenCharacter = selectedCharacter;
            
            currentState = LOSS_SCENE;
        }
    }
    else if(currentState == LOSS_SCENE)
    {
        if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
        {
            currentState = FARMSTEAD;
        }
    }

    else if(currentState == FARMSTEAD)
    {

    }

}
void Game::Draw()
{
    float brandyScale = 0.25f;
    float brandonScale = 0.25f;

    Vector2 brandyPos = {350.0f, 150.0f};

    if(currentState == INTRO_ROOM)
    {
        DrawTexturePro(
            introRoom,
            Rectangle{0, 0, (float)introRoom.width, (float)introRoom.height},
            Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            Vector2{0, 0},
            0.0f,
            WHITE
        );

        DrawTextureEx(brandySprite, brandyPos, 0.0f, brandyScale, WHITE);
        DrawTextureEx(brandonSprite, brandonPos, 0.0f, brandonScale, WHITE);

        if(introState == DIALOGUE)
        {
            DrawRectangle(100, 600, 1200, 150, BLACK);
            DrawRectangleLines(100, 600, 1200, 150, WHITE);

            if(dialogueIndex == 0)
                DrawText("Brandy: You know, a real viking probably could have lifted that whole "
                        "bag of seed.", 130, 630, 22, WHITE);
            if(dialogueIndex == 1)
                DrawText("Brandon: I can lift a bag of seed! Besides, I'm a Viking no matter "
                        "what, it's our heritage", 130, 630, 22, WHITE);
            if(dialogueIndex == 2)
                DrawText("Brandy: Come to think about it, I've only ever fall "
                        " off of boats", 130, 630, 22, WHITE);
            if(dialogueIndex == 3)
                DrawText("Parent: You two better get to bed. You have a lot to do in the morning!",
                            130, 630, 22, WHITE);
            if(dialogueIndex == 4)
                DrawText("Brandon: Rock, paper, scissors for who has to feed the chickens?",
                            130, 630, 22, WHITE);
            if(dialogueIndex == 5)
                DrawText("Brandy: You're on!", 130, 630, 22, WHITE);
        }
    }
    else if(currentState == CHARACTER_SELECT)
    {
        DrawTexturePro(
            characterSelect,
            Rectangle{0, 0, (float)characterSelect.width, (float)characterSelect.height},
            Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            Vector2{0, 0},
            0.0f,
            WHITE
        );

        if(selectedCharacter == 0)
        {
            DrawRectangleLines(150, 600, 250, 150, BLUE);
        }
        if(selectedCharacter == 1)
        {
            DrawRectangleLines(1000, 600, 250, 150, RED);
        }
    }

    else if(currentState == LOSS_SCENE)
    {
        if(chosenCharacter == 0)
        {
            DrawText("Brandy: aw man!", 130, 630, 22, WHITE);
        }
        else if(chosenCharacter == 1)
        {
            DrawText("Brandon: aw man!", 130, 630, 22, WHITE);
        }
    }

    else if(currentState == FARMSTEAD)
    {
        DrawRectangle(0, 0, 1400, 800, GREEN); 

        if(chosenCharacter == 0)
        {
            DrawTextureEx(brandySprite, playerPos, 0.0f, brandyScale, WHITE);
        }
        else if(chosenCharacter == 1)
        {
            DrawTextureEx(brandonSprite, playerPos, 0.0f, brandonScale, WHITE);
        }
    }
}

void Game::HandleInput()
{
    if(currentState == FARMSTEAD)
    {
        if(IsKeyDown(KEY_W))
        {
            playerPos.y -= playerSpeed;
        }
        else if(IsKeyDown(KEY_S))
        {
            playerPos.y += playerSpeed;
        }
        else if(IsKeyDown(KEY_A))
        {
            playerPos.x -= playerSpeed;
        }
        else if(IsKeyDown(KEY_D))
        {
            playerPos.x += playerSpeed;
        }
    }
}
            
