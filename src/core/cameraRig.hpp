#pragma once
#include <raylib.h>

class CameraRig
{
public:
    CameraRig();

    void Update(Vector2 target, float worldWidth, float worldHeight);
    Camera2D& Get();

private:
    Camera2D camera;
};
