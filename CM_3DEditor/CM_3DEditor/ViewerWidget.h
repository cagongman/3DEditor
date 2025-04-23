#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Camera;
class Scene;
class Renderer;

class ViewerWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	ViewerWidget(QWidget *parent);
	~ViewerWidget();

    Scene* GetScene();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Camera* m_camera;
    Scene* m_scene;
    Renderer* m_renderer;
};
