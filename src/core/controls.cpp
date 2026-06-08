#include "core/controls.hpp"

namespace Controls
{
    bool Up()                { return IsKeyDown(KEY_W); }
    bool Down()              { return IsKeyDown(KEY_S); }
    bool Left()              { return IsKeyDown(KEY_A); }
    bool Right()             { return IsKeyDown(KEY_D); }

    bool MeleePressed()      { return IsKeyPressed(KEY_SPACE); }
    bool InventoryPressed()  { return IsKeyPressed(KEY_E); }
    bool PausePressed()      { return IsKeyPressed(KEY_P); }
    bool MinimapPressed()    { return IsKeyPressed(KEY_TAB); }
    bool InteractPressed()   { return IsKeyPressed(KEY_Q); }

    bool SpellUpPressed()    { return IsKeyPressed(KEY_UP); }
    bool SpellDownPressed()  { return IsKeyPressed(KEY_DOWN); }
    bool SpellLeftPressed()  { return IsKeyPressed(KEY_LEFT); }
    bool SpellRightPressed() { return IsKeyPressed(KEY_RIGHT); }
}
