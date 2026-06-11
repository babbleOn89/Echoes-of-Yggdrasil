#pragma once
#include "ui/inventory.hpp"
#include "ui/hud.hpp"
#include "entities/player.hpp"
#include "world/farmstead.hpp"
#include "world/intro.hpp"
#include "core/cameraRig.hpp"
#include <raylib.h>

enum GameState
{
    INTRO_ROOM,
    FARMSTEAD
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

    private:
        int chosenCharacter;
        
        Player player;
        Farmstead farmstead;
        IntroScene introScene;

        GameState currentState;

        Texture2D brandySprite;
        Texture2D brandonSprite;

        Texture2D introRoom;
        Texture2D characterSelect;  
};
