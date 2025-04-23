#pragma once
#include "Scene.h"
#include "Camera.h"

class Renderer {
public:
    Renderer();
    void init();
    void render(Scene* scene, Camera* camera);
};