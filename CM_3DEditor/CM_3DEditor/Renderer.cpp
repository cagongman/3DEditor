#include "Renderer.h"
#include "Object.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>

Renderer::Renderer() {}

void Renderer::init() {
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
    f->glEnable(GL_DEPTH_TEST);
}

void Renderer::render(Scene* scene, Camera* camera) {
    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (const auto& obj : scene->objects()) {
        obj->draw();
    }
}