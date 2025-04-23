#include "Camera.h"

Camera::Camera() 
{

}

void Camera::setViewport(int width, int height) 
{
    m_projection.setToIdentity();
    m_projection.perspective(45.0f, float(width) / height, 0.1f, 100.0f);
}

const QMatrix4x4& Camera::viewMatrix() const 
{
    return m_view;
}

const QMatrix4x4& Camera::projectionMatrix() const 
{
    return m_projection;
}