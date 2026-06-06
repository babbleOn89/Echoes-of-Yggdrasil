#pragma once
#include "inventory.hpp"
#include "player.hpp"
#include "farmstead.hpp"
#include "intro.hpp"
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
