#pragma once
#include "ui/inventory.hpp"
#include "ui/hud.hpp"
#include "entities/player.hpp"
#include "world/intro.hpp"
#include "world/farmstead.hpp"
#include "world/bosstutorial.hpp"
#include "core/cameraRig.hpp"
#include "stats/character_data.hpp"
#include <raylib.h>

enum GameState
{
    INTRO_ROOM,
    FARMSTEAD,
    BOSS_TUTORIAL
};

class Game
{
    public:
        Game();
        ~Game();

        void Update();
        void Draw();
        void HandleInput();

        Inventory inventory;
        CameraRig camera;
        HUD hud;

        std::string GetPlayerName() const;
        std::string GetCompanionName() const;

    private:
        int chosenCharacter;
        
        Player player;
        IntroScene introScene;
        Farmstead farmstead;
        Meadow meadow;

        GameState currentState;

        Texture2D brandySprite;
        Texture2D brandonSprite;

        Texture2D introRoom;
        Texture2D characterSelect;  
};
