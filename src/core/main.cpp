#include <raylib.h>
#include "core/game.hpp"

int main()
{
    //create game window and sets frame rate
    InitWindow(1400, 800, "Echos of Yggdrasil");
    SetTargetFPS(60);
    
    //main game object
    Game game;
    
    //main game loop
    while(!WindowShouldClose())
    {
        //handle player input
        game.HandleInput();

        //update game logic
        game.Update();
        
        //render current frame
        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        EndDrawing();
    }

    //clean up window resources
    CloseWindow();

    return 0;
}
