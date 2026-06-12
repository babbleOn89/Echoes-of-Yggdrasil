#pragma once
#include <string>

enum CharacterType
{
    BRANDON,
    BRANDY
};

struct CharacterData
{
    CharacterType type;
    std::string name;
    float scale;
};

const CharacterData BRANDON_DATA =
{
    BRANDON,
    "Brandon",
    0.20f
};

const CharacterData BRANDY_DATA =
{
    BRANDY,
    "Brandy",
    0.16f
};

const float brandonScale = BRANDON_DATA.scale;
const float brandyScale = BRANDY_DATA.scale;
