#pragma once
#include "entities/player.hpp"
#include <raylib.h>

//base class for all game world areas.
//every world must be able to update and draw itself
class World
{
public:
    //virtual destructor ensures derived worlds clean up correctly
    virtual ~World() = default;
    
    //update world logic each frame
    virtual void Update(Player& player) = 0;
    
    //draw the world, player, and companion
    virtual void Draw(Texture2D playerSprite,
                      float playerScale,
                      Texture2D companionSprite,
                      float companionScale,
                      const Player& player) = 0;
};
