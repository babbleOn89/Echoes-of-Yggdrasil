#include "world/intro.hpp"
#include "ui/dialogue.hpp"
#include "stats/character_data.hpp"

IntroScene::IntroScene()
{
    introState = WALK_IN;

    brandonPos = {75.0f, -50.0f};
    brandonTarget = {800.0f, 50.0f};
    brandyPos = {390.0f, 250.0f};

    dialogueIndex = 0;
    selectedCharacter = 0;
    chosenCharacter = -1;
}

void IntroScene::Update()
{
    if(IsKeyPressed(KEY_N))
    {
        introState = CHARACTER_SELECT;
    }

    if(introState == WALK_IN)
    {
        if(brandonPos.y < 50)
            brandonPos.y += 2.0f;
        else
            introState = WALK_TO_TABLE;
    }
    else if(introState == WALK_TO_TABLE)
    {
        if(brandonPos.x < brandonTarget.x)
            brandonPos.x += 2.0f;
        else
            introState = WALK_DOWN;
    }
    else if(introState == WALK_DOWN)
    {
        if(brandonPos.y < 200)
            brandonPos.y += 2.0f;
        else
            introState = INTRO_DIALOGUE;
    }
    else if(introState == INTRO_DIALOGUE)
    {
        if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
        {
            dialogueIndex++;

            if(dialogueIndex >= (int)Dialogue::introLines.size())
            {
                introState = CHARACTER_SELECT;
            }
        }
    }
    else if(introState == CHARACTER_SELECT)
    {
        if(IsKeyPressed(KEY_LEFT))
            selectedCharacter = 0;

        if(IsKeyPressed(KEY_RIGHT))
            selectedCharacter = 1;

        if(IsKeyPressed(KEY_ENTER))
        {
            chosenCharacter = selectedCharacter;
            introState = LOSS_SCENE;
        }
    }
    else if(introState == LOSS_SCENE)
    {
        if(IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
        {
            introState = INTRO_DONE;
        }
    }
}

void IntroScene::Draw(Texture2D introRoom,
                      Texture2D characterSelect,
                      Texture2D brandySprite,
                      Texture2D brandonSprite)
{

    if(introState == WALK_IN ||
       introState == WALK_TO_TABLE ||
       introState == WALK_DOWN ||
       introState == INTRO_DIALOGUE)
    {
        DrawTexturePro(
            introRoom,
            Rectangle{0, 0, (float)introRoom.width, (float)introRoom.height},
            Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            Vector2{0, 0},
            0.0f,
            WHITE
        );

        DrawTextureEx(brandySprite, brandyPos, 0.0f, brandyScale, WHITE);
        DrawTextureEx(brandonSprite, brandonPos, 0.0f, brandonScale, WHITE);

        if(introState == INTRO_DIALOGUE)
        {
            DrawRectangle(100, 600, 1200, 150, BLACK);
            DrawRectangleLines(100, 600, 1200, 150, WHITE);

            DrawText(Dialogue::introLines[dialogueIndex].c_str(), 130, 630, 22, WHITE);
        }
    }
    else if(introState == CHARACTER_SELECT)
    {
        DrawTexturePro(
            characterSelect,
            Rectangle{0, 0, (float)characterSelect.width, (float)characterSelect.height},
            Rectangle{0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            Vector2{0, 0},
            0.0f,
            WHITE
        );

        if(selectedCharacter == 0)
            DrawRectangleLines(150, 600, 250, 150, BLUE);

        if(selectedCharacter == 1)
            DrawRectangleLines(1000, 600, 250, 150, RED);
    }
    else if(introState == LOSS_SCENE)
    {
        DrawRectangle(100, 600, 1200, 150, BLACK);
        DrawRectangleLines(100, 600, 1200, 150, WHITE);

        if(chosenCharacter == 0)
            DrawText("Brandy: aw man! \n\n"
                    "\nBrandon: And you better remember to close the gate this time!",
                    130,
                    630,
                    22,
                    WHITE
                    );
        else if(chosenCharacter == 1)
            DrawText("Brandon: aw man! \n\n"
                    "\nBrandy: And you better remember to close the gate this time!",
                     130,
                     630,
                     22,
                     WHITE
                     );
    }
}

bool IntroScene::IsFinished() const
{
    return introState == INTRO_DONE;
}

int IntroScene::GetChosenCharacter() const
{
    return chosenCharacter;
}
