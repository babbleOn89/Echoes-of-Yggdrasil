#pragma once
#include <raylib.h>

namespace Controls
{
    bool Up();
    bool Down();
    bool Left();
    bool Right();

    bool MeleePressed();
    bool InventoryPressed();
    bool PausePressed();
    bool MinimapPressed();
    bool InteractPressed();

    bool SpellUpPressed();
    bool SpellDownPressed();
    bool SpellLeftPressed();
    bool SpellRightPressed();
}
