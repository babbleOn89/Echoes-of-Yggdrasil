#pragma once
#include <string>
#include <vector>
#include <raylib.h>

namespace Dialogue
{
    extern const std::vector<std::string> introLines;

    extern const std::vector<std::string> tutorialLines;

    extern const std::vector<std::string> siblingLines;

    void DrawBox(const std::string& text);
}
