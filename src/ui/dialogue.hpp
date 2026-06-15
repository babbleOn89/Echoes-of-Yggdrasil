#pragma once
#include <string>
#include <vector>
#include <raylib.h>

namespace Dialogue
{
    //intro cutscene dialogue
    extern const std::vector<std::string> introLines;
    
    //farmstead tutorial dialogue
    extern const std::vector<std::string> tutorialLines;
    
    //sibling-specific dialogue
    extern const std::vector<std::string> siblingLines;
    
    //screen positioning for dialogue boxes
    enum BoxPosition
    {
        BOX_BOTTOM,
        BOX_TOP
    };
    
    //draw a dialogue box containing teh supplied text
    void DrawBox(const std::string& text, BoxPosition = BOX_BOTTOM);
}
