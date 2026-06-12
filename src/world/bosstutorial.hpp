#pragma once
#include "world/world.hpp"

enum BossRoomState
{
    FOX_ENCOUNTER,
    FOX_FIGHT,
    MAGIC_AWAKENED,
    BYE_FOX,
    COMPANION_ARRIVES,
    HI_HERMES,
    SOME_EXPLAINING,
    BOSSROOM_END
};

class Meadow : public World
{
public:
    Meadow();
    ~Meadow();

    void Update(Player& player) override;

    void Draw(Texture2D playerSprite,
            float playerScale,
            Texture2D companionSprite,
            float companionScale,
            const Player& player) override;

private:
    BossRoomState bossRoomState;

    Texture2D background;

    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;
};
