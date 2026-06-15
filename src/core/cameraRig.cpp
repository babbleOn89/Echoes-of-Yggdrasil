#include "core/cameraRig.hpp"
#include <algorithm>

CameraRig::CameraRig()
{
    //start with a blank Camera2D so all fields have safe default values
    camera = {};

    //Keep the player centered on screen by placing teh camera offset
    //at the middle of the window
    camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f
    };

    //initial camera target before the player/world updates it
    camera.target = {700.0f, 500.0f};

    //no camera rotation for now; classic top-down view
    camera.rotation = 0.0f;

    //normal zoom
    camera.zoom = 1.0f;
}

void CameraRig::Update(Vector2 target, float worldWidth, float worldHeight)
{
    //follow the target: player
    camera.target = target;
    
    //since the camera offset is centered, half the screen width/height
    //tells how close the camera can get to the world edges
    float halfW = camera.offset.x;
    float halfH = camera.offset.y;
    
    //clamp the camera target so teh view does not scroll beyond
    //the left/right edges of the world
    camera.target.x = std::max(halfW, std::min(worldWidth - halfW, camera.target.x));
    camera.target.y = std::max(halfH, std::min(worldHeight - halfH, camera.target.y));
}

Camera2D& CameraRig::Get()
{
    //return the camera so Game can use it with BeginMode2D()
    return camera;
}
