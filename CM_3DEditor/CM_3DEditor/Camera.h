#pragma once

#include <QMatrix4x4>

class Camera
{
public:
    Camera();
    void setViewport(int width, int height);
    const QMatrix4x4& viewMatrix() const;
    const QMatrix4x4& projectionMatrix() const;

private:
    QMatrix4x4 m_view;
    QMatrix4x4 m_projection;
};

