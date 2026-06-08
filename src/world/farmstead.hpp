#pragma once
#include "entities/player.hpp"
#include <raylib.h>

enum TutorialState
{
    TUTORIAL_WASD,
    TUTORIAL_GET_SEED,
    TUTORIAL_PICK_UP_SEED,
    TUTORIAL_STICK,
    TUTORIAL_SWING_STICK,
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
    void UpdateTutorial(Player& player);
    void DrawTutorialUI();

    void UpdatePickups(Player& player);

    bool CanPlayerMove() const;
    bool ShouldDrawTutorialUI() const;
    
    Texture2D coolStickTexture;
    Texture2D seedsTexture;

    float GetMapWidth() const;
    float GetMapHeight() const;

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
    bool seedsPickedUp;

    Rectangle seedContainerArea;
    Rectangle chickumCoopArea;
};
