#include <raylib.h>
#include <iostream>
#include "game.hpp"
#include "character_data.hpp"

Game::Game()
{
    currentState = INTRO_ROOM;

    introRoom = LoadTexture("assets/world_ui/intro.png");
    characterSelect = LoadTexture("assets/world_ui/char_select.png");

    brandySprite = LoadTexture("assets/hero/fsprite2.png");
    brandonSprite = LoadTexture("assets/hero/msprite2.png");

    chosenCharacter = -1;
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
        farmstead.UpdateCompanion();
        farmstead.UpdateCamera(player.GetPosition());
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
        if(chosenCharacter == 0)
            farmstead.Draw(brandySprite, brandyScale, brandonSprite, brandonScale, player);
        else if(chosenCharacter == 1)
            farmstead.Draw(brandonSprite, brandonScale, brandySprite, brandyScale, player);
    }
}

void Game::HandleInput()
{
    if(currentState == FARMSTEAD)
    {
        player.HandleInput();
    }
}
            
