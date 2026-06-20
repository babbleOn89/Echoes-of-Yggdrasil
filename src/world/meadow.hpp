#pragma once
#include "world/world.hpp"
#include "entities/enemies.hpp"

//progression states for the tutorial boss encounter
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

//tutorial boss arena

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
    //controls progression through the boss tutorial sequence
    BossRoomState bossRoomState;
    
    Texture2D background;
    
    //tutorial boss instance
    FoxBoss fox;
    
    //world scaling
    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;

    float bossRoomTimer;

    void UpdateFoxEncounter(Player& player, Vector2 playerPos);
    void UpdateFoxFight(Player& player, Vector2 playerPos);
    void UpdateMagicAwakened(Player& player);
    void UpdateByeFox();
    void UpdateCompanionArrives(Player& player);
    void UpdateHiHermes();
    void UpdateSomeExplaining();
    void UpdateBossRoomEnd();
};

