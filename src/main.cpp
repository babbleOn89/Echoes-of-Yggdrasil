#include <raylib.h>
#include "game.hpp"

int main()
{
    InitWindow(1400, 800, "Echos of Yggdrasil");
    SetTargetFPS(60);

    Game game;

    while(!WindowShouldClose())
    {
        game.Update();
        game.HandleInput();

        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
