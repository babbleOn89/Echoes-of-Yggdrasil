#pragma once
#include <string>

//playable character optionss
enum CharacterType
{
    BRANDON,
    BRANDY
};

//character-specific data used throughout the game
struct CharacterData
{
    CharacterType type;

    //display name shown in dialogue and UI
    std::string name;

    //sprite draw scale
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
