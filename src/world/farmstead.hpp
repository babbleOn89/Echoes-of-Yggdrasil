#pragma once
#include "entities/player.hpp"
#include <raylib.h>

enum TutorialState
{
    TUTORIAL_WASD,
    TUTORIAL_GET_SEED,
    TUTORIAL_PICK_UP_SEED,
    TUTORIAL_OPEN_INVENTORY,
    TUTORIAL_EQUIP_SEED,
    TUTORIAL_CLOSE_INVENTORY,
    TUTORIAL_GO_FEED_CHICKUMS,
    TUTORIAL_FEED_CHICKUMS,
    TUTORIAL_DONE
};

class Farmstead
{
public:
    Farmstead();
    ~Farmstead();

    void UpdateCamera(Vector2 playerPosition);

    void Draw(Texture2D playerSprite,
              float playerScale,
              Texture2D companionSprite,
              float companionScale,
              const Player& player);

    void UpdateCompanion();
    void UpdateTutorial(Player& player, bool inventoryOpen);
    void DrawTutorialUI();

    void UpdatePickups(Player& player);

    bool CanPlayerMove() const;
    bool ShouldDrawTutorialUI() const;
    
    Texture2D coolStickTexture;


private:
    Texture2D background;
    Camera2D camera;

    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;

    Vector2 companionPosition;
    float companionTopY;
    float companionBottomY;
    float companionSpeed;
    int companionDirection;

    TutorialState tutorialState;
    float tutorialTimer;
    bool playerCanMove;

    bool coolStickPickedUp;

    Rectangle seedContainerArea;
    Rectangle chickumCoopArea;
};
