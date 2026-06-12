#pragma once
#include "world/world.hpp"
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
    TUTORIAL_CHICKUM_PANIC,
    TUTORIAL_GO_NORTH,
    TUTORIAL_DONE
};

class Farmstead : public World
{
public:
    Farmstead();
    ~Farmstead();

    void Update(Player& player) override;

    void Draw(Texture2D playerSprite,
              float playerScale,
              Texture2D companionSprite,
              float companionScale,
              const Player& player) override;

    void DrawTutorialUI();

    bool CanPlayerMove() const;
    bool ShouldDrawTutorialUI() const;

    float GetMapWidth() const;
    float GetMapHeight() const;

private:
    void UpdateCompanion();
    void UpdateTutorial(Player& player);
    void UpdatePickups(Player& player);

private:
    Texture2D background;

    Texture2D coolStickTexture;
    Texture2D seedsTexture;

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
