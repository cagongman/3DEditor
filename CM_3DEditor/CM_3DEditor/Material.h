#pragma once
#include <QOpenGLShaderProgram>
#include <QString>

class Material {
public:
    Material(const QString& vertexPath, const QString& fragmentPath);
    ~Material();
    void apply();
private:
    QOpenGLShaderProgram program_;
};