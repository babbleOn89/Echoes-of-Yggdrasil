#include "ui/controls.hpp"
#include "core/game.hpp"
#include "stats/character_data.hpp"
#include <raylib.h>
#include <iostream>

Game::Game()
{
    currentState = INTRO_ROOM;

    introRoom = LoadTexture("assets/world_ui/intro.png");
    characterSelect = LoadTexture("assets/world_ui/char_select.png");

    brandySprite = LoadTexture("assets/hero/fsprite2.png");
    brandonSprite = LoadTexture("assets/hero/msprite2.png");

    chosenCharacter = -1;
    
    camera.Update(player.GetPosition(),
            farmstead.GetMapWidth(), 
            farmstead.GetMapHeight());
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
    }
    else if(currentState == FARMSTEAD)
    {
        farmstead.UpdateTutorial(player);
        farmstead.UpdatePickups(player);
        farmstead.UpdateCompanion();
        camera.Update(
                player.GetPosition(),
                farmstead.GetMapWidth(),
                farmstead.GetMapHeight()
                );
    }
}
void Game::Draw()
{
    if(currentState == INTRO_ROOM)
    {
        introScene.Draw(introRoom, characterSelect, brandySprite, brandonSprite);
    }
    else if(currentState == FARMSTEAD)
    {
        BeginMode2D(camera.Get());

        if(chosenCharacter == 0)
            farmstead.Draw(brandySprite, brandyScale, brandonSprite, brandonScale, player);
        else if(chosenCharacter == 1)
            farmstead.Draw(brandonSprite, brandonScale, brandySprite, brandyScale, player);
        
        EndMode2D();

        hud.Draw(100, 100, 100, 100);

        if(inventory.IsOpen())
        {
            inventory.Draw(player);
        }
        if(farmstead.ShouldDrawTutorialUI())
        {
            farmstead.DrawTutorialUI();
        }
    }
}

void Game::HandleInput()
{
    if(currentState == FARMSTEAD)
    {
        if(Controls::InventoryPressed())
        {
            inventory.Toggle();
        }

        if(inventory.IsOpen())
        {
            //inventory controls
            return;
        }

        if(farmstead.CanPlayerMove())
        {
            player.HandleInput();
        }
    }
}
            
