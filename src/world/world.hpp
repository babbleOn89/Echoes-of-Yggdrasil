#pragma once
#include "entities/player.hpp"
#include <raylib.h>

class World
{
public:
    virtual ~World() = default;

    virtual void Update(Player& player) = 0;

    virtual void Draw(Texture2D playerSprite,
                      float playerScale,
                      Texture2D companionSprite,
                      float companionScale,
                      const Player& player) = 0;
};
