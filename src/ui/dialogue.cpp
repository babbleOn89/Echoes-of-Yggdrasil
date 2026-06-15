#include "ui/dialogue.hpp"

namespace Dialogue
{
    //draw a dialogue box at either the top or bottom of the screen
    void DrawBox(const std::string& text, BoxPosition position)
    {
        //default dialogue box dimensions
        int boxWidth = 700;
        int boxHeight = 150;

        //int leftBoundary = 340;
        //int rightBoundary = GetScreenWidth() - 180;

        int boxX = 430;
        int boxY = GetScreenHeight() - boxHeight - 40;
        
        //move dialogue box to top of the screen when necessary
        if(position == BOX_TOP)
        {
            boxY = 40;
        }

        DrawRectangle(boxX, boxY, boxWidth, boxHeight, BLACK);
        DrawRectangleLines(boxX, boxY, boxWidth, boxHeight, WHITE);

        DrawText(
                text.c_str(),
                boxX + 30,
                boxY + 30,
                24,
                WHITE
                );
    }
    
    //intro cutscene dialogue
    const std::vector<std::string> introLines=
    {
        "Brandy: You know, a real viking probably could have lifted that whole bag of seed.",
        "Brandon: I can lift a bag of seed! Besides, I'm a Viking no matter what, "
            "it's our heritage.",
        "Brandy: Come to think about it, I've only ever seen you fall off of boats.",
        "Parent: You two better get to bed. You have a lot to do in the morning!",
        "Brandon: Rock, paper, scissors for who has to feed the chickens?",
        "Brandy: You're on!"
    };
    
    //tutorial dialogue
    const std::vector<std::string> tutorialLines =
    {
        "Use W A S D to move around.",
        "Go pick up some seed from the container.",
        "Hey look! A really cool stick! \n "
            "You should probably go pick it up",
        "Press Q to pick up the stick",
        "Give it a SWING with SPACEBAR",
        "Okay. Enough Distractions \n"
            "Time to go and feed the chickens.",
        "Press UP ARROW to feed chickens.",
        "BACKAW!!!",
        ":{COMPANION} You forgot to close the gate!"
    };
    
    //sibling lines
    const std::vector<std::string> siblingLines =
    {
        "Don't forget to shut the gate this time!"
    };
}
