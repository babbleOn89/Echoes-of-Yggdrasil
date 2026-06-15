#pragma once
#include <raylib.h>

//handles camera setup, tacking, and world boundary clamping
class CameraRig
{
public:
    CameraRig();
    
    //update camera position and keep it inside world bounds.
    void Update(Vector2 target, float worldWidth, float worldHeight);

    //access the camera for BeginMode2D()
    Camera2D& Get();

private:
    Camera2D camera;
};
