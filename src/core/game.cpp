#include "ui/controls.hpp"
#include "core/game.hpp"
#include "stats/character_data.hpp"
#include <raylib.h>
#include <iostream>

Game::Game()
{
    currentState = INTRO_ROOM;

    introRoom = LoadTexture("assets/world/intro.png");
    characterSelect = LoadTexture("assets/world/char_select.png");

    brandySprite = LoadTexture("assets/hero/fsprite2.png");
    brandonSprite = LoadTexture("assets/hero/msprite2.png");

    chosenCharacter = -1;

    camera.Update(
            player.GetPosition(),
            farmstead.GetMapWidth(),
            farmstead.GetMapHeight()
            );
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
        introScene.Update();

        if(introScene.IsFinished())
        {
            chosenCharacter = introScene.GetChosenCharacter();
            player.SetPosition({500.0f, 750.0f});
            currentState = FARMSTEAD;
        }

        return;
    }

    if(currentState == FARMSTEAD)
    {
        farmstead.Update(player);

        camera.Update(
                player.GetPosition(),
                farmstead.GetMapWidth(),
                farmstead.GetMapHeight()
                );

        Vector2 playerPos = player.GetPosition();

        if(playerPos.y <= 120.0f)
        {
            player.SetPosition({700.0f, 1200.0f});
            currentState = BOSS_TUTORIAL;
        }

        return;
    }

    if(currentState == BOSS_TUTORIAL)
    {
        meadow.Update(player);

        camera.Update(
                player.GetPosition(),
                1400,
                1200
                );

        return;
    }
}

void Game::Draw()
{
    if(currentState == INTRO_ROOM)
    {
        introScene.Draw(
                introRoom,
                characterSelect,
                brandySprite,
                brandonSprite
                );

        return;
    }

    BeginMode2D(camera.Get());

    if(currentState == FARMSTEAD)
    {
        if(chosenCharacter == 0)
        {
            farmstead.Draw(
                    brandySprite,
                    brandyScale,
                    brandonSprite,
                    brandonScale,
                    player
                    );
        }
        else
        {
            farmstead.Draw(
                    brandonSprite,
                    brandonScale,
                    brandySprite,
                    brandyScale,
                    player
                    );
        }
    }
    else if(currentState == BOSS_TUTORIAL)
    {
        if(chosenCharacter == 0)
        {
            meadow.Draw(
                    brandySprite,
                    brandyScale,
                    brandonSprite,
                    brandonScale,
                    player
                    );
        }
        else
        {
            meadow.Draw(
                    brandonSprite,
                    brandonScale,
                    brandySprite,
                    brandyScale,
                    player
                    );
        }
    }

    EndMode2D();

    hud.Draw(100, 100, 100, 100);

    if(inventory.IsOpen())
    {
        inventory.Draw(player);
    }

    if(currentState == FARMSTEAD &&
       farmstead.ShouldDrawTutorialUI())
    {
        farmstead.DrawTutorialUI();
    }
}

void Game::HandleInput()
{
    if(currentState == INTRO_ROOM)
        return;

    if(Controls::InventoryPressed())
    {
        inventory.Toggle();
    }

    if(inventory.IsOpen())
    {
        // inventory controls later
        return;
    }

    if(currentState == FARMSTEAD)
    {
        if(farmstead.CanPlayerMove())
        {
            player.HandleInput();
        }

        return;
    }

    if(currentState == BOSS_TUTORIAL)
    {
        player.HandleInput();
        return;
    }
}

std::string Game::GetPlayerName() const
{
    if(chosenCharacter == 0)
        return "Brandy";
   
    return "Brandon";
}

std::string Game::GetCompanionName() const
{
    if(chosenCharacter == 0)
        return "Brandon";

    return "Brandy";
}
