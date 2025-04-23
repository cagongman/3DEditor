#include "viewerwidget.h"
#include "camera.h"
#include "scene.h"
#include "renderer.h"

ViewerWidget::ViewerWidget(QWidget* parent)
    : QOpenGLWidget(parent),
    m_camera(new Camera()),
    m_scene(new Scene()),
    m_renderer(new Renderer()) 
{

}

ViewerWidget::~ViewerWidget()
{

}

void ViewerWidget::initializeGL() 
{
    initializeOpenGLFunctions();
    m_renderer->init();
}

void ViewerWidget::resizeGL(int w, int h) 
{
    m_camera->setViewport(w, h);
}

void ViewerWidget::paintGL() 
{
    m_renderer->render(m_scene, m_camera);
}

Scene* ViewerWidget::GetScene()
{
    return m_scene;
}