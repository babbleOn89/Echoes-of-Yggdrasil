#pragma once
#include <raylib.h>

enum GameState
{
    INTRO_ROOM,
    CHARACTER_SELECT,
    LOSS_SCENE,
    FARMSTEAD
};

enum IntroState
{
    WALK_IN,
    WALK_TO_TABLE,
    WALK_DOWN,
    DIALOGUE,
    FINISHED
};

class Game
{
    public:
        Game();
        ~Game();

        void Update();
        void Draw();
        void HandleInput();

        //Player player;

    private:
        int selectedCharacter;
        int chosenCharacter;
        int dialogueIndex;

        GameState currentState;
        IntroState introState;

        Texture2D brandySprite;
        Texture2D brandonSprite;

        Texture2D introRoom;
        Texture2D characterSelect;
        
        Vector2 brandonPos;
        Vector2 brandonTarget;
        Vector2 brandyPos;
        
        Vector2 playerPos;
        float playerSpeed;
};
