#pragma once
#include "world/world.hpp"
#include <raylib.h>

//tutorial steps for the farmstead intro sequence
//order matters: enum values are used as dialogue line indexes
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

//farmstead world area
//handles background drawing, companion movement, pickups,
//and the first tutorial sequence
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
    //internal farmstead systems
    void UpdateCompanion();
    void UpdateTutorial(Player& player);
    void UpdatePickups(Player& player);

    //world visuals
    Texture2D background;
    Texture2D coolStickTexture;
    Texture2D seedsTexture;
    
    //world dimensions
    float scaleX;
    float scaleY;
    float mapWidth;
    float mapHeight;

    //companion patrol data
    Vector2 companionPosition;
    float companionTopY;
    float companionBottomY;
    float companionSpeed;
    int companionDirection;
    
    //tutorial state tracking
    TutorialState tutorialState;
    float tutorialTimer;
    bool playerCanMove;
    
    //pickup state
    bool coolStickPickedUp;
    bool seedsPickedUp;
    
    //interaction zones
    Rectangle seedContainerArea;
    Rectangle chickumCoopArea;
};
