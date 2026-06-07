#include <raylib.h>
#include "core/game.hpp"

int main()
{
    InitWindow(1400, 800, "Echos of Yggdrasil");
    SetTargetFPS(60);

    Game game;

    while(!WindowShouldClose())
    {
        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
