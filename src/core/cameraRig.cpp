#include "core/cameraRig.hpp"
#include <algorithm>

CameraRig::CameraRig()
{
    camera = {};
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };
    camera.target = {700.0f, 500.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void CameraRig::Update(Vector2 target, float worldWidth, float worldHeight)
{
    camera.target = target;

    float halfW = camera.offset.x;
    float halfH = camera.offset.y;

    camera.target.x = std::max(halfW, std::min(worldWidth - halfW, camera.target.x));
    camera.target.y = std::max(halfH, std::min(worldHeight - halfH, camera.target.y));
}

Camera2D& CameraRig::Get()
{
    return camera;
}
