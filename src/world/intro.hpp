#pragma once
#include <raylib.h>

enum IntroState
{
    WALK_IN,
    WALK_TO_TABLE,
    WALK_DOWN,
    INTRO_DIALOGUE,
    CHARACTER_SELECT,
    LOSS_SCENE,
    INTRO_DONE
};

class IntroScene
{
public:
    IntroScene();

    void Update();
    void Draw(Texture2D introRoom,
              Texture2D characterSelect,
              Texture2D brandySprite,
              Texture2D brandonSprite);

    bool IsFinished() const;
    int GetChosenCharacter() const;

private:
    IntroState introState;

    Vector2 brandonPos;
    Vector2 brandonTarget;
    Vector2 brandyPos;

    int dialogueIndex;
    int selectedCharacter;
    int chosenCharacter;
};
