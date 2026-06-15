#pragma once
#include "ui/inventory.hpp"
#include "ui/hud.hpp"
#include "entities/player.hpp"
#include "world/intro.hpp"
#include "world/farmstead.hpp"
#include "world/meadow.hpp"
#include "core/cameraRig.hpp"
#include "stats/character_data.hpp"
#include <raylib.h>

enum GameState
{
    INTRO_ROOM,
    FARMSTEAD,
    BOSS_TUTORIAL
};

//Main game controller
//responsible for:
// - State transitions
// - Input routing
// - World updates
// - Rendering
// - Shared systems (HUD, camera, inventory)

class Game
{
    public:
        Game();
        ~Game();
        
        //update active game state
        void Update();

        //draw active game state and ui
        void Draw();

        //route player input to the active state
        void HandleInput();

        Inventory inventory;
        CameraRig camera;
        HUD hud;
        
        //returns teh selected character's name
        std::string GetPlayerName() const;

        //returns the non-selected sibling's name
        std::string GetCompanionName() const;

    private:
        // 0 = Brandy
        // 1 = Brandon
        int chosenCharacter;
        
        Player player;

        //world scenes
        IntroScene introScene;
        Farmstead farmstead;
        Meadow meadow;

        GameState currentState;
        
        //character sprites
        Texture2D brandySprite;
        Texture2D brandonSprite;
        
        //background and ui textures
        Texture2D introRoom;
        Texture2D characterSelect;  
};
